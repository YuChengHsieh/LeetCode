# backtracking (TLE)
# class Solution:
#     def numDecodings(self, s: str) -> int:
#        self.result = 0
#        self.s = s
#        self.s_len = len(s)
#        self.rec(0,[])
#        return self.result
    
#     def rec(self,idx,tmp_list):
#         if idx == self.s_len:
#             print(tmp_list)
#             self.result += 1
#             return
#         tmp_str = ''
#         for i in range(idx,idx+2):
#             if i >= self.s_len or (i == idx and self.s[i] == '0'): return
#             if int(self.s[idx:i+1]) <= 26:
#                 tmp_str += self.s[i]
#                 tmp_list.append(tmp_str)
#                 self.rec(i+1,tmp_list)
#                 tmp_list.pop()
#         return

# DP
# class Solution:
#     def numDecodings(self, s: str) -> int:
#         s_len = len(s)
#         DP = [0 for i in range(s_len)]
#         # delete all str that start with 0
#         if s_len == 1 or s[0] == '0':
#             return 0 if s[0] == '0' else 1
#         DP[0] = 1
        
#         if s[1] == '0' and int(s[0]) >= 3:
#             return 0
#         DP[1] = 1 if int(s[:2]) > 26 or s[1] == '0' else 2

#         for i in range(2,s_len):
#             if s[i] == '0':
#                 if int(s[i-1]) >= 3 or int(s[i-1]) == 0: return 0
#                 else: DP[i] = DP[i-2]
#             else:
#                 DP[i] = DP[i-1] + DP[i-2] if int(s[i-1:i+1]) <= 26 and s[i-1] != '0' else DP[i-1]

#         return DP[s_len-1]

# integrate DP[1] into for loop
class Solution:
    def numDecodings(self, s: str) -> int:
        s_len = len(s)+1
        DP = [0 for _ in range(s_len)]
        DP[0] = 1
        # delete all str that start with 0
        if s_len-1 == 1 or s[0] == '0':
            return 0 if s[0] == '0' else 1
        # first position of s
        DP[1] = 1
        for i in range(1,s_len-1):
            if s[i] == '0':
                # only match of 0 if previous num is 1,2 (10,20)
                if int(s[i-1]) >= 3 or int(s[i-1]) == 0: return 0
                # 0 can not exist solely
                else: DP[i+1] = DP[i-1]
            else:
                # add DP[i-1] possible, eg.(2,3 can split into 2,3 or 23)
                DP[i+1] = DP[i] + DP[i-1] if int(s[i-1:i+1]) <= 26 and s[i-1] != '0' else DP[i]# just add it eg.(4,7 just 4,7 can not combine into 47)
        return DP[s_len-1]

class Solution:
    def numDecodings(self, s: str) -> int:
        if len(s) == 1: return 0 if s[0] == '0' else 1
        dp = [0 for _ in range(len(s)+1)]
        dp[0]=1; dp[1]= 0 if s[0] == '0' else 1
        for i in range(2,len(s)+1):
            dp[i] = 0 if s[i-1] == '0' else dp[i]+ dp[i-1]
            if int(s[i-2:i]) <= 26 and s[i-2] != '0': 
                dp[i] += dp[i-2]
        return dp[-1] 

if __name__ == '__main__':
    a = Solution()
    print(a.numDecodings('12'))
    print(a.numDecodings('2214'))
    print(a.numDecodings('101026'))
    print(a.numDecodings('226'))
    print(a.numDecodings('110003'))