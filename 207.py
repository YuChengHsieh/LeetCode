class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        # cycle detection
        graph = [[] for _ in range(numCourses)]
        for i,j in prerequisites:
            graph[i].append(j)
        
        no_cycle = set()
        visited = set()
        self.can = True

        def dfs(course):
            if course in no_cycle:
                return
            if course in visited:
                self.can = False
                return
            
            visited.add(course)
            for nextn in graph[course]:
                dfs(nextn)
                if not self.can:
                    return
            no_cycle.add(course)
            return
            
        for i in range(numCourses):
            if i not in visited:
                dfs(i)
                if not self.can:
                    return False
        else:
            return True