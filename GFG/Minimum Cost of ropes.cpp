//Approach-1 :
//The key to minimizing the cost is to always connect the smallest ropes first, because connecting the biggest ones early will lead to a higher total cost. We can use a min-heap (a special kind of list that always give the smallest element first) to help with this.
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
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
