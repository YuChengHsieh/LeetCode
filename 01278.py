class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        mem = {}
        n = len(s)

        def check(head,tail):
            left = head; right = tail
            cnt = 0 
            while left < right:
                if s[left] != s[right]: cnt += 1
                left += 1; right -= 1
            return cnt

        def dp(head,k):
            if (head,k) in mem: return mem[(head,k)]
            if k == 1: 
                mem[(head,1)] = check(head,n-1)
                return mem[(head,1)]
            ans = n
            for tail in range(head,n-k+1):
                ans = min(ans,check(head,tail)+dp(tail+1,k-1))
            mem[(head,k)] = ans
            return mem[(head,k)]
        
        return dp(0,k)