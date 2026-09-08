class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

       
        if (n >= 1000) {
            ans += n - 999;
        }

        return ans;
    }
};