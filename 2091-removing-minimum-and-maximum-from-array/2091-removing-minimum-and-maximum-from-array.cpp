class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int option1 = max(minIndex, maxIndex) + 1;

        
        int option2 = n - min(minIndex, maxIndex);

       
        int option3 = minIndex + 1 + n - maxIndex;


        int option4 = maxIndex + 1 + n - minIndex;

        return min({option1, option2, option3, option4});
    }
};