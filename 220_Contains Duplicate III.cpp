// refer to discussion of LeetCode
// multimap would automatically sort by first key
// multimap allows one key corresponding multiple second key

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        multimap<long, int> hash;
        
        for ( int i = 0; i < nums.size(); i++ )
            hash.insert(make_pair(nums[i], i));
        
        multimap<long, int>::iterator p1 = hash.begin();
        while ( p1 != hash.end() ) {
            multimap<long, int>::iterator p2 = p1;
            p2++;
            while ( p2 != hash.end() && abs(p2->first - p1->first) <= t ) {
                if ( abs(p2->second - p1->second) <= k )
                    return true;
                p2++;
            }
            p1++;
        }
        return false;
    }
};