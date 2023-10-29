class Solution:
    def findKOr(self, nums: list[int], k: int) -> int:
        cnt = 0
        n = len(nums)
        i = 1
        max_num = max(nums)
        ans = 0
        while i <= max_num:
            cnt = 0
            for num in nums:
                if i & num == i: cnt += 1
            if cnt >= k: ans += i
            i <<= 1
        return ans