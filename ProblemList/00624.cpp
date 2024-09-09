#include <vector>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<vector<int>> arr(2);
        arr[0] = {INT_MIN,-1,INT_MIN,-1};
        arr[1] = {INT_MAX,-1,INT_MAX,-1};

        for(int i=0; i<arrays.size(); i++){
            if(arrays[i].back() > arr[0][0]){
                arr[0][2] = arr[0][0];
                arr[0][3] = arr[0][1];
                arr[0][0] = arrays[i].back();
                arr[0][1] = i;
            }else if(arrays[i].back() > arr[0][2]){
                arr[0][2] = arrays[i].back();
                arr[0][3] = i;
            }

            if(arrays[i][0] < arr[1][0]){
                arr[1][2] = arr[1][0];
                arr[1][3] = arr[1][1];
                arr[1][0] = arrays[i][0];
                arr[1][1] = i;
            }else if(arrays[i][0] < arr[1][2]){
                arr[1][2] = arrays[i][0];
                arr[1][3] = i;
            }
        }
        return arr[0][1] == arr[1][1] ? max(arr[0][0] - arr[1][2], arr[0][2] - arr[1][0]) : arr[0][0] - arr[1][0];
    }
}; 