class Solution:
    def maxRunTime(self, n: int, batteries: list[int]) -> int:
        import numpy as np
        start,end = min(batteries), sum(batteries)//n

        while start <= end:
            mid = start+(end-start)//2
            if sum(min(mid,battery) for battery in batteries) >= mid*n:
                start = mid+1
            else:
                end = mid-1
        
        return end
