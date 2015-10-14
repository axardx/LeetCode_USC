// refer to discussion of Leetcode

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> table;
        vector<int> ans;
        
        for ( int i = 0; i < nums.size(); i++ ) {
            
            if ( table.count(target-nums[i]) ) {
                ans.push_back( table[target-nums[i]]+1 );
                ans.push_back( i+1 );
                return ans;
            }
            table[nums[i]] = i;
        }
        
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// if the array is sorted and just find the numbers

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size(), l = 0, r = n - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target)
                return {l + 1, r + 1};
            if (numbers[l] + numbers[r] > target) r--;
            else l++;
        }
    }
};