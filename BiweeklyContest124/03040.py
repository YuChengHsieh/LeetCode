# memorization
class Solution:
    def maxOperations(self, nums: list[int]) -> int:
        mem = {}
        def rec(score,tmp_nums):
            if len(tmp_nums) < 2: return 0
            if tuple(tmp_nums) in mem: return mem[tuple(tmp_nums)]
            
            ans = 0;
            # print(score,tmp_nums)
            if tmp_nums[0] + tmp_nums[1] == score:
                ans = max(ans, rec(score, tmp_nums[2:])+1)
            if tmp_nums[-2] + tmp_nums[-1] == score:
                ans = max(ans, rec(score, tmp_nums[:-2])+1)
            if tmp_nums[0] + tmp_nums[-1] == score:
                ans = max(ans, rec(score, tmp_nums[1:-1])+1)
            
            mem[tuple(tmp_nums)] = ans
            return ans
        
        return max(rec(nums[0]+nums[1],nums[2:]),rec(nums[0]+nums[-1],nums[1:-1]),rec(nums[-2]+nums[-1],nums[:-2])) +1
            