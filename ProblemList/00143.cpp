#include <unordered_map>
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
    void reorderList(ListNode* head) {
        unordered_map<ListNode*, ListNode*> map;
        
        ListNode* cur = head;
        while(cur -> next != nullptr){
            map[cur -> next] = cur;
            cur = cur -> next;
        }
        
        ListNode* tail = cur;
        // cout << tail -> val;
        cur = head;
        while(cur != tail && cur -> next != tail){
            ListNode* tmp = cur -> next;
            cur -> next = tail;
            tail -> next = tmp;
            cur = cur -> next -> next;
            tail = map[tail];
        }
        tail -> next = nullptr;
    }
};