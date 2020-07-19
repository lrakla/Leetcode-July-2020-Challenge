class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        string res;
        int s=0; //result sum
        while(i>=0 || j >=0 || s==1 ){
            s+= ((i >=0 ) ? a[i]-'0' : 0);
            s+= ((j >=0 ) ? b[j]-'0' : 0);
        
            res= char(s%2 + '0') + res; //if sum is 1 or 3 add 1 to result
            s/=2; //to calculate carry
            i--;j--;
        }
        return res;
    }
};