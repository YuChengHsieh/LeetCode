# hash map o(value_len^2) TLE ==> too nuch time
class Solution:
    def distinctNames(self, ideas: list[str]) -> int:
        hash_map = {}
        for idea in ideas:
            if hash_map.get(idea[1:]) is None:
                hash_map[idea[1:]] = set()
            hash_map[idea[1:]].add(idea[0])
        
        value = list(hash_map.values())
        value_len = len(value)
        cnt = 0
        for i in range(value_len):
            for j in range(i,value_len):
                intersection = value[i]&value[j]
                cnt += len(value[i]-intersection)*len(value[j]-intersection)*2
        return cnt

# hash map o(26*2) just use the first character to group
class Solution:
    def distinctNames(self, ideas: list[str]) -> int:
        hash_set = [set() for _ in range(26)]
        # eg. cofffee : hash_set[2] = 'offee', donuts: hash_set[3] = 'onuts' 
        for idea in ideas:
            hash_set[ord(idea[0])-ord('a')].add(idea[1:])
        
        cnt = 0
        for i in range(26):
            for j in range(i+1,26):
                intersection = hash_set[i]&hash_set[j]
                cnt += len(hash_set[i]-intersection)*len(hash_set[j]-intersection)*2
        return cnt