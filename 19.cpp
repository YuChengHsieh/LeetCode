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
    my_listNode* removeNthFromEnd(my_listNode* head, int n){
        int length = 0;
        my_listNode* tmp_node = head;
        while(tmp_node != nullptr){
            tmp_node = tmp_node ->next;
            length += 1;
        } 
        int tar_idx = length-n-1;
        // delete head
        if(tar_idx < 0){
            tmp_node = head;
            head = head->next;
            return head;
        }
        tmp_node = head;
        for(int i=0; i<tar_idx; i++){
            tmp_node = tmp_node->next;
        }
        my_listNode* next_node = tmp_node -> next;
        tmp_node->next = next_node->next;
        delete next_node;
        return head;
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
    int total = 1;
    int array[5] = {1};
    my_listNode* ll = new my_listNode(array[0]);
    for(int i=1;i<total;i++){
        insert(array[i],ll);
    }
    show(ll);
    ll = a.removeNthFromEnd(ll,2);
    show(ll);
    return 0;
}