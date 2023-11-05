# use heap
import heapq
class Solution:
    def largestSumAfterKNegations(self, nums: list[int], k: int) -> int:
        pq = []
        for num in nums: heapq.heappush(pq,num)
        for i in range(k):
            val = heapq.heappop(pq)
            if val >= 0:
                if (k-i) % 2 == 1: val *= -1
                return val+sum(pq) 
            heapq.heappush(pq,val*-1)
        return sum(pq)
