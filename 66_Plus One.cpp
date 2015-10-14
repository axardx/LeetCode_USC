
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        vector<int> ans;
        
        for ( int i = digits.size()-1; i >= 0; i--) {
            int tmp = 0;
            
            tmp = digits[i] + carry;
            
            if ( tmp == 10 )
                carry = 1;
            else
                carry = 0;
            ans.push_back(tmp%10);
        }
        if ( carry == 1 )
            ans.push_back(1);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};