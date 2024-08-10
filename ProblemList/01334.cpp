#include <vector>
using namespace std;
class Solution {
public:
    int inf = 100000000;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Floyd Warshall 
        vector<vector<int>> arr(n, vector<int>(n,inf));
        for(auto& edge: edges){
            arr[edge[0]][edge[1]] = min(arr[edge[0]][edge[1]],edge[2]);
            arr[edge[1]][edge[0]] = min(arr[edge[0]][edge[1]],edge[2]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(arr[j][i] + arr[i][k] < arr[j][k]) arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }

        int min_idx = -1, min_cnt = INT_MAX;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(i != j && arr[i][j] <= distanceThreshold) cnt += 1;
            }
            if(cnt <= min_cnt){
                min_cnt = cnt;
                min_idx = i;
            }
        }
        return min_idx;
    }
};