class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        for i in range(int(len(x)//2)):
            if x[i] != x[-(i+1)]:
                return False
        return True
        
if __name__ == '__main__':
    sol = Solution()
    print(sol.isPalindrome(121))