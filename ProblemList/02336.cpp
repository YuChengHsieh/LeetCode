#include <set>
using namespace std;
class SmallestInfiniteSet {
private:
    set<int> s;
    int small = 1;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(s.size()){
            int val = *s.begin();
            s.erase(val);
            return val;
        }else{
            return small++;
        }
    }
    
    void addBack(int num) {
        if(num < small) s.insert(num);
    }
};
