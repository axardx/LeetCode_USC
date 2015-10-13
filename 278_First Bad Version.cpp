
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int left = 1, right = n;
        
        while (left < right) {
            
            // if using mid = (left+right)/2 would overflow!
            int mid = left + (right - left) / 2;
            
            if ( isBadVersion(mid) )
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};