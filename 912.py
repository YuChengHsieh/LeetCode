# use priority queue to sort
import heapq
class Solution:
    def sortArray(self, nums: list[int]) -> list[int]:
        # priority queue
        tmp = []
        ans = []
        for num in nums:
            heapq.heappush(tmp,num)
        for i in range(len(tmp)):
            ans.append(heapq.heappop(tmp))
        return ans