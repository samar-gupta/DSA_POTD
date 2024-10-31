Leetcode Link : https://leetcode.com/problems/minimum-total-distance-traveled/

//Approach : (Recursion + Memo) , Adding multiple (exact count) factories at the position for ease
//Only Recursion : T.C : O(2^M+N) , S.C : O(M+N) (max depth of recursion stack tree)
//After Memo : T.C : O(M*N) , S.C : O(M*N)
class Solution {
    #define MAX 10000000000000LL
    using ll = long long;                          
    
    ll mincost(vector<int>& robot,int robo_pos, vector<int>& factories,int fact_pos,vector<vector<ll>>& mem){
        if(robo_pos<0)  return 0;   //If all robots are repaired
        if(fact_pos<0)  return MAX; //If some robots are left but factories are over
        if(mem[robo_pos][fact_pos]!=-1)
            return mem[robo_pos][fact_pos];

        ll include = abs(robot[robo_pos]-factories[fact_pos])
                     + mincost(robot,robo_pos-1,factories,fact_pos-1,mem);
        
        ll exclude = mincost(robot,robo_pos,factories,fact_pos-1,mem);

        return mem[robo_pos][fact_pos] = min(include,exclude);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        //Convert multi-instance factory to single instance
        vector<int> factories;
        for(int i=0;i<factory.size();++i){
            int pos = factory[i][0];
            int count = factory[i][1];
            for(int j=0;j<count;++j)
                factories.push_back(pos);
        }
        vector<vector<ll>> mem(robot.size(),vector<ll>(factories.size(),-1));
        return mincost(robot,robot.size()-1,factories,factories.size()-1,mem);
    }
};



//Approach-2 : 
class Solution {
public:
    typedef long long ll;
    
    ll solve(int ri, int fi, vector<int>& robot, vector<int>& positions, vector<vector<ll>>& t) { 
        if(ri >= robot.size()) {
            return 0; //no more distance to be covered
        }
        
        if(fi >= positions.size()) {
            return 1e12;
        }
        
        if(t[ri] [fi] != -1) {
            return t[ri] [fi];
        }
        
        ll take_current_factory = abs(robot[ri] - positions[fi]) + solve(ri+1, fi+1, robot, positions, t);
        ll skip = solve(ri, fi+1, robot, positions, t);
        
        return t[ri] [fi] = min(take_current_factory, skip);
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        //Step-1
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));
        
        int m = robot.size();
        
        //Step-2 (Expand factory positions to avoid tracking of limit and easy recursion)
        vector<int> positions;
        for(int i = 0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos = factory[i][0];
            
            for(int j = 0; j < limit; j++) {
                positions.push_back(pos);
            }
        }
        
        int n = positions.size();
        vector<vector<ll>> t(m+1, vector<ll>(n+1, -1));
        
        //step-3 (solve)
        return solve(0, 0, robot, positions, t);
    }
};
