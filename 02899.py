# while
class Solution:
    def lastVisitedIntegers(self, words: list[str]) -> list[int]:
       # stack
        ans = []
        li = []
        i = 0
        n = len(words)
        while i < n:
            cnt = 1
            while i < n and words[i] == 'prev':
                if cnt <= len(li):
                    ans.append(li[len(li)-cnt])
                    cnt += 1
                else:
                     ans.append(-1)
                i += 1
            if i >= n: break
            li.append(int(words[i]))
            i += 1
                    
                
        return ans