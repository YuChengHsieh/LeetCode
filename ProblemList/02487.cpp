
#include <stack>
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        ListNode* cur = head;
        while(cur != nullptr){
            while(!st.empty() && st.top() -> val < cur -> val){
                delete st.top();
                st.pop();
            }
            st.push(cur);
            cur = cur -> next;
        }
        
        ListNode* dummy_head = new ListNode();
        while(!st.empty()){
            st.top() -> next = dummy_head -> next;
            dummy_head -> next = st.top();
            st.pop();
        }
        return dummy_head -> next;
    }
};