#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool rec(ListNode* head, ListNode* curl, TreeNode* curt, map<pair<ListNode*,TreeNode*>,bool>& mem){
        if(curl == nullptr) return true;
        if(curt == nullptr) return false;
        if(mem.count({curl,curt})) return mem[{curl,curt}];
        bool ans = false;
        if(curt -> val == curl -> val){
            ans |= rec(head, curl -> next, curt -> left, mem);
            ans |= rec(head, curl -> next, curt -> right, mem);
        }
        if(head -> val == curt -> val){
            ans |= rec(head, head -> next, curt -> left, mem);
            ans |= rec(head, head -> next, curt -> right, mem);
        }
        ans |= rec(head, head, curt -> left, mem);
        ans |= rec(head, head, curt -> right, mem);
        return mem[{curl,curt}] = ans;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        map<pair<ListNode*,TreeNode*>,bool> mem;
        return rec(head, head, root, mem);
    }
};