#include <set>
#include <map>
#include <string>
using namespace std;
class AllOne {
private:
    set<pair<int,string>> s;
    map<string,int> m;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(s.count({m[key],key})) s.erase({m[key],key});
        m[key] ++;
        s.insert({m[key],key});
    }
    
    void dec(string key) {
        if(s.count({m[key],key})) s.erase({m[key],key});
        m[key] --;
        if(m[key] > 0) s.insert({m[key],key});
    }
    
    string getMaxKey() {
        return s.size() == 0 ? "" : s.rbegin() -> second;
    }
    
    string getMinKey() {
        return s.size() == 0 ? "" : s.begin() -> second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */