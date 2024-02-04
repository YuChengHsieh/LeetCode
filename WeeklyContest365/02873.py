class Solution:
    def maximumTripletValue(self, nums: list[int]) -> int:
        # monotonic stack
        maximum_num = 0
        maximum_diff = 0
        ans = 0
        for num in nums:
            maximum_num = max(maximum_num,num)
            ans = max(maximum_diff*num,ans)
            maximum_diff = max(maximum_diff,maximum_num-num)
        return ans
            