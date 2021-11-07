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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = m - 1;
        int target_row = -1;
        // 先查找元素所在行
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n-1]){ // 说明target 在该行
                target_row = mid;
                break;
            }   
            else if (target < matrix[mid][0]){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }

        }

        if (target_row == -1){return false;} 

        left = 0;
        right = n - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (target == matrix[target_row][mid] ){
                return true;
            }
            if (target < matrix[target_row][mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }

        }

        return false;


    }
};

int main(){
    Solution my_solution;
    vector<vector<int>> matrix= {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << my_solution.searchMatrix(matrix,target) << endl;




    return 0 ;

}