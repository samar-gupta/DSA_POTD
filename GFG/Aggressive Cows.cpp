class Solution {
  public:
    bool ispos(vector<int> &stalls,int d,int k){
        int c=1;
        int last=stalls[0];
        for (int i=1;i<stalls.size();i++){
            if (stalls[i]-last>=d){
                c++;
                last=stalls[i];
            }
            if (c>=k) return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[stalls.size()-1]-stalls[0];
        while(low<=high){
            int mid=(low+high)/2;
            if (ispos(stalls,mid,k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};
