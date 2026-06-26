class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto vec:prerequisites) {
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }
        queue<int> course_qu;
        for(int i=0;i<numCourses;i++)
            if(indegree[i] == 0)
                course_qu.push(i);
        while(!course_qu.empty()) {
            int course = course_qu.front();
            course_qu.pop();
            for(auto neigh:adj[course]) {
                if(--indegree[neigh] == 0)
                    course_qu.push(neigh);
            }
        }
        for(int i=0;i<numCourses;i++) {
            if(indegree[i] != 0)
                return false;
        }
        return true;
    }
};
