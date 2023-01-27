# DP
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        minimum_opers = []
        word1_len = len(word1)+1
        word2_len = len(word2)+1
        for _ in range(word1_len):
            minimum_opers.append([0 for _ in range(word2_len)])
        # minimum_opers[i][j]: means that use minimum_opers[i][j] operations to make word1[:i] equals to word2[:j]
            
        for i in range(word1_len):
            for j in range(word2_len):
                if i == 0:
                    minimum_opers[i][j] = j
                elif j == 0:
                    minimum_opers[i][j] = i
                # make word1[:i] == word2[:j], we can choose minimum of three operations:
                # insert: needs minimum_opers[i][j-1]+1 operations
                # delete: needs minimum_opers[i-1][j]+1 operations
                # replace: 
                #   if word1[i-1] == word2[j-1] needs minimum_opers[i-1][j-1] operations
                #   else needs minimum_opers[i-1][j-1]+1 operations
                else:
                    replace = minimum_opers[i-1][j-1] if word1[i-1] == word2[j-1] else minimum_opers[i-1][j-1]+1
                    minimum_opers[i][j] = min(minimum_opers[i][j-1]+1,minimum_opers[i-1][j]+1,replace)

        return minimum_opers[word1_len-1][word2_len-1]

if __name__ == '__main__':
    a = Solution()
    print(a.minDistance("horse","ros"))
    print(a.minDistance("intention","execution"))