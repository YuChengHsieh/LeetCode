#include <vector>
using namespace std;
class neighborSum {
public:
    vector<vector<int>> graph;
    int m,n;
    neighborSum(vector<vector<int>>& grid) {
        graph = grid; 
        m = graph.size();
        n = graph[0].size();
    }
    
    int adjacentSum(int value) {
        int sum = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] == value){
                    if(i-1 >=0) sum += graph[i-1][j];
                    if(i+1 < m) sum += graph[i+1][j];
                    if(j-1 >=0) sum += graph[i][j-1];
                    if(j+1 < n) sum += graph[i][j+1];

                }
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] == value){
                    if(i-1 >=0 && j-1 >= 0) sum += graph[i-1][j-1];
                    if(i+1 < m && j-1 >= 0) sum += graph[i+1][j-1];
                    if(i-1 >= 0 && j+1 < n) sum += graph[i-1][j+1];
                    if(i+1 < m && j+1 < n) sum += graph[i+1][j+1];

                }
            }
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */