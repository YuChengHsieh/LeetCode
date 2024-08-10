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
    int ans = 0;
    map<int,int> traverse(TreeNode* cur, int distance){
        if(cur -> left == nullptr && cur -> right == nullptr){
            map<int,int> ret;
            ret[1] = 1;
            return ret;
        }
        map<int,int> left,right;
        if(cur -> left != nullptr) left = traverse(cur->left, distance);
        if(cur -> right != nullptr) right = traverse(cur->right, distance);

        map<int,int> ret;
        for(auto& itemL: left){
            for(auto& itemR: right){
                if(itemL.first+itemR.first > distance) break;
                else ans += itemL.second*itemR.second;
            }
        }


        for(auto& item: left){
            if(item.first+1 > distance) break;
            ret[item.first+1] += item.second;
        }

        for(auto& item: right){
            if(item.first+1 > distance) break;
            ret[item.first+1] += item.second;
        }

        return ret;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        auto mp = traverse(root,distance);
        return ans;
    }
};