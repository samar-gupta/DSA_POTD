//Approach-1 : (Brute Force)
//T.C : O(n^2) (double for loop)
//S.C : O(1)


//Approach-2 : 
//T.C : O(n)
//S.C : O(1)
//3 Cases :  1. no zeros  2. two or more zeroes  3. one zeros
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        long long prod=1;
        int zero=0;
        vector<int> ans;
        for(auto num:arr){
            if(num!=0) prod=prod*num;
            else zero++;
        }
        for(auto num:arr){
            if(zero>1) ans.push_back(0);
            else if(num!=0){
                if(zero>0) ans.push_back(0);
                else ans.push_back(prod/num);
            }
            else ans.push_back(prod);    //3. if num[i] is 0, then it will have the product of all other values, and other elements will have 0 as value
        }
        return ans;
    }
};


//Approach-2 : 
class Solution {
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n=nums.size();
        vector<long long int> ans(n,0);
        int zero=0;
        long long int prod=1;
        for(int i=0;i<n;i++) {
            if( nums[i]==0 ){
                zero++;
            }
            else{
                prod=prod*nums[i];
            }
        }
        
        if(zero>1){
            return ans;
        }
        
        for(int i=0;i<n;i++){
           if(nums[i]==0) ans[i]=prod;
           else if(zero) ans[i]=0;
           else ans[i]=prod/nums[i];
        }
        return ans;
    }
};
