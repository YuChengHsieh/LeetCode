#include <iostream>
#include <set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return head;
        ListNode* dummy_head = new ListNode(-1,head);
        ListNode* cur = dummy_head;
        ListNode* nextn = cur->next;
        while(nextn->next != nullptr){
            ListNode* tmp = nextn->next;
            nextn->next = tmp->next;
            cur->next = tmp;
            tmp->next = nextn;
            // update current paras
            cur = nextn;
            nextn = cur->next;
            if(nextn == nullptr) break;
        }
        return dummy_head->next;
    }
};