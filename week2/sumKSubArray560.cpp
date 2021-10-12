#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<stack>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        vector<int> preSum(n+1,0);
        umap[0]=1;
        for (int i = 1; i <= n; ++i){
            preSum[i] = preSum[i-1] + nums[i-1];
            if (umap.find(preSum[i] - k) != umap.end()){
                cnt += umap[preSum[i] - k];
            }
            umap[preSum[i]] ++ ;    
        }
        return cnt;

    }
private:
    unordered_map<int,int> umap;
};




int main(){
    Solution my_solution;


    vector<int>nums = {1,-1,0};
    int k = 0;
    cout << my_solution.subarraySum(nums,k);


    return 0;
}