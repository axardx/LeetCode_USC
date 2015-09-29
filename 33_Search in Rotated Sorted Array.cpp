
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size()-1;
        int m = 0;
        int pre = -1, post = -1;
        
        if ( nums.size() == 1 )
            return nums[0] == target ? 0 : -1;
        
        while ( l < r) {
            m = (l+r) >> 1;
            if ( nums[m] > nums[r] )
                l = m+1;
            else
                r = m;
        }
        
        if ( r != 0)
            pre = binary_search( nums, target, 0, r-1 );
        post = binary_search( nums, target, r, nums.size()-1 );
        
        return pre >= post? pre : post;
        
    }
    
    int binary_search( vector<int>& nums, int target, int l, int r ) {
        
        int m = 0;
        
        while ( l <= r ) {
            m = (l+r) >> 1;
            if ( nums[m] == target )
                return m;
            else if ( nums[m] > target )
                r = m-1;
            else
                l = m+1;
        }
        return -1;
    }
};