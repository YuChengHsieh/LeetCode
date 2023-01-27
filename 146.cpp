// WA
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct my_listNode{
    int val,key;
    my_listNode *next;
    my_listNode *prev;
    my_listNode() : val(-1),key(-1), next(nullptr), prev(nullptr) {}
    my_listNode(int x, int y) :key(x), val(y), next(nullptr), prev(nullptr) {}
    my_listNode(int x, int y, my_listNode *next, my_listNode *prev) :key(x), val(y), next(next), prev(prev) {}
};

class LRUCache {
public:
    my_listNode* dummy_head;
    my_listNode* tail;
    unordered_map<int,my_listNode*> dict;
    int capacity;
    int size;
    LRUCache(int capacity): capacity(capacity), dummy_head(new my_listNode()), tail(dummy_head), size(0) {}

    my_listNode* update_key(int key){
        // move cur to the most recently used key
        my_listNode* cur = dict[key];
        if(dummy_head->next == cur){
            return cur;
        }
        if(tail == cur){
            tail = cur->prev;
        }
        cur->prev->next = cur->next;
        if(cur->next != nullptr){
            cur->next->prev = cur-> prev;
        }
        cur->next = dummy_head->next;
        dummy_head->next->prev = cur;
        dummy_head->next = cur;
        cur->prev = dummy_head;
        return cur;
    }
    int get(int key) {
        if(dict.count(key)){
            my_listNode* cur = update_key(key);
            return cur->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(dict.count(key)){
            my_listNode* cur = update_key(key);
            cur->val = value;
        }else{
            if(size+1>capacity){
                // remove one
                tail = tail->prev;
                my_listNode* tmp = tail->next;
                tail->next = nullptr;
                dict.erase(tmp->key);
                delete tmp;
                size -= 1;
            }
        }
        my_listNode* newn = new my_listNode(key,value,dummy_head->next,dummy_head);
        if(newn->next != nullptr){
            newn->next->prev = newn;
        }else{
            tail = newn;
        }
        dummy_head->next = newn;
        // cout << newn-> next<< endl;
        dict[key] = newn;
        size += 1;
        return;
    }

    void show(my_listNode* cur){
        while(cur != nullptr){
            cout << cur->val;
            cur = cur->next;
        }
        cout << endl;
    }
};



int main(){
    // LRUCache a = LRUCache(2);
    // a.put(1,1);
    // a.put(2,2);
    // cout << a.get(1) << endl;
    // a.put(3,3);
    // cout << a.get(2) << endl;
    // a.put(4,4);
    // cout << a.get(1) << endl;
    // cout << a.get(3) << endl;
    // cout << a.get(4) << endl;

    LRUCache a = LRUCache(1);
    a.put(2,1);
    cout << a.get(2) << endl;
}