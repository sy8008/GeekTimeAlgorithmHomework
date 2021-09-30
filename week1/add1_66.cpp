#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add_flag = 0;
        digits.back() += 1;
        for (int i = digits.size()-1; i>=0; i--){
            if (add_flag == 1){digits[i] += 1;}
            if (digits[i] == 10){
                add_flag = 1;
                digits[i]=0;
            }
            else{
                add_flag = 0;
                
            }
                
        }
        if (add_flag==1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

template<typename T> void printVector(vector<T>vec){
    for (int i=0; i < vec.size(); ++i){
        cout << vec[i] <<endl;
    }

}
int main(){
    Solution my_solution;
    vector<int> input{9,8,9};
    my_solution.plusOne(input);
    printVector(input);

    return 0;
}