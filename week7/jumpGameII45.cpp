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

    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> numJump (n,1e9); // numJump[i] 表示到达位置i处的最少跳跃次数
        numJump[0] = 0;
        int tempMin = 1e9;
        for (int i = 1; i < n; ++i){
            tempMin = 1e9;
            for (int j = 0; j <i; ++j){
                if (j + nums[j] >= i){ // 如果位置i可达
                    tempMin = min(tempMin,numJump[j]);
                }
            }
            if (tempMin != 1e9){
                numJump[i] = tempMin + 1;
            }
        }


        return numJump[n-1];

    }

};



int main(){
    Solution my_solution;
    vector<int> input ={2,3,1,1,4};
    cout << my_solution.jump(input) << endl;
   
   




    return 0 ;

}