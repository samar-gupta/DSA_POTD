//Approach-1 : 
/*
(INTUITION)
Think like this:
  You have numbers from 1 to n.
  You want to pick a subset whose XOR equals n,
  and that subset should be as big as possible,
  and lexicographically smallest (smallest numbers first).

  Now here’s a very simple observation:
  The biggest subset possible is just all numbers from 1 to n.
  So you first check whether keeping all numbers gives you XOR = n.
  But instead of calculating XOR every time, we use a pattern:

If n % 4 == 0 → XOR(1..n) = n        (perfect → keep all)
If n % 4 == 3 → XOR(1..n) = 0        (we can fix by removing n)
If n % 4 == 2 → XOR(1..n) = n + 1    (remove 1)
If n % 4 == 1 → XOR(1..n) = 1        (remove n − 1)
So based on n % 4, we choose which single element to skip.

We skip JUST one number because:
➡ Bigger size (n−1 instead of removing more)
➡ Lexicographically smallest (1 stays, 2 stays, …)
This is why our approach works.

🛠 APPROACH (Very Simple) :
Compute rem = n % 4.
Based on mod, decide which element to skip:

rem == 0 → skip none
rem == 3 → skip n
rem == 2 → skip 1
rem == 1 → skip n−1

Build the answer by adding all elements from 1 to n except the skipped one.

DRY RUN :
Example 1
n = 4
4 % 4 = 0
Skip = -1 → skip none.
So answer = [1,2,3,4].
Check XOR: 1 ^ 2 ^ 3 ^ 4 = 4 ✔

Example 2
n = 3
3 % 4 = 3
Skip = 3
Answer = [1,2]
Check XOR: 1 ^ 2 = 3 ✔

Example 3
n = 5
5 % 4 = 1
Skip = n−1 = 4
Answer = [1,2,3,5]
Check XOR: 1 ^ 2 ^ 3 ^ 5 = 5 ✔

TIME & SPACE COMPLEXITY :
Time Complexity:
  We loop from 1 to n → O(n)

Space Complexity :
  We store the result → O(n)
  No extra space except output.
*/
class Solution {
public:

    // Function that returns the element to skip
    int getSkip(int n){
        int rem=n%4;

        if(rem==0) {
            return -1;          // keep all
        }
        else if(rem==3) {
            return n;           // remove n
        }
        else if(rem==2) {
            return 1;           // remove 1
        }
        else { // rem== 1
            if(n==1) return -1; 
            return n-1;       // remove n-1
        }
    }

    vector<int> subsetXOR(int n) {
        // code here
        vector<int> ans;

        int skip=getSkip(n);   // get element to skip

        for(int i=1; i<=n;i++){
            if (i==skip){
                continue;
            }
            
            ans.push_back(i);
        }

        return ans;
    }
};


//Approach-1 : 
class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        int xorr=0;
        for(int i=1;i<=n;i++)
        {
            xorr^=i;
        }
        vector<int>ans;
        int missing=-1;
        if(xorr!=n)
        {
            missing=(n^xorr);
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=missing)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
