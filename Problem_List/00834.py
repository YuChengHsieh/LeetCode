class Solution:
    def sumOfDistancesInTree(self, n: int, edges: list[list[int]]) -> list[int]:
        graph = [set() for _ in range(n)]
        ret = [0 for _ in range(n)]

        for i,j in edges:
            graph[i].add(j)
            graph[j].add(i)
        
        closer_node_cnts = [0]*n
        def find_base(node,parent,cnt):
            closer_nodes = 1
            base_cnts = cnt
            for nextn in graph[node]:
                if nextn == parent: continue
                node_cnt, base_cnt = find_base(nextn,node,cnt+1)
                closer_nodes += node_cnt
                base_cnts += base_cnt
            closer_node_cnts[node] = closer_nodes

            return closer_nodes,base_cnts
        
        
        def find_others(node,parent):
            for nextn in graph[node]:
                if nextn == parent: continue
                ret[nextn] = ret[node] + (n-closer_node_cnts[nextn]) - closer_node_cnts[nextn]
                find_others(nextn,node)
            
        
        ret[0] = find_base(0,-1,0)[-1]
        find_others(0,-1)
        return ret
            
