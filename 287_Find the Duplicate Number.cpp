// refer to discussion on LeetCode
// https://leetcode.com/discuss/60830/solutions-explanation-space-without-changing-input-array
// O(nlogn)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n-1;
        
        while ( left < right) {
            int mid = (left + right) >> 1;
            int i = 0, count = 0;
            while ( i < n )
                count += nums[i++] <= mid ? 1 : 0;
            if ( count > mid )
                right = mid;
            else
                left = mid+1;
        }
        return left;
        
    }
};