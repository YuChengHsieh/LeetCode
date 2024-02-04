class Solution:
    def buildArray(self, target: list[int], n: int) -> list[str]:
        tar_cnt = 0
        i = 0
        n = len(target)
        ans = []
        while tar_cnt < n:
            ans.append('Push')
            i += 1
            if i == target[tar_cnt]: tar_cnt += 1
            else: ans.append('Pop')
        return ans

