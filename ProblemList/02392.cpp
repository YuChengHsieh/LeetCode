#include <vector>
#include <map>
#include <set>
#include <queue>

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<int> deg_row(k+1,0), deg_col(k+1,0);
        vector<vector<int>> adj_row(k+1), adj_col(k+1);

        queue<int> row_q, col_q;
        for(auto& item: rowConditions){
            adj_row[item[0]].push_back(item[1]);
            deg_row[item[1]] += 1;
        }

        for(int i=1; i<=k; i++){
            if(deg_row[i] == 0) row_q.push(i);
        }

        for(auto& item: colConditions){
            adj_col[item[0]].push_back(item[1]);
            deg_col[item[1]] += 1;
        }

        for(int i=1; i<=k; i++){
            if(deg_col[i] == 0) col_q.push(i);
        }

        vector<int> row(k,0);
        for(int i=0; i<k; i++){
            if(row_q.empty()) return vector<vector<int>>();
            row[i] = row_q.front();
            row_q.pop();
            for(auto& val: adj_row[row[i]]){
                deg_row[val] -= 1;
                if(deg_row[val] == 0){
                    row_q.push(val);
                } 
            }
        }

        unordered_map<int,int> col;
        for(int i=0; i<k; i++){
            if(col_q.empty()) return vector<vector<int>>();
            int dest_val = col_q.front();
            col_q.pop();
            col[dest_val] = i;
            for(auto& val: adj_col[dest_val]){
                deg_col[val] -= 1;
                if(deg_col[val] == 0){
                    col_q.push(val);
                } 
            }
        }

        for(int i=0; i<k; i++){
            ans[i][col[row[i]]] = row[i];
        }
        return ans;
        
    }
};

using namespace std;
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));
        map<int,set<int>> from_row, to_row, from_col, to_col;

        queue<int> row_q, col_q;
        for(auto& item: rowConditions){
            from_row[item[0]].insert(item[1]);
            to_row[item[1]].insert(item[0]);
        }

        for(int i=1; i<=k; i++){
            if(!to_row.count(i)) row_q.push(i);
        }

        for(auto& item: colConditions){
            from_col[item[0]].insert(item[1]);
            to_col[item[1]].insert(item[0]);
        }

        for(int i=1; i<=k; i++){
            if(!to_col.count(i)) col_q.push(i);
        }

        vector<int> row(k,0);
        for(int i=0; i<k; i++){
            if(row_q.empty()) return vector<vector<int>>();
            row[i] = row_q.front();
            row_q.pop();
            for(auto& val: from_row[row[i]]){
                to_row[val].erase(row[i]);
                if(to_row[val].size() == 0){
                    to_row.erase(val);
                    row_q.push(val);
                } 
            }
        }

        unordered_map<int,int> col;
        for(int i=0; i<k; i++){
            if(col_q.empty()) return vector<vector<int>>();
            int dest_val = col_q.front();
            col_q.pop();
            col[dest_val] = i;
            for(auto& val: from_col[dest_val]){
                to_col[val].erase(dest_val);
                if(to_col[val].size() == 0){
                    to_col.erase(val);
                    col_q.push(val);
                } 
            }
        }

        for(int i=0; i<k; i++){
            ans[i][col[row[i]]] = row[i];
        }
        return ans;
        
    }
};