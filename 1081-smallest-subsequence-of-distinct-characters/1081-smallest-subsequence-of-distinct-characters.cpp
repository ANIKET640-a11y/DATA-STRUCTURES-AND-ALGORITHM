class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        // Store the last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        string st;
        vector<bool> visited(26, false);

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Skip if already present in answer
            if (visited[ch - 'a'])
                continue;

            // Maintain lexicographically smallest order
            while (!st.empty() &&
                   st.back() > ch &&
                   last[st.back() - 'a'] > i) {

                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return st;
    }
};