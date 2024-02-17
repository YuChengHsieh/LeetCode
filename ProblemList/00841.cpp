#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
private:
    unordered_set<int> visited;
    void dfs(int num,vector<vector<int>>& rooms){
        if(visited.count(num)) return;
        visited.insert(num);
        for(auto nextn: rooms[num]){
            if(!visited.count(nextn)) dfs(nextn,rooms);
        }
        return;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(0,rooms);
        return visited.size() == rooms.size();
    }
};