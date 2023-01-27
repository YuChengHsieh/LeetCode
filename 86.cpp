#include <iostream>

using namespace std;
struct my_listNode {
    int val;
    my_listNode *next;
    my_listNode() : val(0), next(nullptr) {}
    my_listNode(int x) : val(x), next(nullptr) {}
    my_listNode(int x, my_listNode *next) : val(x), next(next) {}
};

class Solution {
public:
    my_listNode* partition(my_listNode* head, int x) {
        // dummy head
        my_listNode* new_head = new my_listNode(-1,head);
        my_listNode* cur = new_head;
        // store nodes that greater than x in original order
        // dummy head
        my_listNode* greater_node = new my_listNode(-1);
        my_listNode* greater_node_cur = greater_node;

        while(cur->next != nullptr){
            if(cur->next->val >= x){
                greater_node_cur->next = cur->next;
                cur->next = cur->next->next;
                greater_node_cur = greater_node_cur->next;
                greater_node_cur->next = nullptr;
            }
            else{
                cur = cur->next;
            }
        }
        // combine linkedlist that nodes < x and linkedlist that nodes >= x
        cur->next = greater_node->next;
        return new_head->next;
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
    int array[6] = {1,4,3,2,5,2};
    my_listNode* ll = new my_listNode(1);
    for(int i=1; i<6; i++){
        insert(array[i],ll);
    }
    ll = a.partition(ll,3);
    show(ll);
    return 0;
}