class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = 0, j = 0;
        
        nums1.erase(nums1.begin()+m, nums1.end());
        nums2.erase(nums2.begin()+n, nums2.end());
        
        while ( m || n ) {
            if ( n == 0 )
                break;
            
            else if ( m == 0 ) {
                nums1.push_back(nums2[j++]);
                n--;
            }
            
            else {
                if ( nums2[j] < nums1[i] ) {
                    nums1.insert(nums1.begin()+i, nums2[j++]);
                    i++;
                    n--;
                }
                else {
                    i++;
                    m--;
                }
            } // else
        } // while
    }
};