struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int level = 1;
        ListNode* dummy_head = new ListNode();
        dummy_head -> next = head;
        ListNode* prev = dummy_head; 
        while(prev != nullptr && prev -> next != nullptr){
            int length = 0;
            ListNode* check = prev;
            for(int i=0; i<level; i++){
                if(check -> next == nullptr) break;
                check = check -> next;
                length += 1;
            }
            if(length%2 == 0){
                ListNode* cur = prev -> next;
                ListNode* nextn = cur -> next;
                ListNode* cur_end = cur;
                for(int i=0; i< length-1; i++){
                    ListNode* tmp = nextn -> next;
                    nextn -> next = prev -> next;
                    prev -> next = nextn;
                    cur -> next = tmp;

                    // update
                    nextn = cur -> next;
                }
                prev = cur_end;
            }else prev = check;
            level += 1;
        }
        return dummy_head -> next;
    }
};