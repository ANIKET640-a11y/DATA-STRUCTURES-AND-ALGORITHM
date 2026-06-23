class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int k = r - l + 1;

        vector<long long> up(k), down(k), new_up(k), new_down(k);
        
        for (int v = 0; v < k; v++) {
            up[v]   = v;
            down[v] = k - 1 - v;
        }

        for (int i = 0; i < n - 2; i++) {
            // prefix_down[v] = sum(down[0..v-1])
            long long pd = 0, su = 0;
            
            // compute prefix_down on the fly for new_up
            for (int v = 0; v < k; v++) {
                new_up[v] = pd;
                pd = (pd + down[v]) % MOD;
            }
            
            // compute suffix_up on the fly for new_down
            for (int v = k - 1; v >= 0; v--) {
                new_down[v] = su;
                su = (su + up[v]) % MOD;
            }

            swap(up, new_up);
            swap(down, new_down);
        }

        long long ans = 0;
        for (int v = 0; v < k; v++)
            ans = (ans + up[v] + down[v]) % MOD;

        return (int)ans;
    }
};