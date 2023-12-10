class Solution:
    def numberOfGoodPartitions(self, nums: list[int]) -> int:
        mod = 10**9+7
        last_dict = { num:i for i,num in enumerate(nums) }
        power = rightest_idx = -1
        for i,num in enumerate(nums):
            if rightest_idx < i : power += 1
            rightest_idx = max(rightest_idx,last_dict[num])
        return 2**power%mod