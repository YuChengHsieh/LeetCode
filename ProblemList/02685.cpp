#include <vector>
#include <unordered_map>
using namespace std;
class Unionfind{
    private:
        vector<int> parents;
    public:
        Unionfind(int n): parents(n,0){
            for(int i=0; i<n; i++){
                parents[i] = i;
            }
        }
    
        int find(int cur){
            if(parents[cur] != cur)  parents[cur] = find(parents[cur]);
            return parents[cur];
        }
    
        void union_(int a, int b){
            int pa = find(a);
            int pb = find(b);
            if(pa != pb) parents[pb] = pa;
        }
    };
    
    class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            Unionfind uf = Unionfind(n);
            unordered_map<int,int> num, denum;
            for(auto& e: edges){
                uf.union_(e[0],e[1]);
            }
    
            for(auto& e: edges){
                num[uf.find(e[0])] += 1;
            }
    
            for(int i=0; i<n; i++){
                denum[uf.find(i)] += 1;
            }
    
            int ans = 0;
            for(auto& item: denum){
                if(num[item.first] == item.second*(item.second-1)/2) ans ++;
            }
            return ans;
        }
    };