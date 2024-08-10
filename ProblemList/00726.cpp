#include <string>
#include <map>
#include <stack>
using namespace std;

// stack solution
class Solution {
public:
    void count(string& atom, string& cnt, map<string,int>& mp, map<string,int>& prev_mp){  
        int cnt_int = cnt.size() == 0 ? 1: stoi(cnt);
        if(atom.size() == 0) return;
        else if(atom == "map!"){
            for(auto& item: prev_mp){
                mp[item.first] += item.second*cnt_int;
            }
        }else mp[atom] += cnt_int;
        cnt = "";
        atom = "";
        prev_mp = map<string,int>();
    }
    string countOfAtoms(string formula) {
        stack<map<string,int>> st;
        st.push(map<string,int>());
        map<string,int> prev_mp;
        string atom, cnt;
        for(auto& ch: formula){
            if(ch == '('){
                count(atom,cnt,st.top(),prev_mp);
                st.push(map<string,int>());
            }else if(ch == ')'){
                count(atom,cnt,st.top(),prev_mp);
                auto top_mp = st.top();
                st.pop();
                prev_mp = top_mp;
                atom = "map!";
            }else if(isdigit(ch)){
                cnt += ch; 
            }else if(islower(ch)){
                atom += ch;
            }else if(isupper(ch)){
                count(atom,cnt,st.top(),prev_mp);
                atom = ch;
            }
        }
        count(atom,cnt,st.top(),prev_mp);

        string ans;
        auto global_mp = st.top();
        for(auto& item: global_mp){
            ans += item.first + (item.second == 1 ? "" : to_string(item.second));
        }
        return ans;
    }
};

// recursion solution
class Solution {
private:
    void count(string atom, string cnt, map<string,int>& mp, map<string,int>& ret_mp){
        int cnt_int = cnt.size() == 0 ? 1: stoi(cnt);
        if(atom.size() == 0) return;
        else if(atom == "map!"){
            for(auto& item: ret_mp){
                mp[item.first] += item.second*cnt_int;
            }
        }else mp[atom] += cnt_int;
    }
    pair<map<string,int>,int> rec(int idx, string& s){
        map<string,int> mp;
        map<string,int> ret_mp;
        string atom,cnt;
        while(idx < s.size()){
            if(s[idx] == '('){
                count(atom,cnt,mp,ret_mp);
                auto [ret_map, cur_idx] = rec(idx+1,s);
                idx = cur_idx;
                ret_mp = ret_map;
                atom = "map!";
                cnt = "";
            }else if(s[idx] == ')'){
                count(atom,cnt,mp,ret_mp);
                return {mp,idx};
            }else if(isdigit(s[idx])){
                cnt += s[idx]; 
            }else if(islower(s[idx])){
                atom += s[idx];
            }else if(isupper(s[idx])){
                count(atom,cnt,mp,ret_mp);
                cnt = "";
                atom = s[idx];
            }
            idx += 1;
        }
        count(atom,cnt,mp,ret_mp);
        return {mp,idx};
    }
public:
    string countOfAtoms(string formula) {
        auto [mp, idx] = rec(0,formula);
        string ans;
        for(auto& item: mp){
            ans += item.first + (item.second == 1 ? "" : to_string(item.second));
        }
        return ans;
    }
};