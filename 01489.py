class Union_Find:
    def __init__(self,n):
        self.parents = [i for i in range(n)]
        self.weights = 0
        self.edge_count = 0
    def find(self,x):
        if x != self.parents[x]: self.parents[x] = self.find(self.parents[x])
        return self.parents[x]
    def union(self,a,b,w):
        r1 = self.find(a)
        r2 = self.find(b)

        if r1!=r2: # is disjoint set
            self.parents[r2] = r1
            self.weights += w
            self.edge_count += 1
class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        # Kruskal algorithm
        key_dict = {}
        for i in range(len(edges)):
            key_dict[tuple(edges[i])] = i
        edges.sort(key=lambda a: a[-1])
        uf = Union_Find(n)
        th = len(edges)-1
        for i,(n1,n2,val) in enumerate(edges):
            uf.union(n1,n2,val)
            if uf.edge_count == n-1:break
        min_val = uf.weights

        th=i+1
        while th < len(edges):
            if edges[th][-1] != val: 
                break
            th+=1
        ans = [[],[]]
        for i in range(th):
            # take ith node out 
            tmp_uf = Union_Find(n)
            cur_val = 0
            for j,(n1,n2,val) in enumerate(edges):
                if i == j: continue
                tmp_uf.union(n1,n2,val)
                if tmp_uf.edge_count == n-1: break
            if tmp_uf.weights > min_val or tmp_uf.edge_count < n-1 : 
                ans[0].append(key_dict[tuple(edges[i])])
            else: 
                tmp_uf2 = Union_Find(n)
                tmp_uf2.union(*edges[i])
                for n1,n2,val in edges:
                    tmp_uf2.union(n1,n2,val)
                if tmp_uf2.weights == min_val:
                    ans[1].append(key_dict[tuple(edges[i])])
        return ans
        