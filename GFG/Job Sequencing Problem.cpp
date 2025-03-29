//updated
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({deadline[i], profit[i]});
        }
        sort(v.begin(), v.end());
        
        priority_queue<int, vector<int>, greater<int>>pq;
        int curr=0, points=0;
        for(int i=0;i<n;i++){
            if(v[i].first > curr){
                curr++;
                points+=v[i].second;
                pq.push(v[i].second);
            }
            else if(v[i].second > pq.top()){
                points-=pq.top();
                pq.pop();
                points+=v[i].second;
                pq.push(v[i].second);
            }
        }
        return {curr, points};      
    }
};


//old-version
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    bool static comp(Job a, Job b){
        return a.profit> b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int count=0,profit=0;
        sort(arr,arr+n,comp);
        int maxi=arr[0].dead;
        for(int i=0;i<n;i++) maxi=max(maxi,arr[i].dead);
        int slot[maxi+1];
        for(int i=0;i<=maxi;i++) slot[i]=-1;
        
         int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }
      return {countJobs,jobProfit};
        
    } 
};

