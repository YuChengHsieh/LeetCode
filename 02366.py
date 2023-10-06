class Solution:
    def minimumReplacement(self, nums: list[int]) -> int:
        cnt = 0
        prev_bound = nums[-1]

        for num in nums[:-1][::-1]:
           num_op = (num+prev_bound-1)//prev_bound
           cnt += num_op-1
           prev_bound = num//num_op
        
        return cnt