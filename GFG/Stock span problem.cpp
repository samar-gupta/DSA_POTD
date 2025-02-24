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
