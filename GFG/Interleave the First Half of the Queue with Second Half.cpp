//Approach:
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        vector<int>arr;
        while(!q.empty())
        {
            arr.push_back(q.front());
            q.pop();
        }
        int mid=n/2;
        vector<int>ans;
        vector<int>ans2;
        for(int i=0;i<mid;i++)
        {
            ans.push_back(arr[i]);
        }
        for(int i=mid;i<n;i++)
        {
            ans2.push_back(arr[i]);
        }
        for(int i=0;i<mid;i++)
        {
            q.push(ans[i]);
            q.push(ans2[i]);
        }
    }
};


//Approach:
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        queue<int>q1;
        for(int i=0;i<n/2;i++){
            q1.push(q.front());
            q.pop();
        }
        while(!q.empty() && !q1.empty()){
            q.push(q1.front());
            q1.pop();
            q.push(q.front());
            q.pop();
        }
    }
};
