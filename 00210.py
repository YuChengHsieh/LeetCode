# cycle detection
class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        graph = [[] for _ in range(numCourses)]

        for i,j in prerequisites:
            graph[i].append(j)
        
        permanent = set()
        visited = set()
        ans = []
        self.exist_cycle = False
        
        def dfs(course):
            if course in permanent:
                return
            if course in visited:
                self.exist_cycle = True
                return
            
            visited.add(course)
            for nextn in graph[course]:
                dfs(nextn)
                if self.exist_cycle:
                    return

            permanent.add(course)
            ans.append(course)
            return
        
        for i in range(numCourses):
            if i not in visited:
                dfs(i)
                if self.exist_cycle:
                    return []
        return ans