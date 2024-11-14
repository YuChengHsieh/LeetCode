#include <vector>
using namespace std;
class MyCircularDeque {
private:
    vector<int> deque;
    int front = 0;
    int back = 0;
    int k;
public:
    MyCircularDeque(int val): deque(val,INT_MAX), k(val){}
    
    bool insertFront(int value) {
        if(isFull()) return false;
        deque[front] = value;
        front = (front+1)%k;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        back = (back+k-1)%k;
        deque[back] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front = (front+k-1)%k;
        deque[front] = INT_MAX;
        return true;

    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        deque[back] = INT_MAX;
        back = (back+1)%k;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : deque[(front+k-1)%k];
    }
    
    int getRear() {
        return isEmpty() ? -1 :deque[back];
    }
    
    bool isEmpty() {
        return front == back && deque[front] == INT_MAX;
    }
    
    bool isFull() {
        return front == back && deque[front] != INT_MAX;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */