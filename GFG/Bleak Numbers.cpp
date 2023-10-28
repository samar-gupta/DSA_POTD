//Approach - 1
/* 
    Idea: maximum value of set bits for any non-negative int is 31. So simple math there after.
    Let i=countSetBits(x)  //__builtin_popcount has O(1) in C++
    then given equation becomes x + i  = n ⇒ x = n - i
    but i = countSetBits(x) = countSetBits(n-i)
    So just check for i==countSetBits(n-i) where i is in [0,31].
*/

class Solution {
public:
	int is_bleak(int n)
	{
	    for(int i = 0; i<32 and i<=n; i++) 
	    {
	        if(__builtin_popcount(n-i) == i)
	            return 0;
	    }
	    return 1;
	}
};



//Approach - 2
//Intuitive Solution | O(log2(N) *log2(N)) 
//- The brute force solution would be to iterate from all numbers from 1 to n-1 which will take NlogN time. 
//- Now let's understand the main gist of the question
//- Maximum number of set bits in any integer  <=  N will be log2(N), so the minimum value of i such that i + setBits(i) = N will be N - ceil(log2(N))
//- Now, we have significantly reduced our interval from 1 to N to N - ceil(log2(N)) to N which only have logN elements. So the overall complexity is now O(log2(N) *log2(N)).

class Solution {
public:
    int is_bleak(int n)
    {
        // see all the magic is in n - log2(n)
        // max set bits in any number <= n can be ceil value of log2(n), so the minimum i should be n-log2(n)  
        
        for (int i = n - 1; i >= n - ceil(log2(n)); i--)
        {
            if (i + __builtin_popcount(i) == n)
                return 0;
        }

        return 1;
    }
};
