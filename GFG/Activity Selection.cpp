class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>> endtime;
        int n=finish.size();
        for(int i=0;i<n;i++){
            endtime.push_back({finish[i],start[i]});
        }
        sort(endtime.begin(),endtime.end());
        int lasttime=-1, count=0;
        for(int i=0;i<n;i++){
            if(lasttime==-1 || (i>0 && endtime[i].second>lasttime)){
                count++;
                lasttime=endtime[i].first;
            }
        }
        return count;
    }
};
