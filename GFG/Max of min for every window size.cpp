//Approach-1 : 
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        
        // Arrays to store the previous smaller element (PSE) and next smaller element (NSE) indices
        vector<int> left(n+1, -1);  // PSE: default -1 (no smaller element to the left)
        vector<int> right(n+1, n); // NSE: default n (no smaller element to the right)
        vector<int> ans(n, 0);     // Result array to store the maximum of minimums for each window size
        
        stack<int> st; // Stack to help find PSE and NSE
        
        // Step 1: Find the previous smaller element (PSE) for each element
        for(int i = 0; i < n; ++i) {
            // Pop elements from the stack until the top element is smaller than the current element
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            // If the stack is not empty, the top element is the PSE
            if(!st.empty()) left[i] = st.top();
            
            // Push the current index onto the stack
            st.push(i);
        }
        
        // Clear the stack for reuse
        while(!st.empty()) st.pop();
        
        // Step 2: Find the next smaller element (NSE) for each element
        for(int i = n-1; i >= 0; --i) {
            // Pop elements from the stack until the top element is smaller than the current element
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            
            // If the stack is not empty, the top element is the NSE
            if(!st.empty()) right[i] = st.top();
            
            // Push the current index onto the stack
            st.push(i);
        }
        
        // Step 3: Determine the maximum of minimums for each window size
        for(int i = 0; i < n; ++i) {
            // Calculate the window size where arr[i] is the minimum
            int len = right[i] - left[i] - 1;
            
            // Update the result for this window size
            ans[len-1] = max(ans[len-1], arr[i]);
        }
        
        // Step 4: Propagate the maximum values from larger window sizes to smaller ones
        for(int i = n-2; i >= 0; --i) {
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        // Return the final result
        return ans;
    }
};


//Approach-1 : 
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector <int> ans(n), len(n+1,0);
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                int top  = st.top();
                st.pop();
                
                int window = st.empty() ? i : i-st.top()-1;
                len[window] = max(len[window], arr[top]);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            int w = st.empty() ? n : n-st.top()-1;
            len[w] = max(len[w], arr[top]);
        } 
        
        for(int i=1; i<=n; i++) {
            ans[i-1] = len[i];
        }
            
        for(int i=n-2; i>=0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        return ans;
    }
};
