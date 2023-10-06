class Solution:
    def getRow(self, rowIndex: int) -> list[int]:
        prev = [1]
        cur = [1]
        for i in range(1,rowIndex+1):
            cur = [1]
            for j in range(1,i):
                cur.append(prev[j-1]+prev[j])
            cur.append(1)
            prev = cur
        return cur