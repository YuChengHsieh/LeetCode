#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Solution {
    private:
        vector<int> findAllPrimes(int limit){
            vector<int> primes;
            vector<bool> check(limit+1,true);
            for(int i=2; i*i<=limit; i++){
                if(check[i]){
                    for(int j=i*i; j<=limit; j+=i){
                        check[j] = false;
                    }
                }
            }
            for(int i=2; i<=limit; i++){
                if(check[i]) primes.push_back(i);
            }
    
            return primes;
        }
    
        long long modPower(long long a, long long b) {
            long long result = 1;  // Initialize result
            int m = 1e9+7;
            a = a % m;  // Handle large a values by reducing modulo m early
    
            while (b > 0) {
                // If b is odd, multiply the result with the current base a
                if (b % 2 == 1) {
                    result = (result * a) % m;
                }
    
                // Square a and reduce modulo m
                a = (a * a) % m;
    
                // Divide b by 2
                b /= 2;
            }
            return result;
        }
    public:
        int maximumScore(vector<int>& nums, int k) {
            int n = nums.size();
            int max_val = 0;
            for(auto& num: nums) max_val = max(max_val, num);
            // calculate primes
            vector<int> primes = findAllPrimes(max_val);
    
            // calculate prime scores
            vector<int> prime_scores;
            for(auto num: nums){
                int idx = 0, prime_score = 0;
                while(idx < primes.size() && primes[idx]*primes[idx] < num){
                    if(num%primes[idx] == 0) prime_score ++;
                    while(num%primes[idx] == 0) num/= primes[idx];
                    idx ++;
                }
                prime_scores.push_back(num > 1 ? ++prime_score : prime_score);
            }
    
            // monotonic stack 
            vector<int> left_bound(n,-1);
            vector<int> right_bound(n,n);
            
            stack<int> st;
            for(int i=0; i<n; i++){
                while(!st.empty() && prime_scores[st.top()] < prime_scores[i]){
                    right_bound[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
            while(!st.empty()){
                right_bound[st.top()] = n;
                st.pop();
            }
    
            for(int i=n-1; i>=0; i--){
                while(!st.empty() && prime_scores[st.top()] <= prime_scores[i]){
                    left_bound[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
            while(!st.empty()){
                left_bound[st.top()] = -1;
                st.pop();
            }
    
            // for(auto& i: prime_scores) cout << i << ' ';
            // cout << endl;
            // for(auto& i: left_bound) cout << i << ' ';
            // cout << endl;
            // for(auto& i: right_bound) cout << i << ' ';
            // cout << endl;
    
            priority_queue<pair<int,int>> pq;
            long long ans = 1;
            int mod = 1e9+7;
            for(int i=0; i<n; i++){
                pq.push({nums[i],i});
            } 
    
            while(!pq.empty()){
                auto [num,idx] = pq.top();
                pq.pop();
                long long add = (long long)(idx-left_bound[idx])*(long long)(right_bound[idx]-idx);
                ans = (ans*modPower(num,min((long long)k,add)))%mod;
                k -= add;
                if(k <= 0) break; 
            }
    
            return (int)ans%mod;
        }
    };