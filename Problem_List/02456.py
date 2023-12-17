from collections import defaultdict
class Solution:
    def mostPopularCreator(self, creators: list[str], ids: list[str], views: list[int]) -> list[list[str]]:
        totalView_dict = defaultdict(int)
        most_famous_dict = {}
        highest_creators = []
        highest_view = 0

        n = len(creators)

        for i in range(n):
            totalView_dict[creators[i]] += views[i]
            if totalView_dict[creators[i]] > highest_view:
                highest_view = totalView_dict[creators[i]]
                highest_creators = [creators[i]]
            elif totalView_dict[creators[i]] == highest_view:
                highest_creators.append(creators[i])
            
            if creators[i] not in most_famous_dict or views[i] > most_famous_dict[creators[i]][-1] or (views[i] ==  most_famous_dict[creators[i]][-1] and ids[i] < most_famous_dict[creators[i]][0] ): most_famous_dict[creators[i]] = (ids[i],views[i])
        
        ans = set()
        for creator in highest_creators:
            ans.add((creator,most_famous_dict[creator][0]))
        
        return list(ans)
