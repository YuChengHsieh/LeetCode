import heapq
class Solution:
    def maxTaxiEarnings(self, n: int, rides: list[list[int]]) -> int:
        rides.sort(key = lambda i: i[0])
        pq = []
        cur_earn = 0

        for start,end,tips in rides:
            while pq:
                prev_end, prev_earn = heapq.heappop(pq)
                if prev_end > start:
                    heapq.heappush(pq,(prev_end,prev_earn))
                    break
                cur_earn = max(cur_earn,prev_earn)
            heapq.heappush(pq,(end,cur_earn+end-start+tips))
        return max(cur_earn,*(list(zip(*pq))[1]))