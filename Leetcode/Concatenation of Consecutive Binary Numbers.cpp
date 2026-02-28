//Leetcode Link : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
//Approach-1 (Using lo2(n) to find bits count)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int concatenatedBinary(int n) {
        
        long result = 0;
        
        for(int i = 1; i<=n; i++) {
            int digits = log2(i) + 1;
            
            result = (((result << digits)%M) + i)%M;
        }
        
        return result;
        
    }
};



//Approach-2 (Using power of 2 property to find bits count)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int concatenatedBinary(int n) {
        long result = 0;
        int digits = 0;

        for(int num = 1; num <= n; num++) {
            //digit count tabhi barhta hai jab power of 2 ata hai
            if((num & (num-1)) == 0)
                digits++;

            result = ((result << digits)%M + num)%M;
        }

        return result;
    }
};
