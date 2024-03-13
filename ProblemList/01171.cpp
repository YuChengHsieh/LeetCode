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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // stack<ListNode*> st;
        unordered_map<int, ListNode*> map;
        ListNode* dummy_head = new ListNode();
        dummy_head -> next = head;
        ListNode* cur = head;
        int sum = 0;
        map[0] = dummy_head;
        while(cur != nullptr){
            sum += cur -> val;
            if(map.count(sum)){
                ListNode* tmp = map[sum];
                int tmp_sum = sum;
                cur = cur -> next;
                while(tmp -> next != cur){
                    ListNode* del_node = tmp -> next;
                    tmp_sum += del_node -> val;
                    if(map[tmp_sum] == del_node) map.erase(tmp_sum);
                    tmp -> next = del_node -> next;
                    // delete del_node;
                }
            }else{
                map[sum] = cur;
                cur = cur -> next;
            } 
            
        }
        
        return dummy_head -> next;
    }
};
