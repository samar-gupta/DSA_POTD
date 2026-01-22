//Approach : (TLE)
class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int N = arr.size();
        long long sum = 0;
        
        for (int i = 0; i < N; i++) {
            int minVal = arr[i];
            int maxVal = arr[i];
            
            for (int j = i; j < N; j++) {
                minVal = min(minVal, arr[j]);
                maxVal = max(maxVal, arr[j]);
                
                sum += (maxVal - minVal);
            }
        }
        
        return sum;
    }
};


//Approach :
/*
To solve this problem, we have to find 
  Previous Smaller or Equal Element, 
  Next Smaller Element, Previous Larger or Equal Element 
  and Next Larger Element for all the positions in the given array.
After finding all these 4 values, we just have to find that, 
in how many subarrays does this value (arr[i]) occur 
as the minimum and the maximum value. 
After finding the count multiply that with our value at arr[i] 
and add the count of maximum in our answer and subtract the count of minimum from our answer.
That will ultimately give us our final answer.
*/
class Solution {
  public:
    vector<int> findPrevSmallerEqual(vector<int> &arr, int n){
        vector<int> ans(n, -1);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                ans[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
    
    vector<int> findNextSmaller(vector<int> &arr, int n){
        vector<int> ans(n, n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                ans[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
    
    vector<int> findPrevLargerEqual(vector<int> &arr, int n){
        vector<int> ans(n, -1);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()] <= arr[i]){
                ans[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
    
    vector<int> findNextLarger(vector<int> &arr, int n){
        vector<int> ans(n, n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()] < arr[i]){
                ans[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
    
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> prevSmallerEqual = findPrevSmallerEqual(arr, n);
        vector<int> nextSmaller = findNextSmaller(arr, n);
        vector<int> prevLargerEqual = findPrevLargerEqual(arr, n);
        vector<int> nextLarger = findNextLarger(arr, n);
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long pSE = i-prevSmallerEqual[i];
            long long nS = nextSmaller[i]-i;
            long long pLE = i-prevLargerEqual[i];
            long long nL = nextLarger[i]-i;
            
            ans += pLE * nL * arr[i];
            ans -= pSE * nS * arr[i];
        }
        return ans;
    }
};


//Approach : 
#define ll long long int
class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>prevGreater(n,0);
        vector<int>nextGreater(n,0);
        vector<int>prevSmaller(n,0);
        vector<int>nextSmaller(n,0);
        stack<int>st1;
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && arr[st1.top()]<=arr[i])
            {
                st1.pop();
            }
            if(st1.empty())
            {
                prevGreater[i]=-1;
            }
            else{
                prevGreater[i]=st1.top();
            }
            st1.push(i);
        }
        stack<int>st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && arr[st2.top()]<arr[i])
            {
                st2.pop();
            }
            if(st2.empty())
            {
                nextGreater[i]=n;
            }
            else{
                nextGreater[i]=st2.top();
            }
            st2.push(i);
        }
        stack<int>st3;
        for(int i=0;i<n;i++)
        {
            while(!st3.empty() && arr[st3.top()]>=arr[i])
            {
                st3.pop();
            }
            if(st3.empty())
            {
                prevSmaller[i]=-1;
            }
            else{
                prevSmaller[i]=st3.top();
            }
            st3.push(i);
        }
        
        stack<int>st4;
        for(int i=n-1;i>=0;i--)
        {
            while(!st4.empty() && arr[st4.top()]>arr[i])
            {
                st4.pop();
            }
            if(st4.empty())
            {
                nextSmaller[i]=n;
            }
            else{
                nextSmaller[i]=st4.top();
            }
            st4.push(i);
        }
        ll totalmx=0;
        ll totalmn=0;
        for(int i=0;i<n;i++)
        {
            ll leftSmallerCount = i-prevGreater[i];
            ll rightSmallerCount = nextGreater[i]-i;
            totalmx+=arr[i]*1LL*leftSmallerCount*rightSmallerCount;
            
            ll leftGreaterCount = i-prevSmaller[i];
            ll rightGreaterCount = nextSmaller[i]-i;
            totalmn+= arr[i]*1LL*leftGreaterCount*rightGreaterCount;
            
        }
        return totalmx-totalmn;
    }
};
