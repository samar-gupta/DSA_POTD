//Approach-1 :
class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        double total=0;
        
        priority_queue<double>pq;
        
        for(int &i:arr){
            pq.push(i*1.0);
            total+=(i*1.0);
        }
        
        double half=total/2.0;
        int ans=0;
        
        while(total>half){
            double top=pq.top();
            pq.pop();
            
            total-=top/2.0;
            pq.push(top/2.0);
            
            ans++;
        }
        
        return ans;
    }
};
