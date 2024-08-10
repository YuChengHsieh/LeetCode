#include <vector>
#include <set>
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
    vector<TreeNode*> ans;
    void traverse(TreeNode* cur, TreeNode* parent,set<int>& to_delete){
        if(cur == nullptr) return;
        traverse(cur -> left, cur, to_delete);
        traverse(cur -> right, cur, to_delete);
        if(to_delete.count(cur -> val)){
            if(!parent) ; 
            else if(parent -> left == cur) parent -> left = nullptr;
            else parent -> right = nullptr;
            
            if(cur -> left != nullptr) ans.push_back(cur -> left);
            if(cur -> right != nullptr) ans.push_back(cur -> right);
            delete cur;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> to_delete_s(to_delete.begin(),to_delete.end());
        int root_val = root -> val;
        traverse(root,nullptr,to_delete_s);
        if(!to_delete_s.count(root_val))ans.push_back(root);
        return ans;
    }
};