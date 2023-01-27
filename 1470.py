class Solution:
    def shuffle(self, nums: list[int], n: int) -> list[int]:
        nums_len = len(nums)
        ans = [0 for _ in range(nums_len)]
        num_cnt = 0
        for i in range(0,nums_len,2):
            ans[i] = nums[num_cnt]
            ans[i+1] = nums[n+num_cnt]
            num_cnt += 1
        return ans
