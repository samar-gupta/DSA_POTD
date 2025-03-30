//Approach-1 : 
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n=gas.size();
        int start=0, curr=0;
        for(int i=0;i<n;i++){
            curr+=gas[i]-cost[i];
            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        curr=0;
        for(int i=0;i<n;i++){
            int idx=(i+start)%n;
            curr+=gas[idx]-cost[idx];
            if(curr<0) return -1;
        }
        return start;
    }
};


//Approach : 
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n = gas.size();
        int totalgas = 0;
        int totalcost = 0;
        for(int i=0;i<n;i++){
            totalgas=totalgas+gas[i];
            totalcost=totalcost+cost[i];
        }
        if(totalgas<totalcost) return -1;
        int currgas = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            currgas = currgas+(gas[i]-cost[i]);
            if(currgas<0){
                currgas=0;
                ans = i+1;
            }
        }
        return ans;
    }
};
