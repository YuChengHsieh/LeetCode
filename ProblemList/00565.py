class Solution:
    def arrayNesting(self, nums: list[int]) -> int:
        visited = set()
        ans = 0
        for i,num in enumerate(nums):
            cnt = 0
            while i not in visited:
                cnt += 1
                visited.add(i)
                i = nums[i]
            ans = max(ans,cnt)
        return ans