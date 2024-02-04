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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr || head -> next -> next == nullptr) return head;
        ListNode* cur = head;
        ListNode* odd_head = new ListNode();
        ListNode* odd_cur = odd_head;
        while(cur != nullptr && cur -> next != nullptr){
            ListNode* odd_node = cur -> next;
            cur -> next = odd_node -> next;
            odd_cur -> next = odd_node;
            odd_node -> next = nullptr;

            if(cur -> next == nullptr) break;
            odd_cur = odd_cur -> next;
            cur = cur -> next;
        }
        cur -> next = odd_head -> next;
        return head;

    }
};