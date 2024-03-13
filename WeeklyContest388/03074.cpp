#include<vector>
using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), [](int a, int b){
            return a > b;
        });
        int total = 0;
        for(auto& num: apple) total += num;
        for(int i=0; i<capacity.size(); i++){
            if(total <= 0) return i;
            total -= capacity[i];
        }
        return capacity.size();
    }
    
};