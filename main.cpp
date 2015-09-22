//
//  main.cpp
//  283_Move_Zeroes
//
//  Created by HsuYu-wei on 2015/9/22.
//  Copyright (c) 2015年 HsuYu-wei. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = -1;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( start == -1 && nums[i] == 0 )
                start = i;
            if ( start >= 0 && nums[i] != 0 ) {
                nums[start] = nums[i];
                nums[i] = 0;
                start++;
            }
            
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
