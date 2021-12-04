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
    string reverseWords(string s) {
        string ans = "";

        int startIdx = s.size() - 1;
        while (startIdx >= 0)
        {
            pair<string,int> next = getNextWord(startIdx,s);
            if (next.first != ""){
                ans += next.first;
                ans += ' ';
                startIdx = next.second;
            }
            else{
                break;
            }
        }
        
        if (ans[ans.size() - 1] == ' '){
            ans.erase(ans.end() - 1); 
        }

        return ans;
        
    }

    // 从结尾开始 获取下一个单词，以及下下个单词的搜索起始索引
    pair<string,int> getNextWord(int startIdx,string &s){
        string ans = "";
        int currIdx = startIdx; 

        //跳过开头的空格
        while (currIdx >= 0 && s[currIdx] == ' '){
            currIdx--;
        }

        int wordEndIdx = currIdx; // 当前单词的最后一个字符的位置
        // 提取单词
        while (currIdx >= 0 && s[currIdx] != ' '){
            currIdx--;
        }

        int wordStartIdx = currIdx + 1;

        for (int i = wordStartIdx; i <= wordEndIdx; i++){
            ans += s[i];
        }

        return make_pair(ans,currIdx);

    }
};


int main(){

    Solution my_solution;
    string input = "  hello world  ";
    cout << my_solution.reverseWords(input) << endl;
    return 0 ;

}