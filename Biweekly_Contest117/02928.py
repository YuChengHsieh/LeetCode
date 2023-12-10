#o(n)
class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        cnt = 0
        for i in range(1,min(n+1,limit+1)):
            if n > i*3: continue
            first = i
            remain = n-i
            if remain >= i:
                if remain == 2*first: cnt += 1
                else:
                    if remain%2 == 0: cnt += 3
                    cnt += 6*(i-(remain//2+1))
                    cnt += 3
            else:
                if remain%2 == 0: 
                    cnt += 3
                    cnt += 6*(remain//2)
                else:
                    cnt += 6*(remain//2+1)
        return cnt 
                
            
            