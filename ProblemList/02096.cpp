#include <string>
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
    bool find(TreeNode* cur, int val, string& str){
        if(cur == nullptr) return false;
        if(cur -> val == val) return true;
        if(find(cur -> left, val, str)) str += "L";
        else if(find(cur -> right, val, str)) str += "R";
        else return false;
        return true;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string left, right;
        find(root,startValue,left);
        find(root,destValue,right);
        string ans;
        reverse(left.begin(), left.end());
        reverse(right.begin(), right.end());
        int idx = 0;
        for(; idx<min(left.size(), right.size()); idx++){
            if(left[idx] != right[idx]) break;
        }
        for(int i=idx; i<left.size(); i++){
            ans += "U";
        }
        ans += right.substr(idx,right.size()-idx);
        return ans;
    }
};