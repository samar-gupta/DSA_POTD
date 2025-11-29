//Approach-1 : 
class Solution {
  public:
    using ll=long long;
    int countSetBits(int n) {
        // code here
        int ans=0;
        for(int b=0;b<32;b++){
            ll group_size=1ll<<(b+1),cnt_1s=1ll<<b;
            ll num_groups=n/group_size;
            ans+=num_groups*cnt_1s;
            ll pos_n=n%group_size;
            // cout<<group_size<<" "<<cnt_1s<<" "<<num_groups<<" "<<pos_n<<endl;
            if(pos_n>=cnt_1s)
                ans+=(pos_n-cnt_1s+1);
        }
        return ans;
    }
};



//Approach :
/*
The intuition is to work on the bit's position to calculate 
the total number of ones observing the pattern followed by bits.
for n = 15  
  0  = 0000
  1  = 0001
  2  = 0010
  3  = 0011
  4  = 0100
  5  = 0101
  6  = 0110
  7  = 0111
  8  = 1000
  9  = 1001
 10  = 1010
 11  = 1011
 12  = 1100
 13  = 1101
 14  = 1110
 15  = 1111
*/
class Solution {
  public:
    int countSetBits(int n) {
        // code here
        // including 0;
        int totaln = n+1;
        int ones = 1; //0th position has 1 ones in one cycle
        int count = 0;
        
        while(n!=0){
            //for ith position, we have 2^i zeros and 2^i ones in a cycle
            //temp has number of complete cycles //ones*2 (ones + zeros)
            int temp = totaln / (ones*2);
            //adding all ones contributed by complete cycles
            count += (temp*ones);
            //adding incomplete pairs
            //temp has number of cycles containing ones
            temp = totaln/ones;
            //if (temp%2 == 1) means an incomplete cycle exists
            //totaln % ones gives the count of ones in the incomplete cycle
            if(temp%2==1) count += (totaln % ones);
            //n = n/2 for next bit position
            n>>=1;
            //next position contain 2*ones of previous position
            ones*=2;
        }
        return count;
    }
};
