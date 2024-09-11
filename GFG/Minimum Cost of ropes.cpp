class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>>pq;
      
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        
        long long ans=0;
        
        while(pq.size() > 1)
        {
            long long minRope1 = pq.top();
            pq.pop();
            long long minRope2 = pq.top();
            pq.pop();
            
            long long newRope = minRope1 + minRope2 ;
            pq.push(newRope );
            ans+=newRope ;
        }
        
        return ans;
    }
};
