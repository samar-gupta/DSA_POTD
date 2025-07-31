//Approach-1 : 
//T.C : O(n*logn) 
//S.C : O(n) 
class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        map<int, pair<int, int>> line;

        for (auto& it : intervals) {
            line[it[0]].first++;
            line[it[1]].second--;
        }
    
        int curr = 0;
        int ans = -1;
    
        for (auto& p : line) {
            int point = p.first;
            auto delta = p.second;
            curr += delta.first;
            if (curr >= k)
                ans = point;
            curr += delta.second;
        }
    
        return ans;
    }
};


//Approach-2 :
//Memory Limit Exceeded
class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        int maxEnd = 0;
        
        for(auto& interval : intervals) {
            maxEnd = max(maxEnd, interval[1]);
        }
        
        vector<int> diff(maxEnd + 2);
        
        for(auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            diff[start] += 1;
            diff[end + 1] -= 1;
        }
        
        int active = 0;
        int maxPowerful = -1;
        
        for(int i = 1; i < diff.size(); i++) {
            active += diff[i];
            if(active >= k) {
                maxPowerful = i;
            }
        }
        return maxPowerful;
    }
};
