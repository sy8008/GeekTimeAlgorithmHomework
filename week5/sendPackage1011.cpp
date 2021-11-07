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
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);

        // 查找能够满足要求的最小容量值
        while (left < right){
            int mid = left + (right - left) / 2;
            if (validateCapacityInDays(weights,days,mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
            cout << "mid: " << mid << endl;
        }
        return right;


    }

    // 验证当船的容量为capacity时，在指定天数内是否能够将所有货物运输完成。
    // 相当于把n个数 放进 k 个指定大小的盒子，验证是否能够完全放进去
    bool validateCapacityInDays(vector<int>& weights, int days, int capacity){
        int sumDay = 1; // 需要的天数
        int currWeight = 0;
        for (int & w: weights){
            // if (w > capacity){ return false; } // 一个货物就已经超过最大装载容量了

            if (currWeight + w <= capacity ){ // 如果没达到容量限制，就不断装载
                currWeight += w;
            }
            else{ // 如果装不下了，就需下一天再继续装
                sumDay++;
                currWeight = w;
            }

        }
        return sumDay <= days;
    }

};

int main(){
    Solution my_solution;
    vector<int> weights = {1,2,3,1,1};
    int D = 4;
    cout << my_solution.shipWithinDays(weights,D) << endl;




    return 0 ;

}