#include <iostream>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ListNodeCmp{
    public:
        bool operator()(ListNode* l, ListNode* r){
            return l->val > r->val;
        }
};
class Solution {
public:
    priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> pq;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        int total_len = lists.size();
        for(int i=0; i<total_len; i++){
            if(lists[i]!= nullptr) pq.push(lists[i]);
        }
        ListNode* cur = head;
        while(!pq.empty()){
            ListNode* tmp_listNode = pq.top();
            cur->next = tmp_listNode;
            if(tmp_listNode->next != nullptr){
                pq.push(tmp_listNode->next);
                tmp_listNode->next = nullptr;
            }
            cur = cur->next;
            pq.pop();
        }
        return head->next;
    }
};