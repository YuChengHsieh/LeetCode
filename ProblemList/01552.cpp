#include <vector>
using namespace std;
class Solution {
private:
    int check(int distance, int m, vector<int>& position){
        int cur_dis = position[0]+distance;
        m -= 1;
        for(int i=1; i<position.size(); i++){
            if(position[i] < cur_dis) continue;
            cur_dis = position[i]+distance;
            m -= 1;
            if(m == 0) return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start = 1, end = position.back()-position.front();
        while(start <= end){
            int mid = start + (end-start)/2;
            if(check(mid,m,position)) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
};