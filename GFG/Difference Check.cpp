//Approach-1 : 
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        vector<int> seconds;
        
        for(const string& time : arr) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            int s = stoi(time.substr(6, 2));
            
            int totalSeconds = h * 3600 + m * 60 + s;
            seconds.push_back(totalSeconds);
        }
        
        sort(seconds.begin(), seconds.end());
        
        int minDiff = INT_MAX;
        
        for(int i = 1; i < seconds.size(); i++) {
            minDiff = min(minDiff, seconds[i] - seconds[i-1]);
        }
        
        int wrapAroundDiff = (seconds[0] + 24 * 3600) - seconds.back();
        minDiff = min(minDiff, wrapAroundDiff);
        
        return minDiff;
    }
};
