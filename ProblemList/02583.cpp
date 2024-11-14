#include <vector>
#include <queue>
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

// recursion
class Solution {
private:
    vector<long long> level;
    void traverse(int l, TreeNode* cur){
        if(cur == nullptr) return;
        if(l >= level.size()) level.push_back(0);
        level[l] += cur -> val;
        traverse(l+1,cur -> left);
        traverse(l+1,cur -> right);
        return;
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        traverse(0,root);
        sort(level.begin(),level.end(),[](long long a, long long b){return a > b;});
        return k > level.size() ? -1 : level[k-1];
    }
};

// queue
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> level;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long sum = 0;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* cur = q.front();
                q.pop();
                sum += cur -> val;
                if(cur -> left) q.push(cur -> left);
                if(cur -> right) q.push(cur -> right);
            }
            level.push_back(sum);
        }
        sort(level.begin(), level.end(), [](long long a, long long b){return a > b;});
        return k > level.size() ? -1 : level[k-1];
    }
};