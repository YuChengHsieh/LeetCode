# class Solution:
#     def myPow(self, x: float, n: int) -> float:
#         if n == 0:
#             return 1
#         elif n == 1:
#             return x
#         elif n == -1:
#             return 1/x
        
#         val = self.myPow(x,n//2)*self.myPow(x,n//2)
#         if n%2==1:
#             val *= x
        
#         return val

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        elif n == 1:
            return x
        elif n == -1:
            return 1/x
        
        if n%2 == 0:
            return self.myPow(x*x,n//2)
        else:
            return x*self.myPow(x*x,n//2)
        

if __name__ == '__main__':
    a = Solution()
    print(a.myPow(2,-2))
    