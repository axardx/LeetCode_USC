// refer to https://en.wikipedia.org/wiki/H-index
//

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        if ( citations.empty() )
            return 0;
        
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        
        int max = 0;
        int i = 0;
        for ( vector<int>::iterator it = citations.begin(); it != citations.end(); it++ ) {
            if ( min(i+1, *it) > max )
                max = min(i+1, *it);
            i++;
        }
        
        return max;
    }
};