#include <vector>
using namespace std;

// memorization TLE
class Solution {
private:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &pair) const {
            // Use hash_combine to combine hashes of pair.first and pair.second
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };
    int fee;
    int rec(int idx, int val, vector<int> &prices, unordered_map<pair<int,int>, int, pair_hash> &mem){
        if(idx >= prices.size()) return 0;
        if(mem.count({idx,val})) return mem[{idx,val}];

        int ret = 0;
        if(val != -1){
            ret = max(ret,rec(idx+1,val,prices,mem));
            if(prices[idx]-val-fee > 0) ret = max(ret,prices[idx]-val-fee+rec(idx+1,-1,prices,mem));
        }else{
            ret = max(ret,rec(idx+1,prices[idx],prices,mem));
            ret = max(ret,rec(idx+1,val,prices,mem));
        }
        mem[{idx,val}] = ret;
        return ret;
    }
public:
    int maxProfit(vector<int>& prices, int f) {
        fee = f;
        unordered_map<pair<int,int>, int, pair_hash> mem;
        return rec(0,-1,prices,mem);
    }
};

class Solution {
private:
    int fee;
    int rec(int idx, bool cur, vector<int> &prices, vector<vector<int>> &mem){
        if(idx >= prices.size()) return 0;
        if(mem[idx][int(cur)] != -1) return mem[idx][cur];

        int ret = rec(idx+1,cur,prices,mem);
        if(cur) ret = max(ret,prices[idx]-fee+rec(idx+1,false,prices,mem));
        else ret = max(ret,-prices[idx]+rec(idx+1,true,prices,mem));
        mem[idx][int(cur)] = ret;
        return ret;
    }
public:
    int maxProfit(vector<int>& prices, int f) {
        fee = f;
        vector<vector<int>> mem(prices.size(), vector<int>(2,-1));
        return rec(0,false,prices,mem);
    }
};