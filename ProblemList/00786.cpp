#include <vector>
#include <queue>
using namespace std;

// binary search 31 ms, klogk
class Solution {
private:
    vector<int> check(double mid, vector<int>& arr){
        int total = 0, n = arr.size(), no, de;
        double max_frac = 0.0;
        for(int i=0; i<n; i++){
            int j = 0;
            for(; j < i && (double)arr[j] <= (double)arr[i]*mid; j++){
            }
            total += j;
            if(j-1 >= 0 && j-1 < i && (double)arr[j-1]/(double)arr[i] > max_frac){
                max_frac = (double)arr[j-1]/(double)arr[i];
                no = arr[j-1];
                de = arr[i];
            }
        }
        return {total,no,de};
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double start = 0.0, end = 1.0;
        while(start < end){
            double mid = (start+end)/2.0;
            vector<int> ret = check(mid, arr);
            if(ret[0] == k) return {ret[1], ret[2]};
            else if(ret[0] < k) start = mid;
            else end = mid;
        }
        return {};
    }
};

// priority queue 1505 ms, n^2logn
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> pq;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                pq.push({(double)arr[i]/(double)arr[j],(double)arr[i],(double)arr[j]});
            }
        }

        for(int i=0; i<k-1; i++){
            pq.pop();
        }
        vector<double> ans = pq.top();
        return {(int)ans[1], (int)ans[2]};
    }
};

// priority queue 238 ms, nlogn
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int,int>>, vector<pair<double, pair<int,int>>>, greater<pair<double, pair<int,int>>>> pq;
        for(int i=0; i<arr.size(); i++){
            pq.push({(double)arr[0]/(double)arr[i],{0,i}});
        }

        for(int i=0; i<k-1; i++){
            auto [val, ret] = pq.top();
            pq.pop();
            pq.push({(double)arr[ret.first+1]/(double)arr[ret.second] , {ret.first+1,ret.second}});
        }
        auto [val, ret] = pq.top();
        return {arr[ret.first], arr[ret.second]};
    }
};