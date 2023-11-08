/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/
*/

/*********************************************** C++ *****************************************************/
//Approach-2 (Using Maths)
//T.C : O(1)
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int hor_dist = abs(sy-fy);

        int vert_dist = abs(sx-fx);

        if(hor_dist == 0 && vert_dist == 0 && t == 1) {
            return false;
        }

        int min_time = max(hor_dist, vert_dist);

        if(t < min_time) 
            return false;

        return true;                       //(one line answer) -->   return t >= max(vert_dist, hor_dist);
    }
};






//Approach - 1 (Brute Force : Won't work with High Contraints - Infinte Board)
class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
    
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx < 0 || sy < 0) {
            return false;
        }
        
        if(t == 0) {
            return sx == fx && sy == fy;
        }
        
        for(auto &dir : directions) {
            int sx_ = sx + dir[0];
            int sy_ = sy + dir[1];
            
            if(isReachableAtTime(sx_, sy_, fx, fy, t-1))
                return true;
        }
        
        return false;
        
    }
};
