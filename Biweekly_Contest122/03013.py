# TLE
from numpy import inf
class Solution:
    def minimumCost(self, nums: list[int], k: int, dist: int) -> int:
        mem = {}
        
        def rec(i,take,first_take):
            if take == 0: return 0
            if i-first_take > dist: return inf
            if len(nums)-i < take: return inf
            if (i,take,first_take) in mem: return mem[(i,take,first_take)]
            
            
            min_val = inf
            # take
            min_val = min(min_val,nums[i]+rec(i+1,take-1, i if first_take == inf else first_take))
            # don't take
            min_val = min(min_val,rec(i+1,take,first_take))
            # print(rec(i+1,take-1, i if first_take == inf else first_take), rec(i+1,take,first_take), min_val)
            
            mem[(i,take,first_take)] = min_val
            return mem[(i,take,first_take)]
        
        a = rec(1,k,inf)+nums[0]
        
        return rec(1,k-1,inf)+nums[0]
            
            