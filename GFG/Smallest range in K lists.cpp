class Solution {
  public:
    #define p pair<int, pair<int, int>>
    
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        int k = arr.size();
        int n = arr[0].size();
        
        // Create a min heap to store element, array no & idx
        priority_queue<p, vector<p>, greater<p>> pq;
        int mn = INT_MAX, mx = INT_MIN, range = INT_MAX;
        int low = 0, high = 0;
        
        // push first element fo each array and keep track of min and max
        // element
        for(int i=0; i<k; i++){
            pq.push({arr[i][0], {i, 0}});
            mn = min(arr[i][0], mn);
            mx = max(arr[i][0], mx);
        }
        
        // Pick each element and compare it with min to get the range if
        // we get diff less than rang then update all the value and if we
        // reach the last idx of any array then break bcz there will be no
        // more elements in that array else push the next idx of the same
        // array into min heap
        while(!pq.empty()){
            p temp = pq.top();
            pq.pop();
            
            int mini = temp.first;
            if(range > mx - mini){
                mn = mini;
                low = mn;
                high = mx;
                range = mx - mn;
            }
            
            int i = temp.second.first; // array number
            int j = temp.second.second; // index
            
            if(j == n-1) break;
            
            pq.push({arr[i][j+1], {i, j+1}});
            
            if(mx < arr[i][j+1])
                mx = arr[i][j+1];
        }
        
        return {low, high};
        
    }
};
