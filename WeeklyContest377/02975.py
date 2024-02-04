class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: list[int], vFences: list[int]) -> int:
        mod = 10**9+7
        hFences.append(m); hFences.append(1)
        vFences.append(n); vFences.append(1)
        hFences.sort()
        vFences.sort()
        # print(hFences, vFences)
        width_possibility = set()
        for idx,i in enumerate(hFences):
            for j in hFences[idx+1:]:
                width_possibility.add(j-i)
        
        height_possibility = set()
        for idx,i in enumerate(vFences):
            for j in vFences[idx+1:]:
                height_possibility.add(j-i)
    
        intersection = sorted(list(width_possibility.intersection(height_possibility)))
        
        return -1 if len(intersection) == 0 else intersection[-1]**2%mod