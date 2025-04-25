#include <vector>
using namespace std;
class Solution {
    public:
        bool checkCuts(vector<vector<int>>& rectangles, int dim){
            sort(rectangles.begin(), rectangles.end(), [=](vector<int>& a, vector<int>& b){
                return a[dim] < b[dim];
            });
    
            int cnt = 0, end = 0;
            for(auto& r: rectangles){
                if(r[dim] >= end){
                    cnt ++;
                    end = r[dim+2];
                }else end = max(end, r[dim+2]);
                if(cnt == 3) return true;
            }
            return false;
        }
    
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {    
            return checkCuts(rectangles,0) || checkCuts(rectangles,1);
        }
    };