//Approach :
/*
Intuition :
  Each person can see shorter people standing next to them until someone of equal or greater height blocks the view.
  So for every person:
    Look left → find the first person with height ≥ current
    Look right → find the first person with height ≥ current
  These two people act as walls.
  Everyone between these walls is visible (including the person himself).

🚀 Approach :
  Use a monotonic decreasing stack to find:
    Previous Greater or Equal (PGE) for each index
    Next Greater or Equal (NGE) for each index
  For each person i:
    Left boundary = PGE[i] + 1
    Right boundary = NGE[i] - 1
  Count visible people in this range
  Return the maximum count

🧪 Dry Run :
Input: arr = [6, 2, 5, 4, 5, 1, 6]

PGE (Previous ≥ element index)
PGE = [-1, 0, 0, 2, 0, 4, -1]

NGE (Next ≥ element index)
NGE = [6, 2, 4, 4, 6, 6, 7]

Count visible people
Formula: left=PGE[i]+1,right=NGE[i]-1,cnt=right-left + 1

Key cases:
i = 0 (height 6) → range [0,5] → 6
i = 6 (height 6) → range [0,6] → 6
All others give smaller counts.

✅ Final Answer :Maximum people visible = 6
*/
//Time Complexity: O(n)
//Auxiliary Space: O(n)
class Solution {
  private:
  
    vector<int> PGE(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>pge(arr.size(),-1);
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            
            if (!st.empty()) pge[i]=st.top();
            st.push(i);
        }
        
        return pge;
        
    }   
    
    vector<int> NGE(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nge(arr.size(),n);
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            
            if (!st.empty()) nge[i]=st.top();
            st.push(i);
        }
        
        return nge;
        
    }
    
    
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        vector<int> pge=PGE(arr);
        vector<int> nge=NGE(arr);
        
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int left=(pge[i] == -1 ? 0 : pge[i]+1);
            int right=(nge[i] == n ? n-1 : nge[i]-1);
            
            int cnt=right-left+1;
            
            ans=max(ans,cnt);
        }
        
        return ans;


    }
};
