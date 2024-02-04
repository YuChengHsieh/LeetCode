class Solution:
    def executeInstructions(self, n: int, startPos: list[int], s: str) -> list[int]:
        ans = []
        for i in range(len(s)):
            r = startPos[0]
            c = startPos[1]
            start,end = i,i
            while True:
                if r<0 or c<0 or r>=n or c>=n:
                    ans.append(end-start-1)
                    break
                elif end >= len(s):
                    ans.append(end-start)
                    break 

                if s[end] == 'L': c-=1
                elif s[end] == 'R': c+=1
                elif s[end] == 'U': r-=1
                elif s[end] == 'D': r+=1
                end += 1
        return ans