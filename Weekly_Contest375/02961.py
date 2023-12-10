class Solution:
    def getGoodIndices(self, variables: list[list[int]], target: int) -> list[int]:
        ans = []
        
        for i in range(len(variables)):
            a,b,c,m = variables[i]
            val = a
            val %= 10
            for j in range(b-1):
                val *= a
                val %= 10
            
            d = val
            val %= m
            for j in range(c-1):
                val *= d
                val %= m
            if val == target: ans.append(i)
        return ans