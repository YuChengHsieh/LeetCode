import heapq
class Solution:
    def minInterval(self, intervals: list[list[int]], queries: list[int]) -> list[int]:
        # priority queue
        sorted_queries = sorted(queries)
        intervals = sorted(intervals,key = lambda a: a[0])[::-1]
        heap = []
        dict_ = {}
        for query in sorted_queries:
            # start <= query
            while intervals and intervals[-1][0] <= query:
                start,end = intervals.pop()
                heapq.heappush(heap,[end-start+1,end])
            # end < query
            while heap and heap[0][1] < query:
                heapq.heappop(heap)
            dict_[query] = -1 if len(heap) == 0 else heap[0][0]
        return [dict_[query] for query in queries]
