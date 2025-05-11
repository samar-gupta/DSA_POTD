class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
	    for(int i=0;i<n;i++) {
	        int sum = 0;
	        for(int j=i;j<n;j++) {
	            sum += arr[j];
	            pq.push(sum);
	            if(pq.size()>k) {
	                pq.pop();
	            }
	        }
        }
        return pq.top();
    }
};
