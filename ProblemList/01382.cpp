#include <vector>
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
    vector<TreeNode*> bst;
    void traverse(TreeNode* cur){
        if(!cur) return;
        traverse(cur -> left);
        bst.push_back(cur);
        traverse(cur -> right);
        return;
    }
    TreeNode* insert(int start, int end){
        if(start > end) return nullptr;
        int mid = start + (end-start)/2;
        bst[mid] -> left = insert(start,mid-1);
        bst[mid] -> right = insert(mid+1,end);
        return bst[mid];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        int start = 0, end = bst.size()-1;
        insert(start,end);
        return bst[start+(end-start)/2];
    }
};

class Solution {
private:
    vector<TreeNode*> bst;
    void traverse(TreeNode* cur){
        if(!cur) return;
        traverse(cur -> left);
        bst.push_back(cur);
        traverse(cur -> right);
        return;
    }
    void insert(TreeNode* cur, int idx, int start, int end){
        if(!cur) return;
        bst[idx] = nullptr;
        cur -> left = bst[(start+idx)/2];
        insert(cur -> left,(start+idx)/2,start,idx);
        cur -> right = bst[(idx+end)/2];
        insert(cur -> right,(idx+end)/2,idx+1,end);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        int start = 0, end = bst.size();
        TreeNode* new_root = bst[(start+end)/2];
        insert(new_root,(start+end)/2,0,end);
        return new_root;
    }
};