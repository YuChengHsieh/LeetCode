#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// space complexity o(1) solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        bool count = false;
        ListNode* cur1 = l1, *cur2 = l2;
        int add_val;
        while(cur1 != nullptr || cur2 != nullptr){
            if(cur1 != nullptr && cur2 != nullptr) add_val = cur1 -> val + cur2 -> val + (int)count;
            else if(cur1 != nullptr) add_val = cur1 -> val + (int)count;
            else if(cur2 != nullptr) add_val = cur2 -> val + (int)count;
            if(add_val >= 10){
                count = true;
                add_val -= 10;
            }else count = false;

            cur1 -> val = add_val;
            if(cur1 -> next == nullptr){  
                if((cur2 == nullptr || cur2 -> next == nullptr) && !count) break;
                ListNode* new_n = new ListNode(0);
                cur1 -> next = new_n;
            }

            cur1 = cur1 -> next;
            if(cur2 != nullptr) cur2 = cur2 -> next;
        }
        return l1;
    }
};