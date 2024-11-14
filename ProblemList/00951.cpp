#include <set>
#include <map>
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
    void traverse(TreeNode* cur, map<int, set<int>>& mp){
        if(cur -> left){
            mp[cur -> val].insert(cur -> left -> val);
            traverse(cur -> left, mp);
        } 
        if(cur -> right){
            mp[cur -> val].insert(cur -> right -> val);
            traverse(cur -> right, mp);
        } 
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        map<int,set<int>> mp1, mp2;
        if(root1){
            mp1[-1].insert(root1 -> val);
            traverse(root1,mp1);
        } 
        if(root2){
            mp2[-1].insert(root2 -> val);
            traverse(root2,mp2);
        } 
        return mp1 == mp2;
    }
};