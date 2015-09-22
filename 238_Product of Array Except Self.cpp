/*
    For an array : { 4, 6, 2, 3, 5 }
    Consider the matrix :
                             4  6  2  3  5
                            -------------->
                          *{  , 4, 4, 4, 4 }
                          *{ 6,  , 6, 6, 6 }
                          *{ 2, 2,  , 2, 2 }
                          *{ 3, 3, 3,  , 3 }
                          *{ 5, 5, 5, 5,   }
                            <--------------
    First, we accumulate to calculate the multiply of { 4, 4*6, 4*6*2, 4*6*2*3 } from left to right
    Then, we accumulate to calculate the multiply of { 5, 5*3, 5*3*2, 5*3*2*6 } from right to left 
          and multiply with the result of multiply in the First calculation.
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 1);
        if ( nums.size() < 2 )
            return nums;
        
        for ( int i = 1; i < nums.size(); i++ ) {
            ans[i] = ans[i-1]*nums[i-1];
        }
        
        int tmp = nums[nums.size()-1];
        for ( int j = nums.size()-2; j >= 0; j-- ) {
            ans[j] = tmp*ans[j];
            tmp *= nums[j];
        }
        
        return ans;
    }
};