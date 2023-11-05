# Topological sort
class Solution:
    def sortItems(self, n: int, m: int, group: list[int], beforeItems: list[list[int]]) -> list[int]:
        
        def topological_sort(graph,indegree):
            stack = []
            ans = []
            for i in range(len(indegree)):
                if indegree[i] == 0: stack.append(i)
            while len(stack) != 0:
                cur = stack.pop()
                ans.append(cur)
                for nextn in graph[cur]:
                    indegree[nextn] -= 1
                    if indegree[nextn] == 0: stack.append(nextn)
            return ans if len(ans) == len(indegree) else []

        group_cnt = m
        for i in range(n):
            if group[i] == -1:
                group[i] = group_cnt
                group_cnt += 1
        itemGraph = [[] for _ in range(n)]
        item_indegree = [0 for _ in range(n)]
        groupGraph = [[] for _ in range(group_cnt)]
        group_indegree = [0 for _ in range(group_cnt)]

        for i in range(n):
            for j in beforeItems[i]:
                itemGraph[j].append(i)
                item_indegree[i] += 1
                if group[i] != group[j]:
                    groupGraph[group[j]].append(group[i])
                    group_indegree[group[i]] += 1
        item_order = topological_sort(itemGraph,item_indegree)
        group_order = topological_sort(groupGraph,group_indegree)
        # print(item_order,group_order)
        if len(item_order) == 0 or len(group_order) == 0: return []
        
        final_group = [[] for _ in range(group_cnt)]
        for node in item_order:
            final_group[group[node]].append(node)
        ans = []
        for i in group_order:
            ans.extend(final_group[i])
        return ans
