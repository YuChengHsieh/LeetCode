#include <iostream>
#include <vector>
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode* cur = head;
        vector<ListNode*> ans;
        while(cur != nullptr){
            cnt += 1;
            cur = cur->next;
        }
        cur = head;
        ListNode* prev = head;
        for(int i=0; i<k; i++){
            ans.push_back(cur);
            for(int j=0; j<cnt/k; j++) {
                prev = cur;
                cur = cur->next;
            }
            if(i<cnt%k){
                prev = cur;
                cur = cur->next;
            }
            if(prev != nullptr) prev->next = nullptr;
        }
        return ans;
    }
};