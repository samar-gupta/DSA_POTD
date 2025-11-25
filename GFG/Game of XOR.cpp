//Approach-1 : (VERY SHORT OBSERVATION BASED SOLUTION)
/*
  T.C. O(N)       S.C. O(1)  
  Approach: If N is even, every element will be taken 
    selected even number of times if we try to make all subarrays.

Ex. arr : 1 2 3 4
  Subarrays:
{1},{2},{3},{4}
{1,2},{2,3},{3,4}
{1,2,3},{2,3,4}
{1,2,3,4}

1 appears 4 times,      2 appears 6 times, 
3 appears 6 times  and  4 appears 4 times

So, XOR of all numbers will be zero 
 as they have even copies.


Now if N is odd,

Ex. arr : 1 2 3 4 5
  Subarrays:
{1},{2},{3},{4},{5}
{1,2},{2,3},{3,4},{4,5}
{1,2,3),{2,3,4},{3,4,5}
{1,2,3,4},{2,3,4,5}
{1,2,3,4,5}

1 appears 5 times
2 appears 8 times
3 appears 9 times
4 appears 8 times
5 appears 5 times

Only elements will odd indices appear odd number of times, 
 so, XOR of numbers of even indices would be zero, 
 and the result would be XOR of all elements with odd indices.

 Here, res=1^3^5=7.
*/
class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int N = arr.size();
        if(N%2==0){
            return 0;
        }        
        int res=0;
        for(int i=0;i<N;i+=2){
            res=res^arr[i];
        }
        return res;
    }
};
