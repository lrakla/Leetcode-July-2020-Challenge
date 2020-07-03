class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> temp(8);
        vector<vector<int>> seen;//as 8 prison cells
        while(n--){
            for(int j =1;j<7;j++){
                temp[j] = cells[j-1]==cells[j+1];
            }
            if(seen.size() && seen.front()==temp) return seen[n % seen.size()];
            else seen.push_back(temp);
            cells = temp;
        }
        return cells;
    }
};