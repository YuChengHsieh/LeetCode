#include <iostream>
#include <stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int> v1,v2;
        ListNode* cur = l1;
        while(cur != nullptr){
            v1.push(cur->val);
            cur = cur->next;
        }
        cur = l2;
        while(cur != nullptr){
            v2.push(cur->val);
            cur = cur->next;
        }
        ListNode* head = new ListNode();
        cur = head;
        int carry = 0;
        while(!v1.empty() or !v2.empty() or carry){
            int s1 = !v1.empty() ? v1.top() : 0;
            int s2 = !v2.empty() ? v2.top() : 0;
            
            int sum = s1+s2+carry;
            carry = sum/10;
            sum = sum%10;
            if(!v1.empty()) v1.pop();
            if(!v2.empty()) v2.pop();
            ListNode* nextn = new ListNode(sum,head->next);
            head->next = nextn;
        }
        return head->next;
    }
};