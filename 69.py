# BST
class Solution:
    def mySqrt(self, x: int) -> int:
        if x ==1:
            return 1
        start = 0
        end = x//2
        
        while start < end:
            mid = (start+end+1)//2
            if x > mid**2:
                start = mid
            elif x < mid **2:
                end = mid-1
            else:
                return mid

        return start

if __name__ == '__main__':
    a = Solution()
    print(a.mySqrt(4))
    print(a.mySqrt(8))
    print(a.mySqrt(16))
            

        