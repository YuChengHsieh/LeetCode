class Solution:
    def digitSum(self, s: str, k: int) -> str:
        if len(s) <= k : return s
        tmp_s = ''
        for i in range(0,len(s),k):
            num = 0
            for j in range(k):
                if i+j < len(s): num += int(s[i+j])
                else: break
            tmp_s += str(num)
        return self.digitSum(tmp_s,k)