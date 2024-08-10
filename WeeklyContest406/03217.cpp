#include <vector>
#include <set>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> num_set(nums.begin(),nums.end());
        ListNode* dummy_head = new ListNode();
        dummy_head -> next = head;
        ListNode* cur = dummy_head;
        while(cur -> next != nullptr){
            if(num_set.count(cur -> next -> val)){
                ListNode* tmp = cur -> next;
                cur -> next = tmp -> next;
                delete tmp;
            }else cur = cur -> next;
        }
        return dummy_head -> next;
    }
};