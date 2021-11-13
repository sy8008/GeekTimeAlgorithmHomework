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
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> maxLength(nums.size(),1); // 以nums[i] 结尾的最长子序列长度
        vector<int> maxLengthCnt(nums.size(),1); // 以nums[i]结尾的最长子序列长度的个数
        for (int i = 1; i < nums.size(); ++i){
            for (int j = 0;j < i; ++j){
                if (nums[j] < nums[i]){
                    if (maxLength[j] + 1 > maxLength[i]) { // 第一次找到
                        maxLength[i] = maxLength[j] + 1;
                        maxLengthCnt[i] = maxLengthCnt[j];
                    } 
                    else if (maxLength[j] + 1 == maxLength[i]) { // 不是第一次找到
                        maxLengthCnt[i] += maxLengthCnt[j];
                    }

                }
            }
        }

        int max_lis_length = *max_element(maxLength.begin(),maxLength.end()); // lis的长度
        int ans = 0;

        // lis长度对应索引处的个数累加
        for (int i = 0; i < maxLength.size(); ++i){
            if (maxLength[i] == max_lis_length){
                ans += maxLengthCnt[i]; 
            }
        }
        return ans;
        
    }
};

int main(){
    Solution my_solution;
    vector<int> input ={2,2,2,2,2};
    cout << my_solution.findNumberOfLIS(input) << endl;
   




    return 0 ;

}