#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// o(n) time and o(n) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* cur = head;

        while(cur != nullptr){
            arr.push_back(cur -> val);
            cur = cur -> next;
        }
        
        int left = 0, right = arr.size()-1;
        while(left < right){
            if(arr[left] != arr[right]) return false;
            left += 1;
            right -= 1;
        }
        return true;
    }
};

// o(n) time and o(1) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode* dummy_head = new ListNode();
        dummy_head -> next = head;
        ListNode* cur = head;

        while(cur != nullptr){
            cur = cur -> next;
            length ++;
        }

        if(length == 1) return true;

        cur = head;
        for(int i=0; i<length/2-1; i++){
            ListNode* nextn = cur -> next;
            cur -> next = nextn -> next;
            nextn -> next = dummy_head -> next;
            dummy_head -> next = nextn;
        }

        ListNode* tmp = dummy_head -> next;
    
       
        cur = cur -> next;
        if(length%2 == 1) cur = cur -> next;
        ListNode* rev_cur = dummy_head -> next;
        for(int i=0; i<length/2; i++){
            if(cur -> val != rev_cur -> val) return false;
            cur = cur -> next;
            rev_cur = rev_cur -> next;
        }

        return true;
    }
};