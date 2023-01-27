#include <iostream>
#include <set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    set<ListNode*> appear;
    ListNode *detectCycle(ListNode *head) {
        ListNode* cur = head;
        while(cur != nullptr){
            if(appear.count(cur)) return cur;
            else appear.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};