#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> to; // 出边数组
        vector<int> inDeg; // 入度
        vector<int> ans;

        to =vector<vector<int>>(numCourses,vector<int>());
        inDeg = vector<int>(numCourses,0);
        for (auto p:prerequisites){
          int x = p[0];
          int y = p[1];
          to[y].push_back(x);
          inDeg[x]++;

        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
          if (inDeg[i] == 0){
              q.push(i);
          }
        }
        while(!q.empty()){
          int x = q.front();
          q.pop();
          ans.push_back(x);
          for (int y: to[x]){
            if (inDeg[y] > 0) {inDeg[y]--;}       
            if (inDeg[y] == 0){
                q.push(y);
            }

          }

        }

      

      if (ans.size() == numCourses){ return ans;}
      else { return vector<int>();}
    }
// private:
    // vector<vector<int>> to; // 出边数组
    // vector<int> inDeg; // 入度
    // int n;
    // vector<int> ans;

};




int main(){

    Solution my_solution;
    vector<vector<int>> input = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = my_solution.findOrder(4,input);

    for (auto x : ans){
      cout << x <<endl;
    }


    




    return 0;
}



