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
    my_listNode* deleteDuplicates(my_listNode* head) {
        // create new node point to head if head has a chance to be removed
        my_listNode* new_head = new my_listNode(-30000,head); 
        my_listNode* cur = new_head;
        my_listNode* prev = nullptr;
        int del = -30000;
        while(cur->next != nullptr){
            if(cur->val == cur->next->val){
                del = cur->val;
                cur = prev;
            }
            if(cur->next->val == del){
                my_listNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
            
        }
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
    int array[7] = {1,1,3,3,3,4,5};
    my_listNode* ll = new my_listNode(1);
    for(int i=1; i<7; i++){
        insert(array[i],ll);
    }
    ll = a.deleteDuplicates(ll);
    show(ll);
    return 0;
}