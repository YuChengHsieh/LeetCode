#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
private:
    bool isPrime(int n) {
        if (n < 10) return false;
        if (n % 2 == 0) return false;

        int sqrtN = std::sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        vector<vector<int>> dirs {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
        unordered_map<int,int> prime_cnt;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                for(auto& d: dirs){
                    int tmp_i = i, tmp_j = j;
                    int di = d[0], dj = d[1];
                    string s;
                    s += mat[i][j]+'0';
                    while(tmp_i+di >=0 && tmp_i+di < mat.size() && tmp_j+dj >= 0 && tmp_j+dj < mat[0].size()){
                        tmp_i += di; tmp_j += dj;
                        // cout << tmp_i << ' ' << tmp_j << endl;
                        s += mat[tmp_i][tmp_j]+'0';
                        int num = stoi(s);
                        // cout << num << endl;
                        if(isPrime(num)) prime_cnt[num] += 1;
                    }
                    
                }
                
            }
        }
        
        int max_val = 0; int max_num = -1;
        for(auto& item: prime_cnt){
            // cout << item.first << ' ' << item.second << endl;
            if(item.second > max_val || (item.second == max_val && item.first > max_num)){
                max_num = item.first;
                max_val = item.second;
            }
        }
        return max_num;
    }
};