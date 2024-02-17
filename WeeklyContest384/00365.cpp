#include <unordered_set>
#include <numeric>
using namespace std;

// TLE o(n*2) record 2 states of jugs
class Solution {
private:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &pair) const {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };
    bool success = false;
    int jug1cap, jug2cap, target;
    unordered_set<pair<int,int>, pair_hash> visited;
    

    void rec(int jug1, int jug2){
        if(success) return;
        if(jug1 == target || jug2 == target || jug1+jug2 == target){
            success = true;
            return;
        }
        if(visited.count({jug1,jug2})) return;

        visited.insert({jug1,jug2});
        // if(jug1+jug2 < target){
            // full jug
        rec(jug1cap,jug2);
        rec(jug1,jug2cap);
        // }else{
            // empty jug
        rec(0,jug2);
        rec(jug1,0);
        // }
        
        // pour jug1 to jug2
        if(jug1 > jug2cap - jug2) rec(jug1-(jug2cap - jug2), jug2);
        else rec(0, jug2+jug1);

        // pour jug2 to jug1
        if(jug2 > jug1cap-jug1 ) rec(jug1, jug2-(jug1cap - jug1));
        else rec(jug2+jug1,0);
        return;
    }
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        // memorization
        jug1cap = min(jug1Capacity,jug2Capacity); jug2cap = max(jug1Capacity,jug2Capacity), target = targetCapacity;
        rec(jug1cap,jug2cap);
        return success;
    }
};

// o(n) record only total value of jugs
class Solution {
private:
    bool success = false;
    int target, jug1Cap, jug2Cap;

    void rec(int total, vector<int>& visited){
        if(success) return;
        if(total == target){
            success = true;
            return;
        }
        if(total > jug1Cap+jug2Cap || total < 0) return;
        if(visited[total]) return;

        visited[total] = true;

        rec(total+jug1Cap,visited);
        rec(total+jug2Cap,visited);
        rec(total-jug1Cap,visited);
        rec(total-jug2Cap,visited);
        return;
    }
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        // memorization
        jug1Cap = jug1Capacity; jug2Cap = jug2Capacity, target = targetCapacity;
        vector<int> visited(jug1Cap+jug2Cap+1,false);
        rec(0,visited);
        return success;
    }
};

// math solution o(logn)
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int target) {
        if(target == 0) return true;
        if(jug1Capacity + jug2Capacity < target) return false;
        int g = gcd(jug1Capacity, jug2Capacity);
        return target%g == 0;
    }
};