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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        n = edges.size();

        fa = vector<int> (n + 1,0);
        int ans = 0; // 冗余的边编号
        
        
        for (int i = 0; i < n; ++i){ // i 是要删除的边
            
            // 初始化father数组
            for (int k = 1; k <= n; ++k){
                fa[k] = k;
            }


             // 删除第i条边后，用剩余的边构建并查集，判断它们的父亲是否相等。
            for (int j = 0; j < n; ++j){
                if (j == i) { continue;}
                vector<int> curr_edge = edges[j]; 
                UnionSet(curr_edge[0],curr_edge[1]); // 如果两个节点有边，就将它们对应的集合合并
            }
            vector<int> tempfa = fa;
            int father = find(1); // 随机选取一个节点，检查剩余的节点的father是否与它相等
            bool is_redundant = true; // 序号为i的边是否冗余
            for (int m = 2; m <= n; m++){
                if (find(m) != father){
                    is_redundant = false; // 如果删除一条边后，剩余的点构成的集合父亲不唯一，说明i边不是冗余的
                }
            }

            if (is_redundant) {ans = max(ans,i);} // i边冗余，更新答案

        }

        return edges[ans];

    }

    vector<int> fa;
    int n;

    void UnionSet(int x, int y){
        x = find(x);
        y = find(y);
        if (x != y){
            fa[x] = y;
        }
    }
    int find(int x){
        if (x == fa[x]){
            return x;
        }
        return fa[x]=find(fa[x]);
    }


};


int main(){
    Solution my_solution;
    vector<vector<int>> input ={{1,2}, {1,3}, {2,3}};
    vector<int> output = my_solution.findRedundantConnection(input);
    cout << output[0] << " " << output[1] <<endl;
 
   




    return 0 ;

}