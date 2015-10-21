class Solution {
public:
    string convert(string s, int numRows) {
        
        string ans;
        vector<vector<char>> tmp(numRows);
        int i = 0;
        bool forward = true;
        
        for ( int j = 0; j < s.size(); j++ ) {
            if ( forward || i == 0 ) {
                
                forward = true;
                tmp[i].push_back(s[j]);
                i++;
                if ( i == numRows ) {
                    forward = false;
                    i > 1? i= numRows -2: i = 0;
                }
            }
            else if ( !forward) {
                tmp[i].push_back(s[j]);
                i--;
            }
        }
        
        for (vector<char>& row : tmp) {
            for (char& value : row) {
                ans.push_back(value);
            }
        }
        
        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// refer to discussion of LeetCode
// https://leetcode.com/discuss/51476/lines-space-accepted-solution-with-detailed-explantation


string convert(string s, int nRows) {
    if(nRows <= 1) return s;
    string result = "";
    //the size of a cycle(period)
    int cycle = 2 * nRows - 2;
    for(int i = 0; i < nRows; ++i)
    {
        for(int j = i; j < s.length(); j = j + cycle){
            result = result + s[j];
            int secondJ = (j - i) + cycle - i;
            if(i != 0 && i != nRows-1 && secondJ < s.length())
                result = result + s[secondJ];
        }
    }
    return result;
}