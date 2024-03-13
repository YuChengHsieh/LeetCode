#include <iostream>
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
public:
    bool rec(TreeNode* cur,long int left_bound, long int right_bound) {
        bool left_valid = false;
        bool right_valid = false;
        if(cur->left == nullptr){
            left_valid = true;
        }
        else if(cur->left->val<cur->val and cur->left->val > left_bound){
            // into left subtree, cur->val act as a right bounded
            /*
            if cur->val = 5, cur->left->val = 3, ? is bounded by(3,5(cur->val))
`                   5
                   / \
                  3   8
                   \   
                    ?   
            */
            left_valid = rec(cur->left,left_bound,cur->val);
        }
        else{
            return false;
        }

        if(cur->right == nullptr){
            right_valid = true;
        }
        else if(cur->right->val>cur->val and cur->right->val<right_bound){
            // into right subtree, cur->val act as a left bounded
            /*
            if cur->val = 5, cur->right->val = 8, ? is bounded by(5(cur->val),8)
`                   5
                   / \
                  3   8
                     /   
                    ?   
            */
            right_valid =  rec(cur->right,cur->val,right_bound);
        }
        else{
            return false;
        }

        if(left_valid and right_valid){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isValidBST(TreeNode* root){
        return rec(root,INT64_MIN,INT64_MAX);
    }
};

class Solution {
private:
    bool traverse(TreeNode* cur, long long max_val, long long min_val){
        if(cur == nullptr) return true;
        if(cur -> val > min_val && cur -> val < max_val)
            return traverse(cur->left, min((long long)cur->val, max_val), min_val) & traverse(cur->right, max_val, max(min_val,(long long)cur->val));
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return traverse(root->left, root -> val, (long long)INT_MIN-1) & traverse(root->right,(long long)INT_MAX+1, root->val);
    }
};

int main(){
    // TreeNode* left_2 = new TreeNode(3);
    // TreeNode* right_2 = new TreeNode(6);
    // TreeNode* left = new TreeNode(1);
    // TreeNode* right = new TreeNode(4,left_2,right_2);
    // TreeNode* root = new TreeNode(5,left,right);

    TreeNode* left_2 = new TreeNode(4);
    TreeNode* right_2 = new TreeNode(9);
    TreeNode* left = new TreeNode(1);
    TreeNode* right = new TreeNode(7,left_2,right_2);
    TreeNode* root = new TreeNode(5,left,right);

    // TreeNode* left = new TreeNode(1);
    // TreeNode* right = new TreeNode(3);
    // TreeNode* root = new TreeNode(2,left,right);

    // TreeNode* right = new TreeNode(1);
    // TreeNode* root = new TreeNode(0, nullptr,right);

    Solution a = Solution();
    cout << a.isValidBST(root);
}