import heapq
class Solution:
    def minimumDeviation(self, nums: list[int]) -> int:
        priority_queue = []
        min_ = float('inf')
        for i in range(len(nums)):
            if nums[i]%2 != 0:
                nums[i] *= 2
            # priority, small has higher priority
            heapq.heappush(priority_queue,-nums[i])
            if nums[i] < min_:
                min_ = nums[i]

        ret = float('inf')
        while True:
            # take from the largest val
            num = heapq.heappop(priority_queue)
            heapq.heappush(priority_queue, num//2)
            ret = min(ret, -num - min_)
            # check whether new insert val is smaller than min
            min_ = min(min_,-num//2)
            if num%2 != 0 :
                break
        
        return ret