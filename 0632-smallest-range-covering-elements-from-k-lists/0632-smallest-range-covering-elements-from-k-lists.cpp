class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        // {value, list_index, element_index}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > minHeap;

        int currentMax = INT_MIN;

        // Put first element of every list into heap
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int rangeStart = 0;
        int rangeEnd = INT_MAX;

        while (true) {

            // Get minimum element
            auto current = minHeap.top();
            minHeap.pop();

            int currentMin = current[0];
            int listIndex = current[1];
            int elementIndex = current[2];

            // Update smallest range
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }

            // If this list has no more elements,
            // we cannot form a range containing all K lists
            if (elementIndex + 1 == nums[listIndex].size()) {
                break;
            }

            // Add next element from the same list
            int nextValue = nums[listIndex][elementIndex + 1];

            minHeap.push({
                nextValue,
                listIndex,
                elementIndex + 1
            });

            // Update maximum
            currentMax = max(currentMax, nextValue);
        }

        return {rangeStart, rangeEnd};
    }
};