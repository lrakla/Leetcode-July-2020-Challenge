class Solution {
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths, int curr){
        path.push_back(curr);
        if(curr == graph.size()-1)
            paths.push_back(path);
        else 
            for(auto it : graph[curr]){
                dfs(graph,path,paths,it);
            }
        path.pop_back(); //to remove a path after it has been pushed in paths
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> paths;
        dfs(graph,path,paths,0);
        return paths;
    }
};