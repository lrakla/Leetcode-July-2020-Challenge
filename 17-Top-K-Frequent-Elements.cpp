class Solution {  
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int> m; //number and count
        priority_queue<int,vector<int>, greater<int>> max_k;
        vector<int> ans;
        for(int i : nums)
            m[i]++;
        for(auto &i : m){
            max_k.push(i.second);
            while(max_k.size()>k) max_k.pop(); 
        }
        for(auto & i : m) {
            if(i.second >= max_k.top()) ans.push_back(i.first);
        }
        return ans;
    }
};