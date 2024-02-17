//Company Tags   : Microsoft, Google
//Leetcode Link  : https://leetcode.com/problems/furthest-building-you-can-reach/

//Approach-1 : (Recursion + Memo)      (MEMORY LIMIT EXCEED - Not Accepted)
//T.C : Without Memoization - O(2^(bricks + ladders)), With memoization - O(bricks * ladders)
//S.C : O(bricks * ladders) when we use memoization dp array
class Solution {
public:
    int n;
    vector<vector<int>> t;
    
    int solve(int idx, vector<int> &heights, int bricks, int ladders) {
        if(idx == n - 1) //we reached the last building and no need to move further
            return 0;
        
        if(t[bricks][ladders] != -1)
            return t[bricks][ladders];
        
        if(heights[idx] >= heights[idx + 1]) { //No need to use anything. Just move ahead
            t[bricks][ladders] = 1 + solve(idx+1, heights, bricks, ladders);
        } else {
            
            int byBrick  = 0;
            int byLadder = 0;
            if(bricks >= heights[idx + 1] - heights[idx])
                byBrick  = 1 + solve(idx+1, heights, bricks - (heights[idx+1] - heights[idx]), ladders);
            
            if(ladders > 0)
                byLadder = 1 + solve(idx+1, heights, bricks, ladders - 1);
            
            t[bricks][ladders] = max(byBrick, byLadder);
        }
        
        return t[bricks][ladders];
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size(); 
        
        t = vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1));

        return solve(0, heights, bricks, ladders);
    }
};





//Approach-2 : (This is actually a concept of Lazy Greedy Problem (Using priority_queue))
//Accepted Approach Using Lazy Greedy
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {      
        int n = heights.size();
    
        priority_queue<int> pq;
        
        int i = 0;
        for(;i < n-1;i++) {
            if(heights[i] >= heights[i+1]) {
                continue;
            }
            
            int diff = heights[i+1]-heights[i];
            if(diff <= bricks) {
                bricks -= diff;
                pq.push(diff); //I used diff bricks here (keep track of it)
            } else if(ladders > 0) {
                if(!pq.empty()) {
                    int max_bricks_past = pq.top();
                    if(max_bricks_past > diff) {
                        //it means i unneccasrily used huge bricks in past. Let's get it back
                        bricks += max_bricks_past;
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;                  //ladders--   
                    }                                   //ladders--   (or just using one ladders-- instead of three for clean code)
                }
                ladders--; //either used in past or present
            } else {
                break;
            }
        }
      
        return i;
    }
};
