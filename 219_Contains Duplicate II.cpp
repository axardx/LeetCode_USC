
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,int> hash;
        int min = INT_MAX;
        
        for ( int i = 0; i < nums.size(); i++ ) {
            
            if ( hash.count(nums[i]) ) {
                if ( i - hash[nums[i]] < min ) {
                    min = i - hash[nums[i]];
                    if ( min <= k)
                        return true;
                }
                hash[nums[i]] = i;
            }
            else
                hash[nums[i]] = i;
        }
        return false;
    }
};