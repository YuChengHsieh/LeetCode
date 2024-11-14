#include <vector>
using namespace std;
class CustomStack {
public:
    vector<int> vec;
    int cur_val, max_size;
    CustomStack(int maxSize) : cur_val(0), max_size(maxSize) {}
    
    void push(int x) {
        if(vec.size() == max_size) return;
        vec.push_back(x);
    }
    
    int pop() {
        if(vec.size() == 0) return -1;
        int val = vec.back();
        vec.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(k,(int)vec.size()); i++){
            vec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */