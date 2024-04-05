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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy_head = new ListNode();
        dummy_head -> next = list1;
        ListNode* cur = dummy_head;
        
        int del_cnt = b-a+1;
        while(a > 0){
            cur = cur -> next;
            a -= 1;
        }

        for(int i=0; i<del_cnt; i++){
            ListNode* tmp = cur -> next;
            cur -> next = tmp -> next;
            delete tmp;
        }

        ListNode* last_node = cur -> next;
        cur -> next = list2;
        while(list2 -> next !=  nullptr) list2 = list2 -> next;
        list2 -> next = last_node;

        return dummy_head -> next;
    }
};