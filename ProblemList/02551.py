# priority queue
class Solution:
    def putMarbles(self, weights: list[int], k: int) -> int:
        import heapq
        cnt = []
        
        for i in range(len(weights)-1):
            heapq.heappush(cnt,weights[i]+weights[i+1])
        max_,min_ = 0,0
        for i in range(len(weights)-1):
            val = heapq.heappop(cnt)
            if i < k-1:
                min_ += val
            if i >= len(weights)-1-(k-1):
                max_ += val
        return max_ - min_

# sort
class Solution:
    def putMarbles(self, weights: list[int], k: int) -> int:
        cnt = []
        for i in range(len(weights)-1):
            cnt.append(weights[i]+weights[i+1])
        
        cnt.sort()
        return 0 if k == 1 else sum(cnt[-(k-1):]) - sum(cnt[:k-1]) 
