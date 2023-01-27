# BFS
class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: list[list[int]], blueEdges: list[list[int]]) -> list[int]:
        # red first
        ans_list = [-1 for i in range(n)]
        ans_list[0] = 0
        red_graph = [[-1 for j in range(n)] for i in range(n)]
        blue_graph = [[-1 for j in range(n)] for i in range(n)]
        queue = []
        red_unvisited_edge = set([i for i in range(n)])
        blue_unvisited_edge = set([i for i in range(n)])

        # fill graph
        for from_,to in redEdges:
            red_graph[from_][to] = 1
            if from_ == 0 and to != 0:
                # expand from 0 to another node in red graph
                queue.append((0,to,1,'r'))
                ans_list[to] = 1
                red_unvisited_edge.remove(to)

        for from_,to in blueEdges:
            blue_graph[from_][to] = 1
            if from_ == 0 and to != 0:
                # expand from 0 to another node in blue graph
                queue.append((0,to,1,'b'))
                ans_list[to] = 1
                blue_unvisited_edge.remove(to)
        
        while len(queue) != 0:
            from_,to,dist,color = queue.pop(0)
            # set unvisited_edge and graph parameter
            unvisited_edge = blue_unvisited_edge if color == 'r' else red_unvisited_edge
            graph = blue_graph if color == 'r' else red_graph
            # delete edges in unvisited edge that visited in this node 
            tmp_delete = []
            for j in unvisited_edge:
                if graph[to][j] != -1:
                    if ans_list[j] == -1:
                        ans_list[j] = dist+1
                    queue.append((to,j,dist+1,'r' if color == 'b' else 'b'))
                    graph[to][j] = dist+1
                    tmp_delete.append(j)
            for j in tmp_delete:
                unvisited_edge.remove(j)

            # update unvisited_edge and graph parameter
            if color == 'r':
                blue_unvisited_edge = unvisited_edge
                blue_graph = graph
            else:
                red_unvisited_edge = unvisited_edge
                red_graph = graph
                
        return ans_list