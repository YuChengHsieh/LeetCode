class Solution:
    def minScore(self, n: int, roads: list[list[int]]) -> int:
        graph = [[] for _ in range(n)]
        visited_node = set()
        queue = []
        queue.append(0)
        visited_node.add(0)
        for a,b,road in roads:
            graph[a-1].append((b-1,road))
            graph[b-1].append((a-1,road))

        min_score = 100000
        while len(queue)!=0:
            node = queue.pop()
            for tmp_node,road in graph[node]:
                if tmp_node not in visited_node:
                    visited_node.add(tmp_node)
                    queue.append(tmp_node)
                if road < min_score:
                    min_score = road
        return min_score