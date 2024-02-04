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
    int pairSum(ListNode* head) {
        int length = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            length += 1;
            cur = cur -> next;
        }
        
        vector<int> twins_vec(length/2,0);
        cur = head;
        int i=0;
        bool up = true;
        while(cur != nullptr){
            if(i == length/2){
                i -= 1;
                up = false;
            }
            twins_vec[i] += cur -> val;
            if(up) i += 1;
            else i -= 1;
            cur = cur -> next;
        }
        return *max_element(twins_vec.begin(),twins_vec.end());
    }
};