class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        n = len(nums)
        neg = []; pos = []
        for num in nums:    
            if num > 0:
                pos.append(num)
            else:
                neg.append(num)
        ans = []
        for i in range(len(pos)):
            ans.append(pos[i])
            ans.append(neg[i])
        return ans