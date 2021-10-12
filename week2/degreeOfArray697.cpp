#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
      unordered_map<int,int> umap;
      int n = nums.size();
      
      for (int num:nums){
          umap[num]++; // 统计每个值出现的次数
      }
    
      // 查找出现次数最多的元素
      auto max_it = max_element(umap.begin(),umap.end(),[](const pair<int,int> &p1, const pair<int,int> &p2){return p1.second < p2.second;});
      int max_key = max_it->first;
      int max_value =  max_it->second;
      
      auto umap_it = umap.begin();
      vector<int> degree_element;

      // 将所有出现次数最多的元素保存下来
      while (umap_it != umap.end()){
          umap_it= find_if(umap_it,umap.end(),[max_value](const pair<int,int> &p){return p.second == max_value;}); 
          if (umap_it != umap.end()){
            degree_element.push_back(umap_it->first);           
            umap_it++;
          }
      }
    
      
      vector<int> subArrayLength;
      vector<int> degree_pos;
      for (int element:degree_element){
        auto start_it = nums.begin();

        // 记录每个出现次数最多的元素第一次出现和最后一次出现的位置
        while (start_it != nums.end()){
            start_it = find(start_it,nums.end(),element);
            if (start_it != nums.end()){
                int find_pos = distance(nums.begin(),start_it);
                degree_pos.push_back(find_pos);
                start_it++;
            }
        }
        subArrayLength.push_back(degree_pos.back() - degree_pos.front() + 1);
        degree_pos.clear();
      }
      
      // 对于所有出现次数最多的元素，它们第一次出现位置和最后一次出现位置的差的最小值+1就是含有相同度的最小子数组长度
      int min_value = *min_element(subArrayLength.begin(),subArrayLength.end());
      return min_value;
      
    }
};




int main(){
    Solution my_solution;


    vector<int>nums = {1,2,2,1,2,1,1,1,1,2,2,2};

    cout << my_solution.findShortestSubArray(nums) <<endl;




    return 0;
}



