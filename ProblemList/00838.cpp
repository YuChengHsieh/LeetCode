#include <string>
#include <vector>
using namespace std;

// optimized solution o(n)
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n,0);
        int f = 0;
        for(int i=0; i<dominoes.size(); i++){
            if(dominoes[i] == 'R') f = n;
            else if(dominoes[i] == 'L') f = 0;
            else f = max(f-1,0);
            forces[i] += f;
        }

        for(int i=dominoes.size()-1; i>=0; i--){
            if(dominoes[i] == 'L') f = n;
            else if(dominoes[i] == 'R') f = 0;
            else f = max(f-1,0);
            forces[i] -= f;
        }

        for(int i=0; i<dominoes.size(); i++){
            dominoes[i] = forces[i] > 0 ? 'R' : forces[i] < 0 ? 'L' : '.';
        }
        return dominoes;
    }
};

// brutal force o(n^2)
class Solution {
    public:
        string pushDominoes(string dominoes) {
            int l_idx = -1, r_idx = -2;
            for(int i=0; i<dominoes.size(); i++){
                if(dominoes[i] == 'R'){
                    if(r_idx > l_idx){
                        for(int k=r_idx+1; k<i; k++){
                            dominoes[k] = 'R';
                        }
                    }
                    r_idx = i;
                } 
                else if(dominoes[i] == 'L'){
                    if(l_idx > r_idx){
                        for(int k=l_idx+1; k<i; k++){
                            dominoes[k] = 'L';
                        }
                    }else{
                        int total = i-r_idx-1, cnt = 0;
                        for(int k=0; k<total/2; k++){
                            dominoes[r_idx+k+1] = 'R';
                        }
                        for(int k=0; k<total/2; k++){
                            dominoes[i-k-1] = 'L';
                        }
                    }
                    l_idx = i;
                }
            }
            if(r_idx > l_idx){
                for(int k=r_idx+1; k<dominoes.size(); k++){
                    dominoes[k] = 'R';
                }
            }
            return dominoes;
        }
    };