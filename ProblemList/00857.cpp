#include <vector>
#include <queue>
using namespace std;

// priority queue

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({(double)wage[i]/(double)quality[i], quality[i]});
        }

        sort(arr.begin(), arr.end());
        priority_queue<int> pq;

        double ans;
        int quality_cnt = 0;
        for(int i=0; i<k; i++){
            quality_cnt += arr[i].second;
            pq.push(arr[i].second);
        }
        
        ans = arr[k-1].first*(double)quality_cnt;
        for(int i=k; i<n; i++){
            quality_cnt -= pq.top();
            pq.pop();

            quality_cnt += arr[i].second;
            pq.push(arr[i].second);
            ans = min(ans, arr[i].first*(double)quality_cnt);
        }

        return ans;
    }
};


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({quality[i], wage[i]});
        }

        sort(arr.begin(), arr.end());
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;

        double ans = INT_MAX, min_ratio = INT_MAX;
        int quality_cnt = 0, min_quality = 0, min_wage = 0;
        for(int i=0; i<k; i++){
            double ratio = (double)arr[i].first/(double)arr[i].second;
            if(ratio < min_ratio){
                min_ratio = ratio;
                min_quality = arr[i].first;
                min_wage = arr[i].second;
            }
            quality_cnt += arr[i].first;
            pq.push({ratio,i});
        }
        ans = min_wage*(double)quality_cnt/(double)min_quality;

        for(int i=k; i<n; i++){
            double ratio = (double)arr[i].first/(double)arr[i].second;
            auto [prev_ratio, index] = pq.top();
            pq.pop();
            quality_cnt -= arr[index].first;
            quality_cnt += arr[i].first;
            pq.push({ratio,i});
            auto [min_ratio, min_idx] = pq.top();
            ans = min(ans,(double)arr[min_idx].second*(double)quality_cnt/(double)arr[min_idx].first);
        }

        return ans;
    }
};