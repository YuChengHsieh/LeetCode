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
    my_listNode* mergeTwoLists(my_listNode* list1, my_listNode* list2) {
        my_listNode* head = new my_listNode();
        my_listNode* tmp_node = head;
        int tmp_val;
        while(list1 != nullptr or list2 != nullptr){
            if(list1 == nullptr or (list2 != nullptr and list2->val<list1->val)){
                tmp_node -> next = list2;
                list2 = list2->next;
            }
            // list2 == nullptr or (list1 != nullptr and list1->val<=list2->val)
            else{ 
                tmp_node -> next = list1;
                list1 = list1->next;
            }
            tmp_node = tmp_node->next;
        }
        return head -> next;
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
    int n1 = 4;
    int n2 = 3;
    int array1[4] = {1,2,4,5};
    int array2[3] = {1,3,4};
    my_listNode* l1 = new my_listNode(array1[0]);
    my_listNode* l2 = new my_listNode(array2[0]);
    for(int i=1;i<n1;i++){
        insert(array1[i],l1);
    }
    for(int i=1;i<n2;i++){
        insert(array2[i],l2);
    }
    show(l1);
    show(l2);
    my_listNode* ll = a.mergeTwoLists(l1,l2);
    show(ll);
    return 0;
}