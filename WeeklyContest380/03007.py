# binary search
class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        # binary search

        def check(num):
            price = 0
            for i in range(1,64):
                if i%x == 0:
                    price += num//(2**i)*2**(i-1) + max(num%(2**i)-2**(i-1)+1,0)
                if num < 2**i: break
            return price <= k

        start = 1; end = 10**15

        while start <= end:
            mid = start+(end-start)//2
            if check(mid): start = mid + 1
            else: end = mid - 1
        
        return end