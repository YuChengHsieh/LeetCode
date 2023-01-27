# BST
class Solution:
    def shipWithinDays(self, weights: list[int], days: int) -> int:
        self.weights = weights
        self.days = days
        start = max(weights)
        end = sum(weights)

        while start <= end:
            mid = start + (end-start)//2
            ret = self.check(mid)
            if ret:
                end = mid-1
            else:
                start = mid+1
        
        return start
    
    def check(self,capacity):
        days = 1
        size = 0
        for weight in self.weights:
            if size+weight>capacity:
                days += 1
                size = 0
            size += weight
        
        return False if days > self.days else True