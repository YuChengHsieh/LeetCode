#include <iostream>
#include <vector>
using namespace std; 
class Solution {
private:
    bool mem [41][41][2000];
    vector<int> possible_length(string num_str){
        vector<int> combinations;
        if(num_str.size() == 1) combinations.push_back(stoi(num_str));
        else if(num_str.size() == 2){
            combinations.push_back(stoi(num_str));
            cout << stoi(num_str) << endl;
            combinations.push_back(int(num_str[0])-'0'+int(num_str[1])-'0');
        }else{
            combinations.push_back(stoi(num_str));
            combinations.push_back(int(num_str[0])-'0'+int(num_str[1])-'0'+int(num_str[2])-'0');
            combinations.push_back(stoi(num_str.substr(0,2))+int(num_str[2])-'0');
            combinations.push_back(int(num_str[0])-'0'+stoi(num_str.substr(1,2)));
        }
        return combinations;
    }
    bool recurse(string s1, string s2, int idx1, int idx2, int diff){
        int s1_size = s1.size(), s2_size = s2.size();
        if(idx1 == s1_size && idx2 == s2_size) return diff == 0;
        if(mem[idx1][idx2][diff+1000]) return false;
        mem[idx1][idx2][diff+1000] = true;

        if(idx1 < s1_size && isdigit(s1[idx1])){
            int next_idx1 = idx1+1;
            while( next_idx1 < s1_size && isdigit(s1[next_idx1])) next_idx1 += 1;
            vector<int> combinations1 = possible_length(s1.substr(idx1,next_idx1 - idx1));
            for(auto & comb : combinations1){
                if(recurse(s1,s2,next_idx1,idx2,diff-comb)) return true;
            }
        }else if(idx2 < s2_size && isdigit(s2[idx2])){
            int next_idx2 = idx2+1;
            while(next_idx2 < s2_size && isdigit(s2[next_idx2])) next_idx2 += 1;
            vector<int> combinations2 = possible_length(s2.substr(idx2,next_idx2 - idx2));
            for(auto & comb : combinations2){
                if(recurse(s1,s2,idx1,next_idx2,diff+comb)) return true;
            }
        }else if(diff > 0){
            if (idx1 < s1_size) return recurse(s1,s2,idx1+1,idx2,diff-1);
        }else if(diff < 0 && idx2 < s2_size){
            if (idx2 < s2_size) return recurse(s1,s2,idx1,idx2+1,diff+1);
        }else{
            if(idx1 < s1_size && idx2 < s2_size && s1[idx1] == s2[idx2]) return recurse(s1,s2,idx1+1,idx2+1,diff);
        }
        return false;
    }

public:
    bool possiblyEquals(string s1, string s2) {
        return recurse(s1,s2,0,0,0);
    }
};