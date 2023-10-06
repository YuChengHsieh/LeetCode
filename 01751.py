class Solution:
    def maxValue(self, events: list[list[int]], k: int) -> int:
        events.sort(key = lambda l: l[0])
        # memorization
        dp = [[-1 for _ in range(k)] for _ in range(len(events))]
        print(events)
        def BS(i,val):
            start,end = i,len(events)-1
            while start <= end:
                mid = start + (end-start)//2
                if val <= events[mid][0]:
                    end = mid-1
                else:
                    start = mid+1
            return start

        def rec(i,k):
            if i >= len(events) or k < 0: return 0
            if dp[i][k] != -1: return dp[i][k]
            # take
            ret1 = events[i][2]+rec(BS(i,events[i][1]+1),k-1)
            ret2 = rec(i+1,k)
            dp[i][k] = max(ret1,ret2)
            # print(i,k,ret1,ret2)
            return dp[i][k]
        
        return rec(0,k-1)