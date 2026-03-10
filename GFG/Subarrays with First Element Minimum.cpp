//Approach-1 :
class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        stack<int>st;
        int i=0;
        int ans=0;
        while(i<arr.size())
        {
            while(!st.empty() && st.top()>arr[i])
            {
                st.pop();
            }
            st.push(arr[i]);
            ans=ans+st.size();
            i++;
        }
        return ans;
    }
};


//Approach-1 :
class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<int> st;
        long long ans=0;
        
        for(int i=n-1;i>=0;i--) {
            
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            int nxtSmaller=st.empty() ? n : st.top();
            ans+=(nxtSmaller-i);
            
            st.push(i);
        }
        
        return (int)ans;
    }
};
