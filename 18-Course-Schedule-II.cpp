class Solution {
    bool dfs(int i,vector<vector<int>>& adj,vector<int>& s,vector<int>& visited){
        visited[i] = 1;
        for(auto &v : adj[i]){
            if(visited[v]==1) return true;
            if(visited[v]==0 && dfs(v,adj,s,visited)) return true;
        }
        visited[i]=2; //all edges covered
        s.push_back(i);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> s;
        vector<vector<int>> adj(n,vector<int>()); //to store how many courses have ith course as prereq
        for(auto &i: pre){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0 && dfs(i,adj,s,visited)) return {};   
        }
        reverse(s.begin(),s.end());
        return s;  
    }
};