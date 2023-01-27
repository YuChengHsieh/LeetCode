# Dijkstra
class Solution:
    def maxProbability(self, n: int, edges: list[list[int]], succProb: list[float], start: int, end: int) -> float:
        #Dijkstra
        graph = [[0 for _ in range(n)] for _ in range (n)]
        edge_len = len(edges)
        for i in range(edge_len):
            graph[edges[i][0]][edges[i][1]] = succProb[i]
            graph[edges[i][1]][edges[i][0]] = succProb[i]
        
        dist = [0 for _ in range(n)]
        unvisited_node = set([i for i in range(n)])
        for i in range(n):
            if graph[start][i] != 0:
                dist[i] = graph[start][i]
        
        cur = start 
        unvisited_node.remove(cur)
        for i in range(n-1):
            max_ = 0
            next_pt = -1
            for j in unvisited_node:
                if dist[j] > max_:
                    max_ = dist[j]
                    next_pt = j
            if next_pt == -1:
                break
            unvisited_node.remove(next_pt)
            for j in unvisited_node:
                if dist[j] < dist[next_pt]* graph[next_pt][j]:
                    dist[j] = dist[next_pt]* graph[next_pt][j]


        return dist[end]

# pass
class Solution:
    def maxProbability(self, n: int, edges: list[list[int]], succProb: list[float], start: int, end: int) -> float:
        #Dijkstra
        graph = [[] for _ in range (n)]
        edge_len = len(edges)
        for i in range(edge_len):
            graph[edges[i][0]].append((edges[i][1],succProb[i]))
            graph[edges[i][1]].append((edges[i][0],succProb[i]))
        
        dist = [0 for _ in range(n)]
        dist[start] = 1.0

        queue = []
        queue.append(start)
        while len(queue) != 0:
            cur = queue.pop(0)
            
            for i,chance in graph[cur]:
                if dist[i] < dist[cur]*chance:
                    dist[i] = dist[cur]*chance
                    queue.append(i)

        return dist[end]
