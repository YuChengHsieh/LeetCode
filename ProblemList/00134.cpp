#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // kadane's algorithm

        auto size = gas.size();
        for(int i=0; i<size; i++){
            gas[i] -= cost[i];
        }

        int sum = 0, first_sum = 0, max_sum = 0, idx = 0, start_idx = 0;
        for(int i=0; i<size; i++){
            sum += gas[i];
            if(gas[i] > sum){
                sum = gas[i];
                idx = i;
            }
            if(sum > max_sum){
                if(idx == 0) first_sum = sum;
                max_sum = sum;
                start_idx = idx;
            }
        }

        // circular calculate
        for(int i=0; i<size; i++){
            sum += gas[i];
            if(gas[i] > sum) break;
            if(sum > max_sum){
                max_sum = sum;
                start_idx = idx;
            }
        }
    
        idx = start_idx;
        sum = 0;
        for(int i=size; i>0; i--){
            sum += gas[idx];
            idx = (idx+1)%size;
            if(sum < 0) return -1;
        }
        return start_idx;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // kadane's algorithm
        auto size = gas.size();
        for(int i=0; i<size; i++){
            gas[i] -= cost[i];
        }

        int sum = 0, start_idx = 0;
        for(int i=0; i<size*2; i++){
            if(sum < 0){
                sum = 0;
                start_idx = i;
            }
            sum += gas[i%size];
            if(sum >= 0 && (i+1)%size == start_idx) return start_idx;

        }
        return -1;
    }
};