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


  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;

        return build(0,postorder.size() - 1, 0 , inorder.size() - 1);

    }

    // 从 poster_order[l1, r1] 和 in_order[l2, r2] 中还原二叉树
    TreeNode* build(int l1, int r1, int l2, int r2){
        if (l1 > r1){return NULL;}
        TreeNode *root = new TreeNode(postorder[r1]);
        int mid = l2;
        while (inorder[mid] != root -> val){
            mid++;

        }
        root -> left = build(l1, l1 +mid - l2 -1, l2 , mid - 1);
        root -> right = build (l1 +mid -l2, r1 - 1, mid + 1, r2);
        return root;
    }
  vector<int> inorder;
  vector<int> postorder;
  
};



int main(){

    Solution my_solution;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution::TreeNode * ans = my_solution.buildTree(inorder,postorder);



    return 0;
}



