#include <stack>
using namespace std;
class StockSpanner {
private:
    stack<pair<int,int>> s;
    int cnt = 0;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int ret;
        cnt += 1;
        
        while(!s.empty() && price >= s.top().first) s.pop();
        
        if(s.empty()) ret = cnt;
        else ret = cnt - s.top().second;
        
        s.push({price,cnt});
        return ret;
    }
};