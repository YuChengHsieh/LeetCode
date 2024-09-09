#include <vector>
#include <queue>
using namespace std;

// binary search
class KthLargest {
public:
    vector<int> arr;
    int kth;
    void bs(int val){
        int start = 0, end = arr.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(val > arr[mid]) start = mid + 1;
            else end = mid - 1;
        }
        arr.insert(arr.begin()+start,val);
    }
    KthLargest(int k, vector<int>& nums): kth(k), arr(nums) {
        sort(arr.begin(), arr.end());
    }
    
    int add(int val) {
        bs(val);
        return arr[arr.size()-kth];
    }
};

// min heap
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
    KthLargest(int k, vector<int>& nums): kth(k){
        sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
        int idx = 0;
        while(pq.size() < k && nums.size() > idx){
            pq.push(nums[idx]);
            idx ++;
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > kth) pq.pop();
        pq.top();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */