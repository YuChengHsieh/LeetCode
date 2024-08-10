class Solution:
    def minimumAverage(self, nums: list[int]) -> float:
        n = len(nums)
        ans = 1000000000
        for i in range(n//2):
            min_val = min(nums)
            max_val = max(nums)
            nums.remove(min_val)
            nums.remove(max_val)
            ans = min(ans,(min_val+max_val)/2)
        return ans