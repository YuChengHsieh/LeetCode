# first trial
# sort ==> o(nlogn)
class Solution:
    def candy(self, ratings: list[int]) -> int:
        if len(ratings) == 1: return 1
        len_ = len(ratings)
        orig_ratings = ratings.copy()
        for i in range(len_):
            ratings[i] = (i,ratings[i])
        ratings.sort(key = lambda i: i[1])
        ans = [0 for _ in range(len_)]

        for idx,val in ratings: 
            if idx == 0:
                if orig_ratings[0] > orig_ratings[1]: ans[0] = ans[1]+1
                else: ans[0] = 1
            elif idx == len_-1:
                if orig_ratings[len_-1] > orig_ratings[len_-2]: ans[len_-1] = ans[len_-2]+1
                else: ans[len_-1] = 1
            else:
              if orig_ratings[idx-1] >= val and orig_ratings[idx+1] >= val: ans[idx] = 1
              elif  orig_ratings[idx-1] < val and orig_ratings[idx+1] < val: ans[idx] = max(ans[idx-1],ans[idx+1])+1
              else:
                  if orig_ratings[idx-1] < val: ans[idx] = ans[idx-1]+1
                  else: ans[idx] = ans[idx+1]+1
        
        return sum(ans)

# o(n)
class Solution:
    def candy(self, ratings: list[int]) -> int:
        n = len(ratings)
        candies = [1]*n

        for i in range(1,n):
          if ratings[i] > ratings[i-1]: candies[i] = candies[i-1]+1
        
        for i in range(n-2,-1,-1):
          if ratings[i] > ratings[i+1]: candies[i] = max(candies[i],candies[i+1]+1)
        return sum(candies)