#include <vector>
using namespace std;
class Solution {
private:
    vector<int> findPrime(){
        vector<int> ans;
        ans.push_back(0);
        for(int i=2; i<1000; i++){
            bool isPrime = true;
            for(int j=2; j<=sqrt(i); j++){
                if(i%j == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) ans.push_back(i);
        }
        return ans;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime = findPrime();
        int val = 0;
        for(auto& num: nums){
            int start = 0, end = prime.size()-1;
            int tar = num-val;
            if(tar <= 0) return false;
            while(start <= end){
                int mid = start + (end-start)/2;
                if(prime[mid] < tar) start = mid + 1;
                else end = mid - 1;
            }
            val = num - prime[end];
        }
        return true;
    }
};