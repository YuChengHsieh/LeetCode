#include <iostream>
#include <vector>

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
    my_listNode* reverseBetween(my_listNode* head, int left, int right) {
        my_listNode* dummy_head = new my_listNode(-1,head);
        my_listNode* new_ll = new my_listNode(-1);
        my_listNode* cur = dummy_head;
        int cnt = 0;
        // find most left change ll
        while(cnt+1 != left){
            cur = cur->next;
            cnt += 1;
        }
        // move reversing node intp new ll
        my_listNode* new_ll_end = nullptr;
        while(cnt!= right){
            my_listNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = new_ll->next;
            if(tmp->next == nullptr){
                new_ll_end = tmp;
            }
            new_ll->next = tmp;
            cnt += 1;
        }

        // moved reverse ll back to original
        new_ll_end->next = cur->next;
        cur->next = new_ll->next;
        delete new_ll;
        return dummy_head->next;
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
    vector <int> v = {5};
    my_listNode* ll = new my_listNode(0);
    for(auto i :v){
        insert(i,ll);
    }
    show(ll->next);
    ll = a.reverseBetween(ll->next,1,1);
    show(ll);
    return 0;
}