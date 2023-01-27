# class Solution:
#     def findJudge(self, n: int, trust: list[list[int]]) -> int:
#         trust_dict = {}
#         judge_dict = {}
        
#         if n == 1 and len(trust) == 0:
#             return n
        
#         for trust_ in trust:
#             if trust_dict.get(trust_[0]) is None:
#                 trust_dict[trust_[0]] = True
#             if judge_dict.get(trust_[1]) is None:
#                 judge_dict[trust_[1]] = 0
#             judge_dict[trust_[1]] += 1

#         for i in range(n):
#             # judge potential (do not trust others) and everybody trust it
#             if trust_dict.get(i+1) is None and judge_dict.get(i+1) is not None and judge_dict[i+1] == n-1: 
#                 return i+1
#         # Did not find a judge
#         return -1

class Solution:
    def findJudge(self, n: int, trust: list[list[int]]) -> int:
        different_trust = [0 for _ in range(n+1)]
        for other,judge in trust:
            different_trust[other] -= 1
            different_trust[judge] += 1
        
        for i in range(len(different_trust)-1):
            if different_trust[i+1] == n-1:
                return i+1
        return -1
       

        
        
                
if __name__ == '__main__':
    a = Solution()
    print(a.findJudge(2,[[1,2]]))
    print(a.findJudge(3,[[1,3],[2,3]]))
    print(a.findJudge(4,[[1,3],[1,4],[2,3],[2,4],[4,3]]))
    print(a.findJudge(2,[]))
        