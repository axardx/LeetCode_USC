//
//  main.cpp
//  290_Word Pattern
//
//  Created by HsuYu-wei on 2015/10/11.
//  Copyright (c) 2015年 HsuYu-wei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <algorithm>
#include <map>

using namespace std;

bool wordPattern(string pattern, string str) {
    
    string tmp = "";
    string compare;
    bool first = true;
    int count = 0;
    
    map<string, char> buffer;
    
    for ( int i = 0; i <= str.size(); i++ ) {
        
        char c = str[i];

        if ( c == ' ' || i == str.size() ){
            cout << tmp << endl;
            if ( first ) {
                compare += pattern[count];
                buffer[tmp] = pattern[count];
                first = false;

            }
            else {
                if ( buffer.count(tmp) ) {
                    if ( pattern[count] != buffer[tmp] )
                        return false;
                    compare += buffer[tmp];
                }
                else {
                    map<string, char>::const_iterator it = buffer.begin();
                    
                    while ( it != buffer.end() ) {
                        if ( it->second == pattern[count] )
                            return false;
                        ++it;
                    }
                    buffer[tmp] = pattern[count];
                    compare += pattern[count];
                }
            }
            tmp = "";
            count++;
        }
        else
            tmp += str[i];
    }
    cout << compare << endl;
    return compare == pattern;
}

int main(int argc, const char * argv[]) {
    
    string pattern = "adda";
    string str = "cat dog dog cat";
    
    cout << wordPattern(pattern, str) << endl;
    
    return 0;
}
