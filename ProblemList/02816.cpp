using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private:
    bool traverse(ListNode* cur){
        if(cur == nullptr) return false;
        bool carry = traverse(cur -> next);
        bool new_carry = ((cur -> val)*2)/10 == 0 ? false : true;
        cur -> val = ((cur -> val)*2)%10 + carry;
        return new_carry;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        bool carry = traverse(head);
        if(carry){
            ListNode* new_head = new ListNode(1);
            new_head -> next = head;
            head = new_head;
        }
        return head;
    }
};