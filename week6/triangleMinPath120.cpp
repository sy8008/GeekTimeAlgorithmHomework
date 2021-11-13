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
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> minSum; // 存储从第i第j个元素到最底层的最小和
        int INF = 1e8;
        
        //初始化状态数组,最底下一行赋值为原数组对应元素
        for (int i = 0; i <triangle.size(); ++i){
            vector<int> row;
            for (int j = 0; j <triangle[i].size(); ++j){
                if (i != triangle.size() - 1){
                    row.push_back(INF);
                }
                else{
                    row.push_back(triangle[i][j]);
                }
                
            }
            minSum.push_back(row);
        }
        
        // 自底向上递推状态
        if (triangle.size() == 1) {return *min_element(triangle[0].begin(),triangle[0].end());}
        
        for (int i = triangle.size() - 2; i >= 0; --i){
            for (int j = 0; j < triangle[i].size(); ++j){
                minSum[i][j] = triangle[i][j] + min(minSum[i+1][j],minSum[i+1][j+1]);
                cout << "i: " << i << " j: " << j <<" minsum: " << minSum[i][j] << endl;
            }
        }

        return minSum[0][0];



    }
};
int main(){
    Solution my_solution;
    // vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    vector<vector<int>> triangle = {{-10}};
    cout <<my_solution.minimumTotal(triangle) << endl;




    return 0 ;

}