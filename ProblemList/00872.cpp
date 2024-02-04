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
    vector<int> ans1,ans2;
    void check_leafSeq(TreeNode* cur, bool root1){
        if(cur -> left == nullptr && cur -> right == nullptr){
            if (root1) ans1.push_back(cur -> val);
            else ans2.push_back(cur -> val);
        }
        else if(cur -> left == nullptr) check_leafSeq(cur -> right, root1);
        else if(cur -> right == nullptr) check_leafSeq(cur -> left, root1);
        else{
            check_leafSeq(cur -> right, root1);
            check_leafSeq(cur -> left, root1);
        }
        return;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        check_leafSeq(root1,true);
        check_leafSeq(root2,false);
        return ans1 == ans2;
    }
};
