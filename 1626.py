# DP
class Solution:
    def bestTeamScore(self, scores: list[int], ages: list[int]) -> int:
        # follow age to sort, if age is the same, use score to sort
        sorted_score = [x for x,_ in sorted(zip(scores,ages),key=lambda i: (i[1],i[0]))]
        len_ = len(scores)
        DP = [0 for _ in range(len_)]
        DP[0] = sorted_score[0]
        for i in range(1,len_):
            max_ = 0
            # search from previous indice that can maximize the score if use i as the last chose element
            for j in range(0,i):
                if DP[j] > max_ and sorted_score[i] >= sorted_score[j]:
                    max_ = DP[j]
            DP[i] = max_+sorted_score[i]
        return max(DP)

if __name__ == '__main__':
    a = Solution()
    print(a.bestTeamScore([1,3,5,10,15],[1,2,3,4,5]))
    print(a.bestTeamScore([4,5,6,5],[2,1,2,1]))
    print(a.bestTeamScore([1,2,3,5],[8,9,10,1]))
    print(a.bestTeamScore([5,6,1,2],[1,2,3,4]))
    print(a.bestTeamScore([319776,611683,835240,602298,430007,574,142444,858606,734364,896074],[1,1,1,1,1,1,1,1,1,1]))