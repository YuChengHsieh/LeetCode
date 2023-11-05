# use heap
import heapq
class Solution:
    def constrainedSubsetSum(self, nums: list[int], k: int) -> int:
        n = len(nums)
        dp = [0]*n
        pq = []
        for i in range(n):
            prev = 0
            while len(pq) != 0:
                val,idx = heapq.heappop(pq)
                if i-idx <=k: 
                    prev = -val
                    heapq.heappush(pq,(val,idx))
                    break
            dp[i] = max(0,prev)+nums[i]
            heapq.heappush(pq,(-dp[i],i))
        return max(dp)

# use deque
import collections
class Solution:
    def constrainedSubsetSum(self, nums: list[int], k: int) -> int:
        n = len(nums)
        deque = collections.deque()
        
        for i in range(n):
            nums[i] += deque[0] if deque else 0
            while len(deque) and deque[-1] < nums[i]: deque.pop()
            if nums[i] > 0: deque.append(nums[i])
            if i >= k and len(deque) and deque[0] == nums[i-k]: deque.popleft()
        return max(nums)


