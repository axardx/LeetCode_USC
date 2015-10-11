
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if ( log2(n) - (int)log2(n) != 0.0 )
            return false;
        return true;
    }
};