#include <vector>
using namespace std;

// prefix sum, o(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr){
        int cnt = 0, prefix_sum = 0, cur_sum = 0, n = arr.size()-1;
        for(int i=n; i>=0; i--){
            cur_sum += arr[i];
            prefix_sum += i;
            if(prefix_sum == cur_sum) cnt++;
        }
        return cnt;
    }
}; 

// o(n^2)
class Solution {
public:
    int checkBiggest(vector<bool>& check){
        for(int i=check.size()-1; i>=0; i--){
            if(!check[i]) return i;
        }
        return -1;
    }
    int maxChunksToSorted(vector<int>& arr){
        int cnt = 0, n = arr.size()-1;
        vector<bool> check(n+1,false);
        for(int i=n; i>=0; i--){
            check[arr[i]] = true;
            if(checkBiggest(check) < i) cnt ++;
        }
        return cnt;
    }
};