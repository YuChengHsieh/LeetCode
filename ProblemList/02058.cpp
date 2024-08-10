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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first_idx = INT_MAX, prev_idx = -1;
        ListNode* cur = head -> next;
        int prev_val = head -> val, mininum_interval = INT_MAX;
        int idx = 0;
        while(cur -> next != nullptr){
            if((prev_val < cur -> val && cur -> next -> val < cur -> val) ||
            (prev_val > cur -> val && cur -> next -> val > cur -> val)){
                first_idx = min(first_idx,idx);
                if(idx - first_idx != 0) mininum_interval = min(mininum_interval,idx - prev_idx);
                prev_idx = idx;
            }
            prev_val = cur -> val;
            cur = cur -> next;
            idx ++;
        }
        return mininum_interval == INT_MAX ? vector<int>({-1,-1}) : vector<int>({mininum_interval, prev_idx-first_idx});
    }
};