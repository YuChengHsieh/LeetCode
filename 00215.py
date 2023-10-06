class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        import heapq
        ans = []
        for num in nums:
            heapq.heappush(ans,-num)
        
        for i in range(len(nums)):
            val = -heapq.heappop(ans)
            if i+1 == k:
                return val