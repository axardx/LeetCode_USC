
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (!nums.size())
            return 0;
        
        int count = 1;
        while ( count < nums.size() ) {
            
            if ( nums[count] == nums[count-1] )
                nums.erase(nums.begin()+count);
            else
                count++;
        }
        return count;
        
    }
};