class Solution:
    def kSmallestPairs(self, nums1: list[int], nums2: list[int], k: int) -> list[list[int]]:
        import heapq
        pq = []
        for i in nums1:
            for j in nums2:
                if len(pq) == k:
                    val,comb = pq[0]
                    if -(i+j) > val:
                        heapq.heappop(pq)
                        heapq.heappush(pq,(-(i+j),[i,j]))
                    else:
                        break
                else:
                    heapq.heappush(pq,(-(i+j),[i,j]))
        ret = []
        for i in range(len(pq)):
            ret.insert(0,pq[i][1])
        return ret