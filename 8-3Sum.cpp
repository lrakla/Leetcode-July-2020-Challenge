class Solution { //using two pointer and variation of TwoSum problem
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            int target = -nums[i];
            if(target<0) break;
            int front = i+1;
            int back = nums.size()-1;
            while(front < back){
                int sum = nums[front] + nums[back];
                if(sum<target) front++;
                else if(sum>target) back--;
                else{
                    vector<int> temp(3,0);
                    temp[0]=nums[i];
                    temp[1]=nums[front];
                    temp[2]=nums[back];
                    ans.push_back(temp);
                
                    while(front<back && nums[front]==temp[1]) front++;
                    while(front<back && nums[back]==temp[2]) back--; 
                }
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
            
        }
        return ans;
    }
};