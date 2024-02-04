#include <numeric>
#include <unordered_set>
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
    long long int min = std::numeric_limits<long long int>::max();
    long long int secondMin = std::numeric_limits<long long int>::max();
    unordered_set<int> visited;
    void traversal(TreeNode* cur){
        if(cur == nullptr) return;
        if(visited.count(cur->val) != 1){
            if(cur->val < min){
                secondMin = min;
                min = cur -> val;
            }else if(cur->val < secondMin) secondMin = cur->val;
            visited.insert(cur->val);
        }
        traversal(cur -> left);
        traversal(cur -> right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        traversal(root);
        return secondMin == std::numeric_limits<long long int>::max() ? -1 : secondMin;
    }
};