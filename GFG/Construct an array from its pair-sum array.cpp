//Approach:
/*
Intuition:
We are given an array that contains pairwise sums of an unknown original array in a fixed order:

First all pairs with the 0th element:
(0,1), (0,2), (0,3), …, (0, n-1)

Then all pairs with the 1st element:
(1,2), (1,3), …

So the first values of the pair-sum array look like this:
arr[0] = a0 + a1
arr[1] = a0 + a2
arr[2] = a0 + a3
…
(n−2)-th = a0 + a(n−1)
(n−1)-th = a1 + a2

So the three important sums are:
S01 = a0 + a1
S02 = a0 + a2
S12 = a1 + a2 (this is always at index n−1)
These three reveal the first value easily:
a0 = (S01 + S02 – S12) / 2

Once we know a0, every other element is reconstructed using the pair sums from the first block:
a1 = S01 – a0
a2 = S02 – a0
a3 = (a0 + a3) – a0
...
a(i) = arr[i−1] – a0

Approach:
If the pair-sum array has only 1 element, original array has size 2.

Compute n using the formula
n = (1 + √(1 + 8m)) / 2
because m = n(n−1)/2.

Read the three important pair sums:
arr[0] = a0 + a1
arr[1] = a0 + a2
arr[n−1] = a1 + a2

Compute a0 using the formula above.

For every i from 1 to n−1, compute ai from the first block:
ai = arr[i−1] − a0

Return the reconstructed array.


Dry Run:
Given pair-sum array:
[6, 4, 4, 8, 8, 6]

Step 1: m = 6
Solve m = n*(n−1)/2 → n = 4
(so original array has 4 numbers)

Step 2: Identify important sums:
S01 = arr[0] = 6
S02 = arr[1] = 4
S12 = arr[n−1] = arr[3] = 8

Step 3: Compute a0:
a0 = (6 + 4 – 8) / 2 = 2 / 2 = 1

Step 4: Compute other values:
a1 = arr[0] – a0 = 6 – 1 = 5
a2 = arr[1] – a0 = 4 – 1 = 3
a3 = arr[2] – a0 = 4 – 1 = 3

Final array:
[1, 5, 3, 3]
Its pair-sums match original input → correct.

Time Complexity
O(n) , Because Only one loop to fill the array.

Space Complexity
O(n) , Because Only the result array is used.
*/
class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        // code here
        int m=arr.size();
    
           if(m==1){
               return {1,arr[0]-1};
            } 
    
           int n=(1 + sqrt(1 + 8*m)/2);
    
           vector<int> ans(n);
    
           ans[0]=(arr[0]+arr[1]-arr[n-1])/2;
    
           for(int i=1;i<n;i++){
               ans[i]=arr[i-1]-ans[0];
           }
        
           return ans;
    }
};


//Approach:
class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        // code here
        int n = (int)(sqrt(arr.size()*2)) + 1;
        vector<int> res(n);
        
        res[0] = (arr[0] + arr[1] - arr[n-1]) / 2;
        
        for(int i=1;i<n;i++)
        res[i] = arr[i-1] - res[0];
        
        return res;
    }
};
