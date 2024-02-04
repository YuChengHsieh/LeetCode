from numpy import inf
class Solution:
    def maximumSubarraySum(self, nums: list[int], k: int) -> int:
        dict_ = {}
        n = len(nums)
        prefix = [0]*(n+1)
        
        max_sum = -inf
        for i in range(n):
            prefix[i+1] = prefix[i] + nums[i]
            
            if nums[i] not in dict_: 
                dict_[nums[i]] = i
            else: 
                dict_[nums[i]] = i if prefix[i] - prefix[dict_[nums[i]]] < 0 else dict_[nums[i]]
            
            if nums[i]-k in dict_: max_sum = max(max_sum,prefix[i+1]-prefix[dict_[nums[i]-k]])
            if nums[i]+k in dict_: max_sum = max(max_sum,prefix[i+1]-prefix[dict_[nums[i]+k]])
        return max_sum if max_sum != -inf else 0
        