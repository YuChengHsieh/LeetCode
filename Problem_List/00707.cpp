struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    MyLinkedList() {
        head = new ListNode(-1);
        tail = head;
    }
    
    int get(int index) {
        ListNode* cur = head->next;
        while(cur != nullptr){
            if(index==0) return cur->val;
            index -= 1;
            cur = cur->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* newn = new ListNode(val);
        ListNode* tmp = head->next;
        head->next = newn;
        newn->next = tmp;
        if(tail == head) tail = newn;
    }
    
    void addAtTail(int val) {
        ListNode* newn = new ListNode(val);
        tail->next = newn;
        tail = newn;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* cur = head;
        while(cur != nullptr){
            if(index==0){
                ListNode* newn = new ListNode(val);
                ListNode* tmp = cur->next;
                if(tmp == nullptr) tail = newn;
                cur->next = newn;
                newn->next = tmp;
                return;
            }
            index -= 1;
            cur = cur->next;
        }
    }
    
    void deleteAtIndex(int index) {
        ListNode* prev = head;
        ListNode* cur = head->next;
        while(cur != nullptr){
            if(index==0){
                if(cur->next == nullptr) tail = prev;
                ListNode* tmp = cur->next;
                prev -> next = tmp;
                delete cur;
                return;
            }
            index -= 1;
            prev = cur;
            cur = cur->next;
        }
    }
private:
    ListNode* head;
    ListNode* tail;
};