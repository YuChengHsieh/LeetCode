class Solution:
    def placedCoins(self, edges: list[list[int]], cost: list[int]) -> list[int]:
        n = len(cost)
        visited = {}
        self.ans = [0]*n
        graph = [set() for _ in range(n)]
        
        for i,j in edges:
            graph[i].add(j)
            graph[j].add(i)
        
        def dfs(curn,prevn):
            if curn in visited: return visited[curn]
            li = []
            for nextn in graph[curn]:
                if nextn != prevn: 
                    ret_list = dfs(nextn,curn)
                    li.extend(ret_list)
                    
            
            li.append(cost[curn])
            if len(li) < 3: self.ans[curn] = 1
            else: 
                li.sort()
                self.ans[curn] = max(0,li[-3]*li[-2]*li[-1],li[-1]*li[0]*li[1])
            
            visited[curn] = li if len(li) < 5 else li[:2] + li[-3:]
            return li
        
        dfs(0,-1)
        return self.ans
        