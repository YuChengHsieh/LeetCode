class Solution:
    def maximumStrongPairXor(self, nums: list[int]) -> int:
        ans = 0
        for i in range(20,-1,-1):
            ans <<= 1
            pre = {}; pre2 = {}
            for num in nums:
                tmp = num >> i
                if tmp not in pre: pre[tmp] = pre2[tmp] = num
                pre[tmp] = min(num,pre[tmp])
                pre2[tmp] = max(num,pre2[tmp])
            for x in pre:
                y = ans^1^x
                if x >= y and y in pre and pre[x] <= pre2[y]*2 : 
                    ans |= 1
                    break
        return ans