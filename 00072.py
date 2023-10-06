# DP
# class Solution:
#     def minDistance(self, word1: str, word2: str) -> int:
#         minimum_opers = []
#         word1_len = len(word1)+1
#         word2_len = len(word2)+1
#         for _ in range(word1_len):
#             minimum_opers.append([0 for _ in range(word2_len)])
#         # minimum_opers[i][j]: means that use minimum_opers[i][j] operations to make word1[:i] equals to word2[:j]
            
#         for i in range(word1_len):
#             for j in range(word2_len):
#                 if i == 0:
#                     minimum_opers[i][j] = j
#                 elif j == 0:
#                     minimum_opers[i][j] = i
#                 # make word1[:i] == word2[:j], we can choose minimum of three operations:
#                 # insert: needs minimum_opers[i][j-1]+1 operations
#                 # delete: needs minimum_opers[i-1][j]+1 operations
#                 # replace: 
#                 #   if word1[i-1] == word2[j-1] needs minimum_opers[i-1][j-1] operations
#                 #   else needs minimum_opers[i-1][j-1]+1 operations
#                 else:
#                     replace = minimum_opers[i-1][j-1] if word1[i-1] == word2[j-1] else minimum_opers[i-1][j-1]+1
#                     minimum_opers[i][j] = min(minimum_opers[i][j-1]+1,minimum_opers[i-1][j]+1,replace)

#         return minimum_opers[word1_len-1][word2_len-1]

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = [[0 for _ in range(len(word2)+1)] for _ in range(len(word1)+1)]

        sum_ = 1
        for i in range(len(word1)):
            dp[i+1][0] = sum_
            sum_ += 1
        
        sum_ = 1
        for i in range(len(word2)):
            dp[0][i+1] = sum_
            sum_ += 1

        for i in range(len(word1)):
            for j in range(len(word2)):
                if word1[i] == word2[j]: dp[i+1][j+1] = dp[i][j]
                else:
                    dp[i+1][j+1] = min(dp[i][j+1],dp[i+1][j],dp[i][j])+1 # delete, insert, replace 

        return dp[len(word1)][len(word2)]

# 1d
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = [0 for _ in range(len(word2)+1)]

        sum_ = 1
        for i in range(len(word2)):
            dp[i+1] = sum_
            sum_ += 1
        
        for i in range(len(word1)):
            cur = [dp[0]+1]
            for j in range(len(word2)):
                if word1[i] == word2[j]: cur.append(dp[j])
                else:
                    cur.append(min(dp[j+1],cur[j],dp[j])+1)
            dp = cur

        return dp[-1]

if __name__ == '__main__':
    a = Solution()
    print(a.minDistance("horse","ros"))
    print(a.minDistance("intention","execution"))