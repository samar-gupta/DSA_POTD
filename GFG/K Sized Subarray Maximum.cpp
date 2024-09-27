class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        int n = arr.size();
        
        vector<int>ans;
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<k;i++) {
           pq.push({arr[i],i});
        }

        ans.push_back(pq.top().first);

        for(int i=k;i<n;i++) {
           pq.push({arr[i],i});

           while(i-pq.top().second>=k)
               pq.pop();

           ans.push_back(pq.top().first);
       }

       return ans;
    }
};
