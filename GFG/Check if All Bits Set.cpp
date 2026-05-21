//Approach-1 : 
class Solution {
  public:
    bool isBitSet(int N) {
        // code here
        if(N==0)
        return 0;
        
        while(N>0)
        {
            if(N%2==0)
             return 0;
             N /= 2;
        }
        return 1;
    }
};



//Approach-2 :
class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(N==0)
            return 0;
        
        while(N>0)
        {
            if((N&1)==0)//checking LSB bit
                return 0;
            N>>=1; //shift N to right to check LSB bit 
        }
        return 1;
    }
};


//Approach-3 :
/*
n looks like 1111
n + 1 looks like 10000

Both numbers have no common set bit.
So:

if result is 0 → return true
otherwise → return false
*/
class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if (n == 0)
            return false;

        return (n & (n + 1)) == 0;
    }
};
