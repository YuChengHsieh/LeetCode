# Binary Search
class Solution:
    def jobScheduling(self, startTime: list[int], endTime: list[int], profit: list[int]) -> int:
        jobs = [(i,j,k) for i,j,k in zip(startTime,endTime,profit)]
        jobs.sort(key=lambda i: (i[0],i[1]))

        sorted_list = []
        cur_max = 0

        def BS(val):
            start = 0; end = len(sorted_list)-1
            while start <= end:
                mid = start+(end-start)//2
                if sorted_list[mid][0] <= val: start = mid+1
                else: end = mid-1
            return start

        for start,end,profit in jobs:
            del_idx = BS(start)
            if del_idx != 0:
                cur_max = max(cur_max,*(list(zip(*sorted_list[:del_idx]))[1]))
            sorted_list = sorted_list[del_idx:]
            insert_idx = BS(end)
            sorted_list.insert(insert_idx,(end,cur_max+profit))
        return max(cur_max,*(list(zip(*sorted_list))[1]))

# Heap
import heapq
class Solution:
    def jobScheduling(self, startTime: list[int], endTime: list[int], profit: list[int]) -> int:
        jobs = [(i,j,k) for i,j,k in zip(startTime,endTime,profit)]
        jobs.sort(key=lambda i: (i[0],i[1]))
        
        pq = []
        cur_max = 0
        for start,end,profit in jobs:
            while pq:
                prev_end,prev_profit = heapq.heappop(pq)
                if prev_end > start:
                    heapq.heappush(pq,(prev_end,prev_profit))
                    break
                cur_max = max(cur_max,prev_profit)
            heapq.heappush(pq,(end,cur_max+profit))
        return max(cur_max,*(list(zip(*pq))[1]))
