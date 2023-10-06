#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        Node* new_head = new Node(-1);
        Node* new_cur = new_head;
        unordered_map <Node*, Node*> fi;
        unordered_map <Node*, Node*> sc;
        
        while (cur != nullptr){
            Node* new_tmp = new Node(cur->val);
            new_cur->next = new_tmp;
            new_cur = new_cur->next;
            fi[new_cur] = cur;
            sc[cur] = new_cur;
            cur = cur->next;
        }

        cur = head;
        new_cur = new_head->next;
        while (new_cur != nullptr){
            if(fi[new_cur]->random != nullptr) new_cur->random = sc[fi[new_cur]->random];
            new_cur = new_cur->next;
        }
        return new_head->next;
    }
};