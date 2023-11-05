class Solution:
    def minOperations(self, nums: list[int], k: int) -> int:
        visited = set()
        for i,num in enumerate(nums[::-1],1):
            if num <= k: visited.add(num)
            if len(visited) == k: return i