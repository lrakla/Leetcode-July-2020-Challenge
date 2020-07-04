class Solution {
public:
    int nthUglyNumber(int n) {
        unsigned ugly[n];
        ugly[0]=1;
        int i2=0,i5=0,i3=0;
        int n2,n3,n5;
        for(int i=1;i<n;i++){
            n2 = ugly[i2]*2;
            n3 = ugly[i3]*3;
            n5 = ugly[i5]*5;  
            ugly[i] = min(min(n2,n3),n5);
            if(ugly[i]==n2) i2++;
            if(ugly[i]==n3) i3++;
            if(ugly[i]==n5) i5++;
        }
        return ugly[n-1];
    }
};