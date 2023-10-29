class Solution:
    def minIncrementOperations(self, nums: list[int], k: int) -> int:
        n = len(nums)
        mem = [-1]*n

        def rec(idx):
            if idx < 2: return 0
            if mem[idx] != -1: return mem[idx]
            
            ans = float("inf")
            for i in range(3):
                if idx-i < 0: continue
                ans = min(ans,max(0,k-nums[idx-i])+rec(idx-i-1))
            mem[idx] = ans
            return mem[idx]
        return rec(n-1)
