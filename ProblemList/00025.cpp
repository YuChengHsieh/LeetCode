#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// space complexity o(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        k -= 1;
        ListNode* dummy_head = new ListNode();
        dummy_head -> next = head;
        ListNode* prev = dummy_head, *cur, *nextn;

        while(prev != nullptr){
            
            // check if prev -> prev + k is available
            ListNode* checkn = prev -> next;
            for(int i=0; i<k; i++){
                if(checkn == nullptr) break;
                checkn = checkn -> next;
            }

            if(checkn == nullptr) break;

            cur = prev -> next;
            nextn = cur -> next;
            // cout << prev -> val << ' ' << cur -> val << ' ' << nextn -> val << endl;
            for(int i=0; i<k; i++){
                ListNode* tmp = nextn -> next;
                nextn -> next = prev -> next;
                prev -> next = nextn;
                cur -> next = tmp;

                // update
                nextn = cur -> next;
            }
            prev = cur;
        }
        return dummy_head -> next;
    }
};

// use unordered_map space complexity o(n)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        k -= 1;
        ListNode* dummy_head = new ListNode();
        dummy_head -> next = head;
        unordered_map<ListNode*, ListNode*> map;
        map[head] = dummy_head;
        ListNode* last = head, *first = head;

        while(last != nullptr){
            for(int i=0; i<k; i++){
                map[last -> next] = last;
                last = last -> next;
                if(last == nullptr) break;
            }

            ListNode* cur_last = first;
            if(last != nullptr){
                for(int i=0; i<k/2; i++){

                    map[first] -> next = last;
                    map[last] -> next = first;
                    map[first -> next] = last;
                    map[last -> next] = first;

                    ListNode* tmp = first -> next;
                    first -> next = last -> next;
                    last -> next = tmp;

                    
                    
                    // update map
                    tmp = map[first];
                    map[first] = map[last];
                    map[last] = tmp;

                    // update first, last pointer
                    tmp = first;
                    first = last -> next;
                    last = map[tmp];

                }
                if(k%2 == 1){
                    
                    first -> next = last -> next;
                    last -> next = first;
                    map[first] -> next = last;

                    ListNode* tmp = map[first];
                    map[first] = last;
                    map[last] = tmp;
                    
                }
                if(cur_last -> next != nullptr) map[cur_last->next] = cur_last;
                last = cur_last -> next;
                first = last;
                
            }
        }
        return dummy_head -> next;
    }
};