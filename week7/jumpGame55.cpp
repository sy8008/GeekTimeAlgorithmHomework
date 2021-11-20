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
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return true;
        }
        vector<int> reachIdx (n + 1, 0); // readchIdx[i] 表示在索引i处的最远可达索引
        reachIdx[0] = nums[0];
        int last_max_reach_idx = 0;
        for (int i = 1; i < n; ++i){
            if ( i <= reachIdx[i - 1]){ // 如果当前索引是能够到达的，再进行更新
                reachIdx[i] = max(i + nums[i],reachIdx[i - 1]);
            }
        }

        int max_reach_idx = *max_element(reachIdx.begin(),reachIdx.end());
        return max_reach_idx >= n - 1;
    }
};



int main(){
    Solution my_solution;
    vector<int> input ={1,2};
    cout << my_solution.canJump(input) << endl;
   




    return 0 ;

}