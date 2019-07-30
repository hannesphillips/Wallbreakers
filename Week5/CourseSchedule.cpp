class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses < 2) return true;
        if(prerequisites.size() < 2) return true;
        
        // Expand single course relationships into a graph
        // index, vector pairs form edges 
        vector<vector<int>> courseGraph(numCourses);
        for(int i = 0; i < prerequisites.size(); i++)
            courseGraph.at(prerequisites[i][0]).push_back(prerequisites[i][1]);
        
        unordered_set<int> path;
        bool past[numCourses] = {false};
        
        // If a single cycle is found in the graph, return false
        for(int i = 0; i < numCourses; i++)
            if(findCycle(i, courseGraph, path, past))
                return false;
        
        return true;
    }
    
    /* Recursively expand a node's edges and record in path, if a node
    is encountered twice in path, a cycle exists -> immediately return false.
    Add node to path and follow all of its edges. Past array records if a
    node has been processed already to prevent repeptive work. */
    bool findCycle(int course, vector<vector<int>>& v, unordered_set<int>& path, bool past[]) {
        if(path.find(course) != path.end()) return true;
        
        if(past[course]) return false;
        
        path.insert(course);
        for(int i = 0; i < v[course].size(); i++) {
            if(findCycle(v[course][i], v, path, past))
                return true;
        }
        
        past[course] = true;
        path.erase(course);
        return false;
    }
};