class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //Step 1:building graph
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        
        //Step 2:topo sorting
        vector<int> indeg(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]) indeg[it]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            topo.push_back(f);
            for(auto it:adj[f]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        //Step 3:Process nodes in order of topo sort,and for each node,propagate its prerequisites to
        //its neighbors(basically transfer the prerequisites of current node to the node's neighbors
        //as well)
        vector<bitset<100>> prereq(numCourses);
        for(int u:topo){
            for(int nbr:adj[u]){
                prereq[nbr]=prereq[nbr]|prereq[u];
                prereq[nbr].set(u);
            }
        }
        
        //Step 4:for each query,check if u is set in v's prereq bitset
        vector<bool> ans;
        for(auto& q:queries){
            int u=q[0],v=q[1];
            ans.push_back(prereq[v][u]);
        }
        return ans;
    }
};