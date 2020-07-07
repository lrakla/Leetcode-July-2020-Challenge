class Solution { //if onone side there is water, perimeter increases by 1
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int per = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int sides =0;
                    if(i==0 || grid[i-1][j]==0) sides++;
                    if(i==n-1 || grid[i+1][j]==0) sides++;
                    if(j==0 || grid[i][j-1]==0) sides++;
                    if(j==m-1 || grid[i][j+1]==0) sides++;
                    per+=sides;
                    
                }
            }
        }
        return per;
        
    }
};