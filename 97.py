# o(n) sliding window (WA)
# class Solution:
#     def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
#         s1_idx = s2_idx = s3_idx = 0
#         s1_len = len(s1)
#         s2_len = len(s2)
#         first = True
#         while s1_idx < s1_len and s2_idx < s2_len:
#             if s1[s1_idx] == s3[s3_idx] and s2[s2_idx] == s3[s3_idx]:
#                 if first == True:
#                     record_idx = s3_idx
#                     first = False 
#                 s1_idx += 1
#                 s2_idx += 1
#             elif s1[s1_idx] == s3[s3_idx]:
#                 if not first:
#                     s2_idx -= s3_idx - record_idx
#                     first = True
#                 s1_idx += 1
#             elif s2[s2_idx] == s3[s3_idx]:
#                 if not first:
#                     s1_idx -= s3_idx - record_idx
#                     first = True
#                 s2_idx += 1
#             else:
#                 return False
#             s3_idx += 1
#         # s1 not finish
#         if s1_idx < s1_len:
#             if not first:
#                 s1_idx -= s3_idx - record_idx
#             return s3[s3_idx:] == s1[s1_idx:]
#         else:# s2 not finish
#             if not first:
#                 s2_idx -= s3_idx - record_idx
#             return s3[s3_idx:] == s2[s2_idx:]

# DP
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1)+len(s2) != len(s3):
            return False

        s1_len = len(s1)+1; s2_len = len(s2)+1
        # DP[i][j] means if we can s1[:i] + s2[:j] to construct s3[:i+j]
        DP = [[False]*(s2_len) for _ in range(s1_len)]
        DP[0][0] = True

        # only use s1
        for i in range(1,s1_len):
            DP[i][0] = DP[i-1][0] and s1[i-1] == s3[i-1]
            if DP[i][0] == False:
                break
        # only use s2
        for j in range(1,s2_len):
            DP[0][j] = DP[0][j-1] and s2[j-1] == s3[j-1] 
            if DP[0][j] == False:
                break
        for i in range(1,s1_len):
            for j in range(1,s2_len):
                DP[i][j] = (DP[i-1][j] and s1[i-1] == s3[i+j-1]) or\
                        (DP[i][j-1] and s2[j-1] == s3[i+j-1])
        print(DP)
        return DP[s1_len-1][s2_len-1]

if __name__ == '__main__':
    a = Solution()
    print(a.isInterleave("aabcc","dbbca","aadbbcbcac"))
