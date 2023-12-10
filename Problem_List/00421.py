# explanation: https://leetcode.com/problems/maximum-strong-pair-xor-ii/
class Solution:
    def findMaximumXOR(self, nums: list[int]) -> int:
        ans = 0
        for i in range(31,-1,-1):
            ans <<= 1
            pre = {}
            for num in nums:
                tmp = num >> i
                if tmp not in pre: pre[tmp] = num
            
            for x in pre:
                y = ans^1^x
                if y in pre: ans |= 1
        
        return ans