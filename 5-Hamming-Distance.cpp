class Solution {
public:
    int hammingDistance(int x, int y) {
        int c = x^y;
        int ans = __builtin_popcount(c); 
        return ans;   
    }
};