//Approach-1 : 
/*
1. Let:
    endWith0 = number of valid strings ending with 0
    endWith1 = number of valid strings ending with 1

2. For length 1:
    "0" → ends with 0
    "1" → ends with 1
  So:
   endWith0 = 1
   endWith1 = 1

3. For every next position:
    New strings ending with 0 can come from both previous 0 and 1
    New strings ending with 1 can only come from previous 0
  So:
   newEndWith0 = endWith0 + endWith1
   newEndWith1 = endWith0

4. Update the values for every length from 2 to n.

5. Final answer is:
    endWith0 + endWith1
*/
class Solution {
  public:
    int countStrings(int n) {
        // code here
        long long endWith0 = 1;
        long long endWith1 = 1;
        
        for (int i = 2; i <= n; i++) {
            long long newEndWith0 = endWith0 + endWith1;
            long long newEndWith1 = endWith0;
            
            endWith0 = newEndWith0;
            endWith1 = newEndWith1;
        }
        
        return endWith0 + endWith1;
    }
};
