//Approach-1 : 
//Time complexity - O(N)
//Space complexity- O(N)
class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int N = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++)
            mp[arr[i]]++;
        
        for(auto it:mp)
        {
            if(it.second==1)
            return it.first;
        }
        return -1;
    }
};


//Approach-2 : 
//just count how many times each bit is set
//if not a multiple of 3 it means this bit is set for unique element
class Solution {
  public:
    int getSingle(vector<int> &arr) {
        vector<int> setBits(32,0);
       
        for(auto num : arr){
            for(int i=31;i>=0;i--){
                if((num>>i)&1) setBits[i]+=1;
            }
        }
       
        int res=0;
        for(int i=31;i>=0;i--){
            if(setBits[i]%3!=0) {
                res|=(1<<i); 
            }
        }
           
        return res;
    }
};
