//Approach-1 : (Using priority_queue)
//T.C : O(nLogK)
//S.C : O(k)
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minH;
        
        int idx = 0;
        for(auto&i: arr){
            minH.push(i);
            if(minH.size()>k){
                arr[idx++] = minH.top();
                minH.pop();
            }
        }
        while(!minH.empty()){
            arr[idx++] = minH.top();
                minH.pop();
        }
    }
};



//old
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int,vector<int>,greater<int>> q;
        int n=arr.size();
        for(int i=0;i<=k;i++) q.push(arr[i]);
        int i=0,j=k+1;
        while(j<n){
            int x=q.top();
            q.pop();
            arr[i]=x;
            q.push(arr[j]);
            i++;
            j++;
        }
        while(i<n){
            arr[i]=q.top();
            q.pop();
            i++;
        }
    }
};
