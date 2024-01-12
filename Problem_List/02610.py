class Solution:
    def findMatrix(self, nums: list[int]) -> list[list[int]]:
        ans = [set()]

        for num in nums:
            for li in ans:
                if num not in li: 
                    li.add(num)
                    break
            else:
                ans.append(set([num]))

        return ans