class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        mem = {}
        n = len(s)

        # check whether s[head:tail+1] is semi-palindrome
        def check(head,tail):
            length = tail-head+1
            best = n
            # divisor of length
            for d in range(1,length//2+1):
                if length%d != 0: continue
                change = 0
                # check how many changes we have to make from the definition of palindrome
                for i in range(d):
                    left = head+i
                    right = tail-d+i+1
                    while left < right:
                        if s[left] != s[right]: change += 1
                        left += d
                        right -= d
                best = min(best,change)
            return best
        def dp(head,k):
            if (head,k) in mem: return mem[(head,k)]
            # only one way
            if k == 1: 
                mem[(head,1)] = check(head,n-1)
                return mem[(head,1)]
            
            ans = n
            for tail in range(head+1,n-(k-1)*2):
                ans = min(ans, check(head,tail)+dp(tail+1,k-1))
            mem[(head,k)] = ans
            return mem[(head,k)]
        return dp(0,k)