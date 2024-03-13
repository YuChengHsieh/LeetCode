struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            length += 1;
            cur = cur -> next;
        }

        cur = head;
        for(int i=0; i<length/2; i++){
            cur = cur -> next;
        }
        return cur;
    }
};