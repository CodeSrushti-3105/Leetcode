class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min-heap (smallest number at the top)
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Loop through all numbers
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]);  // Add number to heap

            // If heap size is more than k, remove the smallest
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The top element is the kth largest
        return minHeap.top();
    }
};
