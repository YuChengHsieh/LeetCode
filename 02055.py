class Solution:
    def platesBetweenCandles(self, s: str, queries: list[list[int]]) -> list[int]:
        # prefix sum
        n = len(s)
        prefix = [[0,-1,-1] for _ in range(n+1)]

        start_clost = -1
        for i,char in enumerate(s):
            prefix[i+1][0] = prefix[i][0]+1 if s[i] == '*' else prefix[i][0]
            if char == '|': start_clost = i+1
            prefix[i+1][1] = start_clost
        
        end_clost = n
        for i,char in enumerate(s[::-1]):
            if char == '|': end_clost = n-i
            prefix[n-i][2] = end_clost
        ans = []
        for start,end in queries:
            ans.append(max(0,\
            prefix[end+1][0]-prefix[start][0]-(end+1-prefix[end+1][1])-(prefix[start+1][2]-(start+1))))
        return ans