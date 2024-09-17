struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while(cur -> next != nullptr){
            ListNode* nextn = cur -> next;
            int val = gcd(cur -> val, nextn -> val);
            ListNode* newn = new ListNode(val);
            cur -> next = newn;
            newn -> next = nextn;
            cur = nextn;
        }
        return head;
    }
};