# binary search
class Solution:
    def blackbox(self,cpc):#candies per childern
        cnt = 0
        for candy in self.candies:
            cnt += candy//cpc
        return True if cnt >= self.k else False
    def maximumCandies(self, candies: list[int], k: int) -> int:
        self.candies = candies
        self.k = k

        start=0; end=max(candies)

        while start <= end:
            mid = start + (end-start)//2
            if mid == 0 or self.blackbox(mid):
                start = mid+1
            else:
                end = mid-1
        
        return end