#include <queue>
using namespace std;
class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        while(!q.empty() && t-3000 > q.front() ) q.pop();
        return q.size();
    }
};