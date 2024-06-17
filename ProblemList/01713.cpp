#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
private:
    void bs(int val, vector<int>& sub){
        int start = 0, end = sub.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(val > sub[mid]) start = mid + 1;
            else end = mid - 1;
        }
        if(start == sub.size()) sub.push_back(val);
        else sub[start] = val;
    }
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        // longest increasing subseqence
        unordered_map<int,int> mp;
        vector<int> pos;
        for(int i=0; i<target.size(); i++){
            mp[target[i]] = i;
        }

        for(int i=0; i<arr.size(); i++){
            if(mp.count(arr[i])) pos.push_back(mp[arr[i]]);
        }

        vector<int> sub;
        for(int i=0; i<pos.size(); i++){
            bs(pos[i],sub);
        }
        return target.size() - sub.size();
    }
};