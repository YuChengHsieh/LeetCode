class Solution:
    def partitionString(self, s: str) -> int:
        cnt = 1
        tmp_set = set()
        for char in s:
            if char in tmp_set:
                cnt += 1
                tmp_set = set()
            tmp_set.add(char)
        return cnt