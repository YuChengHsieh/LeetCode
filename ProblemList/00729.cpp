#include <vector>
using namespace std;
class MyCalendar {
private:
    vector<vector<int>> vec;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int idx = 0;
        for(; idx < vec.size(); idx++){
            if(end <= vec[idx][0]) break;
            if(!(start >= vec[idx][1])) return false;
        }
        vec.insert(vec.begin()+idx, {start,end});

        return true;
    }
};
