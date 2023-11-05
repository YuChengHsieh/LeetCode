class Solution:
    def totalCost(self, costs: list[int], k: int, candidates: int) -> int:
        import heapq 
        pq = []
        cost_len = len(costs)
        if candidates*2 < cost_len:
            for i in range(candidates):
                heapq.heappush(pq,(costs[i],i))
                heapq.heappush(pq,(costs[-(i+1)],cost_len-i-1))
            cnt = 0
            front,back = candidates, cost_len-candidates-1
            for i in range(k):
                # print(pq)
                val,idx =  heapq.heappop(pq)
                # print(val,front,back)
                cnt += val
                if front <= back:
                    if idx < front:
                        heapq.heappush(pq,(costs[front],front))
                        front += 1
                    else:
                        heapq.heappush(pq,(costs[back],back))
                        back -= 1
        else:
            for i in range(cost_len):
                heapq.heappush(pq,(costs[i],i))
            cnt = 0

            for i in range(k):
                val,idx =  heapq.heappop(pq)
                cnt += val
        
        return cnt
