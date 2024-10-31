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
