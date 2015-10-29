// refer to discussion of LeetCode
// https://leetcode.com/discuss/65204/c-binary-search-solution-easy-understand
// https://leetcode.com/discuss/58631/3-4-short-lines-integer-newton-every-language


class Solution {
public:
    int mySqrt(int x) {
        // return (int)exp( log(x)/2 );
        long low = 0, high = x;
        
        while ( low < high ) {
            long mid = low + (high-low)/2;
            
            if ( mid*mid == x )
                return mid;
            else if ( mid*mid > x )
                high = mid-1;
            else
                low = mid+1;
        }
        return low*low > x? low-1 : low;
    }
};