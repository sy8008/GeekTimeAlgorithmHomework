#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      this->n = nums.size();
      this->visited = vector<bool>(n, false);
      permute(nums,0);
      return ans;

    } 

private:
    int n;
    vector<int> permutedArray;
    vector<vector<int>> ans;
    vector<bool> visited;
    unordered_set<string> uset;

    string vec2string(vector<int> & vec){
      string ans = "";
      for (auto x : vec){
        ans += to_string(x);
      }
      return ans;
    }
    void permute(vector<int>& nums, int pos){
        if (pos == n && uset.find(vec2string(permutedArray)) == uset.end()){
          // if (pos == n ){
           ans.push_back(permutedArray);
           uset.insert(vec2string(permutedArray));
           return;

       }
        
        for (int i = 0; i < n; ++ i){
          if (!visited[i]){
              visited[i] = true;
              permutedArray.push_back(nums[i]);
              permute(nums,pos + 1);
              visited[i] = false;
              permutedArray.pop_back();

          }
        }

    }
};




int main(){

    Solution my_solution;
    vector<int> input = {1,1,2};
    vector<vector<int>> ans = my_solution.permuteUnique(input);
    for (auto x:ans){
      for(auto y : x){
        cout << y ;
      }
      cout << endl;
    }

    




    return 0;
}



