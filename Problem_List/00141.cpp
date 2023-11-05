#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur = head;
        while (cur != nullptr){
            if(cur -> val == INT_MAX) return true;
            cur->val = INT_MAX;
            cur = cur->next;
        }
        return false;
    }
};