# binary search
class Solution:
    def eatAll(self,k):
        cnt = 0
        for pile in self.piles:
            cnt += (pile-1)//k+1
        return cnt

    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        self.piles = piles
        self.h = h

        start = 1; end = max(self.piles)
        while start <= end:
            mid = start + (end-start)//2

            tmp_h = self.eatAll(mid)
            if tmp_h > h:
                start = mid+1
            else:
                end = mid-1
        
        return start
            