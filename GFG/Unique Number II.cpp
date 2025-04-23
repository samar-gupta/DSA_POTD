//Approach-1 : 
class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        vector<int> res;
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for(auto& it: mp)
        {
            if(it.second == 1)
                res.push_back(it.first);
        }
        if(res[0] > res[1])
            swap(res[0],res[1]);
        return res;
    }
};



//Approach-2 : 
//Time complexicity : O(n)
//Space complexicity : O(1)
/*
   1. First we do xor of all the numbers through which the xor all the repeated numbers become zero 
       and the ans is gonna be the xor of remaining two numbers .

   2. Now the problem arises how to get the two numbers from its xor.

   3. Here is the solution that we will find the rightmostset bit and apply & operation with all the elements 
       and divide the elements into two parts : one which gives gives 0 with the & operation and other one which doesn't. 
       Main point is that the ans (means those two numbers) is never be on same side.

   4. Then if i do xor operation of the two parts 
       i can see that the i get the two numbers from two parts .... which is the answer.
*/
class Solution {
  public:
    vector<int> singleNum(vector<int>& nums) {
        // Code here.
        int xxory=0;
        
        for(auto it: nums)
            xxory=xxory^it;
        int number=xxory & -xxory;
        int x=0;
        int y=0;
        for(auto it:nums){
            if(it & number){
                x=x^it;
            }
            else{
                y=y^it;
            }
        }
        
        if(x>y){
            return {y, x};
        } else{
            return {x, y};
        }
    }
};
