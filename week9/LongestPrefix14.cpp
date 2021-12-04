#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
#include <numeric>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         
         int numStr = strs.size();
         size_t minStrSize = 1e9;
         for (string &str: strs){    
            minStrSize = min(minStrSize,str.size());
         }

         string ans = "";
         for (int i = 0; i < int(minStrSize); ++i){
             char curStr = strs[0][i];
             for (int j = 1; j < numStr; ++j){
                 if (strs[j][i] != curStr){
                     return ans;
                 }
             }
             ans += curStr;
         }
         return ans;
    }
};


int main(){

    
    return 0 ;

}