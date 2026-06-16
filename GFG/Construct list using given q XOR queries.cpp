//Approach-1 : (Brute Force)
class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        ans.push_back(0);
        for(auto &x : queries){
            int f = x[0];
            int s = x[1];
            
            if(f == 0){
                ans.push_back(s);
            } else {
                for(int i=0; i<ans.size(); i++){
                    ans[i] ^= s;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//Approach-2 :
/*
Instead of immediately applying XOR to all elements, 
  maintain a variable xr that stores the cumulative XOR 
  of all type-1 queries seen so far.
After processing all queries, apply the final cumulative XOR (xr) 
  to every stored element once.
XORing the same value twice cancels out.
*/
class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        ans.push_back(0);
        int xr = 0;
        for(auto &x : queries){
            int f = x[0];
            int s = x[1];
            
            if(f == 0){
                ans.push_back(s^xr);
            } else {
                xr ^= s;
            }
        }
        for(int i=0; i<ans.size(); i++){
            ans[i] ^= xr;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};




//old (good)
class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &arr) {
        // code here
        vector<int>ans;
        int x=0;
        
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i][0]==0){
                ans.push_back(x^arr[i][1]);
            }
            else{
                x^=arr[i][1];
            }
        }
        ans.push_back(0^x);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
