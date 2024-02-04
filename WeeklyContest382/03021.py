class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        if m > n: 
            tmp = n
            n = m
            m = tmp
        
        ans = 0
        
        for i in range(1,n+1):
            if(i%2 == 0):
                ans += (m+1)//2
            else:
                ans += m//2
        
        return ans

class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return ((m+1)//2)*(n//2) + (m//2)*((n+1)//2)