class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans = {0,0};
        int diff = accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        diff &= -diff;
        for( int i:nums){
            if((i & diff)==0){
                ans[0]^=i;
            }
            else
                ans[1]^=i;
        }
        return ans;
        
    }
};