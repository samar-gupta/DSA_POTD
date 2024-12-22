//Leetcode Link : https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/

//Approach-1 : (Using Priority queue)
//T.C : O(nlogn)
//S.C : O(n) 
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = q.size();
        vector<int> ans(n,-1);
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({max(q[i][0],q[i][1]),i});
        }
        
        sort(v.begin(),v.end());
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        int j=0;
        
        for(int i=0;i<h.size();i++){
            
            while( j<n && v[j].first <= i ){
                int ind = v[j].second;
                
                if( h[ max(q[ind][0],q[ind][1]) ] > h[ min(q[ind][0],q[ind][1]) ] ) 
                    ans[ind] = i;
                else if( q[ind][0]==q[ind][1] ) 
                    ans[ind] = i;
                else
                pq.push({ max(h[q[ind][0]],h[q[ind][1]]) , ind});
                
                j++;
            }
            
            while( pq.size() && pq.top().first < h[i] ){
                ans[pq.top().second] = i;
                pq.pop();
            }
            
        }
        
        return ans;
    }
};
