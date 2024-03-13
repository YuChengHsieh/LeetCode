struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy_head = new ListNode();
        dummy_head -> next = head;

        ListNode* cur = head;
        int length = 0;
        while(cur != nullptr){
            length += 1;
            cur = cur -> next;
        }
        
        ListNode* swap_node1 = dummy_head;
        for(int i=0; i<k-1; i++){
            swap_node1 = swap_node1 -> next;
        }

        ListNode* swap_node2 = dummy_head;
        for(int i=0; i<length-k; i++){
            swap_node2 = swap_node2 -> next;
        }
        
        ListNode* tmp = swap_node1 -> next;
        swap_node1 -> next = swap_node2 -> next;
        swap_node2 -> next = tmp;
        
        tmp = swap_node1 -> next -> next;
        swap_node1 -> next -> next = swap_node2 -> next -> next;
        swap_node2 -> next -> next = tmp;
        
        return dummy_head -> next;
    }
    
};