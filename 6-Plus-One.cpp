class Solution {    
public:
    vector<int> plusOne(vector<int>& d) {
        int n = d.size();
        for(int i =n-1;i>=0;--i){
            if(d[i]==9){
                d[i]=0;
            }
            else{
                d[i]++;
                return d;
            }
        }
        d[0]=1;
        d.push_back(0);
        return d;
    }
};