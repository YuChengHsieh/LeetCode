class Solution:
    def groupThePeople(self, groupSizes: list[int]) -> list[list[int]]:
        hash = {}
        ans = []
        for i in range(len(groupSizes)):
            if hash.get(groupSizes[i]) is None: hash[groupSizes[i]] = []
            hash[groupSizes[i]].append(i)

            if len(hash[groupSizes[i]]) == groupSizes[i]:
                ans.append(hash[groupSizes[i]])
                hash[groupSizes[i]] = []
        return ans