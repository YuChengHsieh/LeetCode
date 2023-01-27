#include <iostream>
using namespace std;

struct my_listNode {
    int val;
    my_listNode *next;
    my_listNode() : val(0), next(nullptr) {}
    my_listNode(int x) : val(x), next(nullptr) {}
    my_listNode(int x, my_listNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         bool carry = false;
//         int tmp_val = l1->val + l2->val;
//         if(tmp_val > 9){
//                 tmp_val -= 10;
//                 carry = true;
//             }
//         ListNode* head = new ListNode(tmp_val);
//         ListNode* tmp_node = head;
//         l1 = l1 -> next;
//         l2 = l2 -> next;

//         while(l1 != nullptr and l2 != nullptr){
//             tmp_val = l1->val + l2->val;
//             if(carry == true){
//                 tmp_val += 1;
//             }
//             if(tmp_val > 9){
//                 tmp_val -= 10;
//                 carry = true;
//             }else{
//                 carry = false;
//             }
//             ListNode* new_node = new ListNode(tmp_val);
//             tmp_node->next = new_node;

//             // update parameters
//             l1 = l1 -> next;
//             l2 = l2 -> next;
//             tmp_node = new_node;
//         }

//         // len(l1) != len(l2)
//         if(l2 != nullptr){
//             l1 = l2;
//         }
//         while(l1 != nullptr){
//             tmp_val = l1->val;
//             if(carry == true){
//                 tmp_val += 1;
//             }
//             if(tmp_val > 9){
//                 tmp_val -= 10;
//                 carry = true;
//             }else{
//                 carry = false;
//             }

//             ListNode* new_node = new ListNode(tmp_val);
//             tmp_node->next = new_node;
//             // update parameters
//             l1 = l1 -> next;
//             tmp_node = new_node;
//         }

//         if(carry == true){
//             ListNode* new_node = new ListNode(1);
//             tmp_node->next = new_node;
//             }

//     return head;        
//     }
// };

class Solution {
public:
    my_listNode* addTwoNumbers(my_listNode* l1, my_listNode* l2) {
        bool carry = false;
        my_listNode* head = new my_listNode();
        my_listNode* tmp_node = head;
        int tmp_val;
        while(l1 != nullptr || l2 != nullptr){
            // check whether l1 or l2 is out of numbers
            if(l1 == nullptr){
                tmp_val = l2->val;
            }else if(l2 == nullptr){
                tmp_val = l1->val;
            }else{
                tmp_val = l1->val + l2->val;
            }
            // check whether addition generates carry
            if(carry == true){
                tmp_val += 1;
            }
            if(tmp_val > 9){
                tmp_val -= 10;
                carry = true;
            }else{
                carry = false;
            }

            my_listNode* new_node = new my_listNode(tmp_val);
            tmp_node->next = new_node;

            // update parameters
            if (l1 == nullptr){
                l2 = l2 -> next;
            }else if (l2 == nullptr){
                l1 = l1 -> next;
            }else{
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            tmp_node = new_node;
        }
        if(carry == true){
            my_listNode* new_node = new my_listNode(1);
            tmp_node->next = new_node;
            }

    return head->next;        
    }
};

void insert(int val, my_listNode* cur){
    my_listNode* tmp_node = new my_listNode(val);
    while(cur -> next != nullptr){
        cur = cur->next;
    }
    cur->next = tmp_node;
}

void show(my_listNode* cur){
    while(cur != nullptr){
        cout << cur->val;
        cur = cur->next;
    }
    cout << endl;
}

int main(){
    Solution a = Solution();
    int l1[3] = {2,4,3}; 
    int l2[3] = {5,6,4};
    my_listNode* l1_ll = new my_listNode(2); 
    my_listNode* l2_ll = new my_listNode(5);

    for(int i=1;i<3;i++){
        insert(l1[i],l1_ll);
        insert(l2[i],l2_ll);
    }
    my_listNode* ret_node = a.addTwoNumbers(l1_ll,l2_ll);
    show(ret_node);
    
    return 0;
}