class Solution {
public:     //1+2+...k=k*(k+1)/2 <=n => k<=[sqrt(2*n +0.5)-0.5] (make the equation a perfect square)
    int arrangeCoins(int n) {
        
      return (int) (sqrt(2*(long)n + 0.25)-0.5);
    }
};

//Alternate Solution
/*class Solution {
public:     //Use Binary Search
    int arrangeCoins(int n) {
        long left = 0,right = n,k,curr;
        while(left<=right){
            k = left + (right-left)/2;
            curr = k*(k+1)/2;
            if(curr==n) return (int) k;
            if(curr>n){
                right = k-1;
            }
            else left=k+1;
        }
        return (int)right;
        
    }
};
*/
