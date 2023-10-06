from collections import defaultdict
class Solution:
    def kWeakestRows(self, mat: list[list[int]], k: int) -> list[int]:
        hash = defaultdict(list)
        for i in range(len(mat)):
            hash[mat[i].count(1)].append(i)
        ans = []
        cnt = 0
        for i in range(len(mat[0])+1):
            for j in hash[i]:
                ans.append(j)
                cnt += 1
                if cnt == k:
                    return ans 