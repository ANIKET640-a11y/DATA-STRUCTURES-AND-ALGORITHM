class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Store index of each litter cell
        vector<vector<int>> litter(m, vector<int>(n, -1));

        int sr = 0, sc = 0;
        int cnt = 0;

        // Find starting position and number/index of litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter[i][j] = cnt++;
                }
            }
        }

        // No litter
        if (cnt == 0)
            return 0;

        // All litter collected
        int fullMask = (1 << cnt) - 1;

        /*
            State:
            row, col, remaining energy, collected mask
        */

        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, 0});

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                // Can't move if energy is 0
                if (currEnergy == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Boundary check
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Moving costs 1 energy
                    int newEnergy = currEnergy - 1;

                    // Reset cell
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Update litter mask
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int id = litter[nr][nc];

                        newMask |= (1 << id);
                    }

                    // If this state hasn't been visited
                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};