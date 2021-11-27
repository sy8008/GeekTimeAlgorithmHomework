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
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // visited = vector<vector<bool>>(m,vector<bool>(n,false));
        int outsideIdx = m*n; // 用来标识
        fa = vector<int>(m * n,0);

        // 初始化各个集合的father
        for (int i = 0; i < m * n; i++){
            fa[i] = i;
        }


        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                for (int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n){continue;}
                    if (grid[i][j] == '0' && grid[nx][ny] == '0'
                      ||grid[i][j] == '1' && grid[nx][ny] == '1'){
                        unionSet(pos2idx(i,j),pos2idx(nx,ny));
                    }  
                }

            }
        }

        int ans = 0;
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == '1' && find(pos2idx(i,j)) == pos2idx(i,j)){
                    ans ++;
                } 
            }
        }

        vector<int> tempfa = fa;
        return ans;

    }

    // 将矩阵索引转化为1维索引
    int pos2idx(int i, int j){
        return n * i + j;
    }


    int find(int x){
        if (x == fa[x]){return x;}
        return fa[x] = find(fa[x]);
    }

    void unionSet(int x, int y){
        x = find(x);
        y = find(y);
        if (x != y){
            fa[x] = y;
        }
    }


    int m;
    int n;
    vector<int> fa;
    // vector<vector<bool>> visited;
    
    // 方向数组：上下左右
    const int dx[4] = {-1,1,0,0};
    const int dy[4] = {0,0,-1,1};

};


int main(){
    Solution my_solution;
    vector<vector<char>> input ={{'1'}, {'1'}};
    cout << my_solution.numIslands(input) << endl;
 
   




    return 0 ;

}