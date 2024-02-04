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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;

        int length = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            cur = cur -> next;
            length += 1;
        }
        
        cur = head;
        for(int i=0; i<length/2-1; i++){
            cur = cur -> next;
        }

        ListNode* del_node = cur->next;
        cur -> next = del_node -> next;
        delete del_node;
        return head;
    }
};