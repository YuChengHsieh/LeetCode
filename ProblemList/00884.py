class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> list[str]:
        m1 = {}
        m2 = {}

        s1 = s1.split(' ')
        s2 = s2.split(' ')

        for word in s1:
            if word not in m1:
                m1[word] = 0
            m1[word] += 1

        for word in s2:
            if word not in m2:
                m2[word] = 0
            m2[word] += 1

        ans = []
        for k,v in m1.items():
            if k not in m2 and v == 1:
                ans.append(k)
        
        for k,v in m2.items():
            if k not in m1 and v == 1:
                ans.append(k)
        
        return ans