//Approach-1 : 
class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        // When you repeatedly divide a number by 2, the remainder at each step is 
        // simply the least significant bit (LSB) of its binary representation.
        
        
        // The number of times the remainder is 1 equals the population count (popcount) 
        // or set bits of the number.
        
        int maxElement = INT_MIN;
        
        int n = arr.size();
        
        for(int i = 0 ; i < n ; i++)
        {
            maxElement = max(maxElement, arr[i]);
        }
        
        int decrementOperation = 0;
        int divideOperation = 0;
        
        int temp =  maxElement;
        
        for(int i = 0;i<n;i++)
        {
            int onesBit = __builtin_popcount(arr[i]);
            decrementOperation += onesBit;
            
        }
        
        while(temp > 0)
        {
            if(temp%2==0)
            {
                temp/=2;
                divideOperation++;
            }
            else
            {
                temp-=1;
            }
        }
        
        return decrementOperation + divideOperation;
    }
};



//Approach-2 : 
class Solution {
  public:
    int countMinOperations(vector<int>& a) {
        // code here
        int min_moves = 0;

       // loop till all the array elements become 0
       while (true)
       {
           // stores count of 0's in the current array
           int no_of_zeroes = 0;

           // traverse the array
           for (int i = 0; i < a.size(); i++)
           {
               // convert all odd numbers to even by reducing their value by 1
               // for each odd value, increment the number of moves required
               if (a[i] % 2 == 1)
               {
                   a[i]--;
                   min_moves++;
               }

               // increment zeroes count if the current element becomes 0
               if (a[i] == 0) {
                   no_of_zeroes++;
               }
           }

           // break the loop if elements in the array become 0
           if (no_of_zeroes == a.size()) {
               break;
           }

           // Since each array element is even at this point,
           // divide each element by 2
           for (int j = 0; j < a.size(); j++) {
               a[j] = a[j] / 2;
           }

           // increment number of moves by 1 for the above divide operation
           min_moves++;
       }

       // return count of minimum moves required
       return min_moves;
    }
};
