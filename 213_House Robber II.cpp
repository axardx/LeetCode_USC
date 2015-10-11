
class Solution {
public:
    int rob(vector<int>& nums) {
        
        if ( nums.size() == 0 )
            return 0;
        else if ( nums.size() == 1 )
            return nums[0];
        
        vector<int> dp2(nums.size(), 0);
        int n = nums.size();
        int ans_0 = 0, ans_n = 0;
        
        // either start from 0 -> n-2
        dp2[1] = nums[0];
        for ( int i = 1; i < n-1; i++ )
            dp2[i+1] = max( dp2[i], dp2[i-1]+nums[i] );
        ans_0 = dp2[n-1];
        
        // or start from 1 -> n-1
        dp2[0] = 0;
        dp2[1] = nums[1];
        for ( int i = 1; i < n-1; i++ )
            dp2[i+1] = max( dp2[i], dp2[i-1]+nums[i+1] );
        ans_n = dp2[n-1];
        
        return ans_0 >= ans_n ? ans_0 : ans_n;
        
    }
};