# union
class Solution:
    def makeConnected(self, n: int, connections: list[list[int]]) -> int:
        # list of set
        connected_list = []
        extra_edge = 0
        for a,b in connections:
            union_num = []
            for i,group in enumerate(connected_list):
                if a in group and b in group:
                    extra_edge += 1
                    break
                elif a in group or b in group:
                    union_num.append(i)
                    if a not in group:
                        group.add(a)
                    elif b not in group:
                        group.add(b)
            else:
                if len(union_num) == 2:
                    connected_list[union_num[0]] = connected_list[union_num[0]].union(connected_list[union_num[1]])
                    connected_list.pop(union_num[1])
                elif len(union_num) == 0:
                    connected_list.append(set())
                    connected_list[-1].add(a)
                    connected_list[-1].add(b)
        
        cnt = n
        for group in connected_list:
            print(group)
            cnt -= len(group)
        return -1 if extra_edge - (len(connected_list)-1) - cnt<0  else len(connected_list)-1+cnt

# BFS
class Solution:
    def makeConnected(self, n: int, connections: list[list[int]]) -> int:
        if len(connections) < n-1:
            return -1
        visited_node = set()
        graph = [set() for _ in range(n)]
        
        for a,b in connections:
            graph[a].add(b)
            graph[b].add(a)
        
        def dfs(node):
            if node in visited_node:
                return 0
            
            visited_node.add(node)
            for to in graph[node]:
                dfs(to)
                

            return 1
        
        return sum(dfs(i) for i in range(n))-1