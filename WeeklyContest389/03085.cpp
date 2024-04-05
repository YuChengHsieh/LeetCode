#include<unordered_map>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution{
public:
    int minimumDeletions(string word, int k){
        unordered_map<int, int> dict;
        for(auto&ch: word) dict[ch] ++;
        vector<int> freq;
        for(auto& item: dict) freq.push_back(item.second);

        sort(freq.begin(), freq.end());
        int right = freq.back();
        int ans = INT_MAX;
        for(int left=1; left<=right; left++){
            int cnt = 0;
            for(auto& num: freq){
                if(num < left) cnt += num;
                else if(num > left+k)cnt += num - (left+k);
            }
            ans = min(ans,cnt);
        }
        return ans;
    }
};

// memorization
class Solution {
private:
    int rec(int left, int right, vector<pair<int,int>> vec, int k, vector<vector<int>>& mem){
        if(left == right || vec[right].first - vec[left].first <= k) return 0;
        if(mem[left][right] != -1) return mem[left][right];
        
        // cout << left << ' ' << right << endl;
        int ans = INT_MAX;
        ans = min(ans, rec(left+1,right,vec,k, mem) + vec[left].first*vec[left].second);
        // cout << ans << ' ';
        if(vec[right-1].first < k+vec[left].first) 
           {
                // cout << left << ' ' << right << ' ' << vec[right-1].first << ' ' << vec[right].first << ' ' << endl;
                ans = min(ans, (vec[right].first-(k+vec[left].first))*vec[right].second);
                // cout << ans << ' ';
           }
        else{
            int add_val = (vec[right].first - vec[right-1].first)*vec[right].second;
            vec[right-1].second += vec[right].second;
            ans = min(ans, rec(left,right-1,vec,k, mem) + add_val);
            // cout << ans << ' ';
        }
        
        
        mem[left][right] = ans;
        return ans;
        
    }
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        
        for(auto&ch :word){
            freq[ch-'a'] += 1;
        }
        
        map<int, int> dict;
        for(int i=0; i<26; i++){
            if(freq[i] != 0) dict[freq[i]] += 1;
        }
        
        vector<pair<int,int>> vec;
        for(auto&item: dict){
            vec.push_back({item.first, item.second});
            // cout << item.first << ' ' << item.second << endl;
        }
        
        vector<vector<int>> mem(vec.size(), vector<int>(vec.size(),-1));
        return rec(0, vec.size()-1, vec, k, mem);
        // return ans;
    }
};