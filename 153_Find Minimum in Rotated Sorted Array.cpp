
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if ( nums.size() == 1 )
            return nums[0];
        
        int min = nums[0];
        int i = 0, j = nums.size()-1;
        while ( 1 ) {
            if ( nums[i] > nums[i+1] )
                return nums[i+1];
            else if ( nums[j] < nums[j-1] )
                return nums[j];
            else if ( nums[i] < nums[j] )
                return nums[i];
            i++;
            j--;
        }
    }
};



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Refer to Discussion on LeetCode
// Solve by binary Search


public int FindMin(int[] nums) {
    int left = 0, right = nums.Length - 1, mid = 0;
    while(left < right){
        mid = (left + right) >> 1;
        if(nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }
    return nums[right];
}