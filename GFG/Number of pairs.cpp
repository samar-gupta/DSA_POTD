//Approach 1 (Brute Force):
//The Brute force approach involves just checking through all pairs, hence we would have two for loops to iterate through all pairs and checking the condition x^y > y^x. Computation of x^y and y^x would take time log(y) + log(x) respectively for eack pair.
//Time complexity = O(n*m*maxVal(logy+logx))
//n = size of arr  m=size of brr 
//This solution will clearly give TLE as the constrains of n,m are 10^5, further more x^y cannot be stored in a long long type integer as 1e3^1e3 is a very huge number.

 
//Approach 2:
//We can see that we need to find pairs satisfying x^y > y^x, Apply (1/xy) on the power to both sides,the inequality sign will not change as 1/xy is positive always and power is an increasing function. We get x^(1/x) > y^(1/y)  this means that if we replace every x with X =x^(1/x) and every y with  Y = y^(1/y). Our job is to only find the pairs such that X>Y.
//This makes the problem easy to solve in faster complexity.
//To find pairs X>Y can be easily done, we can sort the array storing the Y's and iterate over each X to find how many elements in Y are lesser than X. That can be easily calculated as Y is sorted and we can simply use the lower bound function  to find the first index that is lesser than or equal to X in Y's array. Hence all elements from start to this index will be valid pairs for X. Add it to the answer simply. At the end return ans. 
//Computing x^1/x would take Log(x) time and sorting the array takes mLog(m) time and iterating thorugh X's and for each X computing its lower bound takes nLog(m) time.
//Also the max value of x^1/x is 1.444 hence it can be stored easily inside the long double.
//Time Complexity: O(log(x) + nLog(m)+mLog(m)) = O((n+m)(Log(m) + Log(x))

 //Code (C++):
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        vector<long double>a,b;
        
        for(auto ele:arr) {
            long double temp = double(ele);
            a.push_back(pow(temp,1/temp));
        }
        
        for(auto ele:brr) {
            long double temp = double(ele);
            b.push_back(pow(temp,1/temp));
        }      
        
        sort(b.begin(),b.end());

        long long ans = 0;
        
        for(auto ele:a) {
            ans+= (long)distance(b.begin(),lower_bound(b.begin(),b.end(),ele));
        }
        
        return ans;
    }
};
