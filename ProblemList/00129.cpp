#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int ans = 0;
    void traverse(TreeNode* cur, string s){
        s += cur -> val + '0';
        if(cur -> left == nullptr && cur -> right == nullptr) ans += stoi(s);
        if(cur -> left != nullptr) traverse(cur -> left, s);
        if(cur -> right != nullptr) traverse(cur -> right, s);
    }
public:
    int sumNumbers(TreeNode* root) {
        traverse(root,"");
        return ans;
    }
};

class Solution {
public:
    int mySumNumbers(TreeNode* cur,  vector<int> vec){
        int sum = 0;
        vec.push_back(cur->val);
        if(cur->left == nullptr and cur->right == nullptr){
            for(int i=0 ; i<vec.size() ; i++){
                sum+=pow(10,i)*vec[vec.size()-1-i];
            }
        }
        else{
            if(cur->left != nullptr) sum += mySumNumbers(cur->left,vec);
            if(cur->right != nullptr) sum += mySumNumbers(cur->right,vec);
        }
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        vector<int> vec;
        return mySumNumbers(root,vec);
    }
};