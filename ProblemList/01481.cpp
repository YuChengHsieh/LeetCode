#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        for(auto& num: arr){
            map[num] += 1;
        }
        
        vector<int> cnts;
        for(auto& item: map){
            cnts.push_back(item.second);
        }

        sort(cnts.begin(),cnts.end());
        for(int i=0; i<cnts.size(); i++){
            k -= cnts[i];
            if(k < 0) return cnts.size() - i;
        }
        return 0;
    }
};