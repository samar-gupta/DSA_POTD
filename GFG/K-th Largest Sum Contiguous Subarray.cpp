class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        priority_queue <int, vector <int>, greater<int>> pq;
        
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                
                if(pq.size() < k) pq.push(sum);
                else{
                    int top = pq.top();
                    if(sum > top){
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        
        return pq.top();
    }
};
