#include <vector>
using namespace std;
class Solution {
private:
    vector<int> MaxDist(vector<vector<int>>& A, int skip = -1){
        int N = A.size();

        vector<int> sum = {INT_MAX, INT_MIN}, sum_i = {0,0}, diff = {INT_MAX, INT_MIN}, diff_i = {0,0};
        
        int cnt = 0;
        for(int i=0; i<N; i++){
            if(i == skip) continue;
            
            if(A[i][0] + A[i][1] < sum[0]){
                sum[0] = A[i][0] + A[i][1];
                sum_i[0] = i;
            }

            if(A[i][0] + A[i][1] > sum[1]){
                sum[1] = A[i][0] + A[i][1];
                sum_i[1] = i;
            }

            if(A[i][0] - A[i][1] < diff[0]){
                diff[0] = A[i][0] - A[i][1];
                diff_i[0] = i;
            }

            if(A[i][0] - A[i][1] > diff[1]){
                diff[1] = A[i][0] - A[i][1];
                diff_i[1] = i;
            }

        }
        return (sum[1] - sum[0]) > (diff[1] - diff[0]) ? vector<int>({sum[1] - sum[0], sum_i[0], sum_i[1]}) 
                : vector<int>({diff[1] - diff[0], diff_i[0], diff_i[1]});

    }
public:
    int minimumDistance(vector<vector<int>>& points) {
        auto vec = MaxDist(points);
        return min(MaxDist(points,vec[1])[0],MaxDist(points,vec[2])[0]);
    }
};

// my solution, find the four corners: upper left, upper right, lower left, lower right
class Solution {
private:
    int MaxDist(vector<vector<int>>& A, vector<int>& del_pt)
    {
        int N = A.size();
        vector<int> V(N-1), V1(N-1);
        
        int cnt = 0;
        for(int i=0; i<N; i++){
            if(A[i][0] == del_pt[0] && A[i][1] == del_pt[1]){
                del_pt = {-1,-1};
                continue;
            } 
            V[cnt] = A[i][0] + A[i][1];
            V1[cnt] = A[i][0] - A[i][1];
            cnt += 1;
        }

        sort(V.begin(), V.end());
        sort(V1.begin(), V1.end());

        int maximum
            = max(V.back() - V.front(), V1.back() - V1.front());
        return maximum;
    }
public:
    int minimumDistance(vector<vector<int>>& points) {
        vector<vector<int>> corners;
        int max_val = pow(10,8)+1;
        // upper_left
        vector<int> upper_left = {max_val,0};
        vector<int> upper_right = {0,0};
        vector<int> lower_left = {max_val,max_val};
        vector<int> lower_right = {0,max_val};
        for(auto& point: points){
            if(point[1] - point[0] > upper_left[1] - upper_left[0]) upper_left = point;
            if(point[1] + point[0] > upper_right[1] + upper_right[0]) upper_right = point;
            if(point[1] + point[0] < lower_left[1] + lower_left[0]) lower_left = point;
            if(point[1] - point[0] < lower_right[1] - lower_right[0]) lower_right = point;
        }
        corners = {upper_left,upper_right,lower_left,lower_right};
        
        int min_dis = INT_MAX;
        for(int i=0; i<corners.size(); i++){
            int max_dis = MaxDist(points,corners[i]);
            min_dis = min(min_dis, max_dis);
        }
        return min_dis;
    }
};