class Solution:
    def maxSubarrayLength(self, nums: list[int], k: int) -> int:
        dict_ = {}
        cur_len = max_len = 0
        left = 0
        for num in nums:
            if num not in dict_: dict_[num] = 0
            dict_[num] += 1
            # exceed             
            while dict_[num] > k:
                dict_[nums[left]] -= 1
                cur_len -= 1
                left += 1
        
            cur_len += 1
            max_len = max(cur_len,max_len)
        return max_len