struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy_head = new ListNode();
        ListNode* ans_cur = dummy_head;
        ListNode* cur = head;
        int sum;
        while(cur != nullptr){
            if(cur -> val == 0){
                if(cur != head){
                    ListNode* nextn = new ListNode(sum);
                    ans_cur -> next = nextn;
                    ans_cur = ans_cur -> next;
                }
                sum = 0;
            }
            else sum += cur -> val;
            cur = cur -> next;
        }
        return dummy_head -> next;
    }
};