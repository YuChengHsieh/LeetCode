#include <vector>
#include <set>
using namespace std;
class Solution {
    private:
        bool check(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength){
            k--;
            multiset<int> ws;
            for(int i=0; i<=k; i++){
                ws.insert(workers[i]);
            } 
            for(int i=k; i>=0; i--){
                if(*prev(ws.end()) >= tasks[i]) ws.erase(prev(ws.end()));
                else{
                    if(pills > 0 && ws.lower_bound(tasks[i]-strength) != ws.end()){
                        pills --;
                        ws.erase(ws.lower_bound(tasks[i]-strength));
                    } 
                    else  return false;
                } 
            }
            return true;
        }
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end() , [](int a, int b){return a > b;});
            
            int start = 0, end = min(tasks.size(), workers.size());
            while(start <= end){
                int mid = start + (end - start)/2;
                if(check(mid, tasks, workers, pills, strength)) start = mid + 1;
                else end = mid - 1;
            }
            return end;
        }
    };