//Approach:
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(i+1);
            }
            else{
                ans.push_back(i-st.top());
            }
            st.push(i);
        }
        return ans;
    }
};


//old
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& price) {
        // write code here
        int n = price.size();
        vector<int> res(n,1);
        stack<int> st;
        st.push(0);
       
        for(int i=1; i < n; i++){
            while(!st.empty() and price[st.top()] <= price[i]){
                st.pop();
            }
            int ans = (st.empty()) ? i+1 : i-st.top();
            res[i] = ans;
            st.push(i);
        }
        return res;
    }
};
