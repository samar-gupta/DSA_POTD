//Company Tags  : Media.net
//Leetcode Link : https://leetcode.com/problems/minimum-time-visiting-all-points/

//Simple Math (Geometry)
//T.C : O(n) - Checking all n points
//S.C : O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int steps = 0;
        
        for(int i = 0; i<n-1; i++) { //We have to reach the last point - points[n-1]
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            int x2 = points[i+1][0];
            int y2 = points[i+1][1]; 
            
            int dx = abs(x2-x1);
            int dy = abs(y2-y1);
            
            
            int diagonal = min(dx, dy);
            int remain   = abs(dx-dy);
            
            
            steps += diagonal + remain;
            
        }
        
        return steps;
        
    }
};
