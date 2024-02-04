class Solution:
    def maxSubsequence(self, nums: list[int], k: int) -> list[int]:
        nums = [(num,i) for i,num in enumerate(nums)]
        nums.sort(key = lambda a: a[0])
        return list(zip(*sorted(nums[-k:],key = lambda a: a[-1])))[0]