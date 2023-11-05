class Solution:
    def minSpeedOnTime(self, dist: list[int], hour: float) -> int:
        start,end = 1,10000001

        def check(mid):
            hour_taken = 0
            for num in dist[:-1]:
                hour_taken += (num-1)//mid+1
            else:
                hour_taken += dist[-1]/mid
            return True if hour_taken <= hour else False

        while start <= end:
            mid = start+(end-start)//2
            if check(mid):
                end = mid-1
            else:
                start = mid+1
        
        return -1 if mid == 10000001 else start