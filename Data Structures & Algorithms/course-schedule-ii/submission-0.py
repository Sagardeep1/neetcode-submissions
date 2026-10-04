class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree = [0] * numCourses
        adj = defaultdict(list)

        for i in prerequisites:
            indegree[i[0]] += 1
            adj[i[1]].append(i[0])
        
        ans = []
        qu = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                qu.append(i)
        
        while qu:
            course = qu.popleft()
            ans.append(course)
            for adj_course in adj[course]:
                indegree[adj_course] -= 1
                if indegree[adj_course] == 0:
                    qu.append(adj_course)
        
        if len(ans) == numCourses:
            return ans
        return []