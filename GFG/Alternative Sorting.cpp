//Approach-1 : (Usong priority_queue)
class Solution {
  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        for (int i = 0; i < n; i+=2) {
            arr[i] = pq.top();
            pq.pop();
        }
        int i = (n % 2 == 0) ? (n-1) : (n-2);
        while (i > 0) {
            arr[i] = pq.top();
            pq.pop();
            i -= 2;
        }
        return arr;
    }
};


//Approach-2 : (Sorting & 2-pointer)
class Solution {
  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        vector<int>ans(n,0);
        sort(arr.begin(),arr.end());
        int j=n-1,k=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans[i]=arr[j];
                j--;
            }
            else{
                ans[i]=arr[k];
                k++;
            }
        }
        return ans;
    }
};
