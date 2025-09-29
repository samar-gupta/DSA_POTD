//Approach-1 : (prefix sums + sliding window min with deque)
/*
• Intuition :
    The sum of any subarray arr[l..r] can be written as:  sum(l,r)=pref[r+1]-pref[l]
    Constraint: subarray length must satisfy :a≤(r−l+1)≤b Which means l lies in range [r-b+1, r-a+1].
    So for each r, we must find the smallest prefix[l] in that window to maximize pref[r+1] - pref[l].
    A deque is perfect to keep the candidate l indices:
    Increasing order of prefix values (so front = smallest).
    Pop indices that fall outside the valid [r-b, r-a] range.

• Approach(Step by Step)
    Build prefix sum array.
    Traverse right endpoint r = a … n.
    Candidate start index = l = r-a.
    Push l into deque while keeping prefix increasing.
    Remove deque front if it’s < r-b.
    Compute best = pref[r] - pref[dq.front()].
    Track global maximum.
• Summary:
    Build prefix sums.
    Use deque to maintain min prefix in valid window.
    Answer = max over (pref[i] - minPrefInWindow).
    TC = O(n), SC = O(n).
*/
//T.C : O(n)   //Each index is pushed/popped from deque at most once.
//S.C : O(n)   //Prefix array O(n), deque O(n).
class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
        int n=arr.size();
        
        vector<long long> pref(n+1,0);
        
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+arr[i-1];
        }
        
        deque<int> dq;
        
        int maxSum=INT_MIN;
        
        for(int r=a;r<=n;r++){
           int l=r-a;
           
           while (!dq.empty() && pref[dq.back()] >= pref[l]){
               dq.pop_back();
           }
           
           dq.push_back(l);
           
           while (!dq.empty() && dq.front() < r-b){
                dq.pop_front();
           }
           
           maxSum=max(maxSum,(int)(pref[r]-pref[dq.front()]));
        }
        
        return maxSum;
    }
};
