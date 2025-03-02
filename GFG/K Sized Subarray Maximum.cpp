//updated
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> res;
        deque<int> dq;  // Deque to store indices

        for (int i = 0; i < n; i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove elements smaller than current one
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();

            // Add current index to deque
            dq.push_back(i);

            // Store result after the first window is filled
            if (i >= k - 1)
                res.push_back(arr[dq.front()]);
        }

        return res;
    }
};


//old
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
