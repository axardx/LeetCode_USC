
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = -1;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( start == -1 && nums[i] == 0 )
                start = i;
            if ( start >= 0 && nums[i] != 0 ) {
                nums[start] = nums[i];
                nums[i] = 0;
                start++;
            }
            
        }
    }
};