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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy_head = new ListNode();
        ListNode* cur = head;
        ListNode* nextn = cur;
        while(nextn != nullptr){
            nextn = cur -> next;
            cur -> next = dummy_head -> next;
            dummy_head -> next = cur;
            cur = nextn;
        }
        return dummy_head -> next;
    }
};