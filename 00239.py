from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        deq = deque()
        right = left = 0
        ans = []
        while right < len(nums):
            while len(deq) != 0 and nums[right] > nums[deq[-1]]: deq.pop()
            deq.append(right)
            
            if left > deq[0]: deq.popleft()

            if right+1 >= k: 
                ans.append(nums[deq[0]])
                left += 1
            right += 1
        return ans