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
    void solve(vector<vector<char>>& board) {
      m = board.size();
      n = board[0].size();
      visited = vector<vector<bool>>(m, vector<bool>(n,false));
      vector<pair<int,int>> toBeFilled;
      for (int i = 0; i < m ; ++i){
        for (int j = 0; j < n; ++j){
          if (validIdx(i,j) && board[i][j] == 'O' && !visited[i][j] && !inBoarder(i,j)){
              toBeFilled = bfs(board,i,j);
              fillBoard(board,toBeFilled);

          } 
        }
      }

      

    }

    // 填充
    void fillBoard(vector<vector<char>>& board,vector<pair<int,int>>& toBeFilled){
        for (auto p:toBeFilled){
          int x = p.first;
          int y = p.second;
          board[x][y] = 'X';
        }
    }
    // 从 (x,y) 开始进行一次bfs，得到待填充的'O'的位置集合
    vector<pair<int,int>> bfs(vector<vector<char>>& board,int x, int y){
        queue<pair<int,int>> q;
        vector<pair<int,int>> toBeFilled;
        q.push({x,y});
        visited[x][y] = true;
        bool visitedBoarder = false;
        while (!q.empty()){
          // 取队头
          int cx = q.front().first;
          int cy = q.front().second;
          toBeFilled.push_back(q.front());
          q.pop();

          // 拓展队头
          for (int i = 0; i < 4; ++i){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 有效的'O':没有越界、没有在边界上、没有访问过
            if (validIdx(nx,ny) && !inBoarder(nx,ny) && board[nx][ny] == 'O' && !visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny] = true;
                
            }

            // 没有越界、没有访问过，但是在边界上的'O'
            else if (validIdx(nx,ny) && inBoarder(nx,ny) && board[nx][ny] == 'O' && !visited[nx][ny]){
                visitedBoarder = true;
            }
                    
        }
      }

      if (visitedBoarder){ // 遇到了在边界上的'O'，该连通区域无效
        return vector<pair<int,int>>({}); 
      }
      else {
        return toBeFilled;
      }
      


    }
    // 判断索引是否越界
    bool validIdx(int x, int y){
      if ( x >= 0 && x < m && y >= 0 && y <n){
        return true;
      }
      else{
        return false;
      }
    }

    // 判断是否在边界上
    bool inBoarder(int x, int y){
      if (x == 0 || x == m - 1 || y == 0 || y == n - 1){
        return true;
      }
      else{
        return false;
      }
    }

  int m, n;
  const int dx[4] = {-1,1,0,0};
  const int dy[4] = {0,0,-1,1}; // 方向数组, 上下左右
  vector<vector<bool>> visited;
  // vector<pair<int,int>> toBeFilled; // 待填充的'O'
  


};  


int main(){

    Solution my_solution;

    vector<vector<char>> charSet{
    {'O','X','O','O','O','O','O','O','O'},
    {'O','O','O','X','O','O','O','O','X'},
    {'O','X','O','X','O','O','O','O','X'},
    {'O','O','O','O','X','O','O','O','O'},
    {'X','O','O','O','O','O','O','O','X'},
    {'X','X','O','O','X','O','X','O','X'},
    {'O','O','O','X','O','O','O','O','O'},
    {'O','O','O','X','O','O','O','O','O'},
    {'O','O','O','O','O','X','X','O','O'}
    };
    my_solution.solve(charSet);
    

    


    return 0;
}



