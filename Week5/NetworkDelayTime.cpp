struct mycomp {
    bool operator() (const vector<int>& v, const vector<int>& w)
    {return v[0] > w[0];}
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(K < 0 || times.empty() || N < 1) return -1;
        if(N == 1) return 0;
        
        // Using times, construct graph i.e u -> {{v1, w1}, {v2, w2},...}
        unordered_map<int, vector<vector<int>> > graph;
        for(auto t : times)
            graph[t[0]].push_back({t[1], t[2]});
                
        // Hashmap maintaining key-value = {node, min path}
        unordered_map<int, int> d;
        
        // Heap of node traversed and signal time thus far
        typedef priority_queue<vector<int>, vector<vector<int>>, mycomp> mypq;
        mypq pq; 
        pq.push({0, K});
        
        /* Take top pair of heap (min dist to node x), check if visited.
        If not add to distance map, then expand node's neighbors */
        while(!pq.empty()) {
            vector<int> temp = pq.top();
            int node = temp[1], sig = temp[0];
            pq.pop();
            
            if(d.find(node) != d.end()) continue;
            d.insert({node, sig});
            
            if(graph.count(node))
               for(auto v : graph[node]) {
                   if(d.find(v[0]) == d.end())
                       pq.push({sig + v[1], v[0]});
               }
        }
        // If we do not have a value for each node there is a node that cannot be reached
        if(d.size() != N) return -1; 
        
        int longestSignal = 0;
        for(auto path : d) {
            longestSignal = max(longestSignal, path.second);
        }
        return longestSignal;
    }
};