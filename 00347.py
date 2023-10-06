class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        import heapq
        cnt = {}
        for num in nums:
            if not cnt.get(num): cnt[num] = 0
            cnt[num] += 1
        
        heap = []
        for key,val in cnt.items():
            heap.append((key,val))
        heap.sort(key = lambda x: x[1])
        return list(zip(*heap))[0][-k:] 