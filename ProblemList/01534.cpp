#include<vector>
using namespace std;

// o(n^3)
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                for(int k=j+1; k<arr.size();k++){
                    if(abs(arr[i]-arr[j]) <= a && abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c) ans++;
                }
            }
        }
        return ans;
    }
};

// o(n^2)
class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int ans = 0;
            vector<int> sum(1002,0);
            for(int j=0; j<arr.size(); j++){
                for(int k=j+1; k<arr.size(); k++){
                    if(abs(arr[j]-arr[k]) <= b){
                        int l = max(0, max(arr[j] - a,arr[k] - c)), r = min(1000,min(arr[j] + a, arr[k] + c));
                        if(l <= r) ans += sum[r+1] - sum[l];
                    }
                }
                for(int i = arr[j]+1; i <= 1001; i++) ++sum[i];
            }
            return ans;
        }
    };