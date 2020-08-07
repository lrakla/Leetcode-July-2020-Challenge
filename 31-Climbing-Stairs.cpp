class Solution {
public:
    unordered_map<int,int> s = {{0,0},{1,1},{2,2}}; 
    int climbStairs(int n) {
       if(s[n]) return s[n]; 
       return s[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};