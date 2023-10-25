class Solution{
public:

    int t[1001][1001];
    int solve(int N, int W, int val[], int wt[]) {
        if(N == 0 || W == 0) 
            return 0;
            
        if(t[N][W] != -1)
            return t[N][W];
        
        if(wt[N-1] <= W) {
            return t[N][W] = max(val[N-1] + solve(N, W-wt[N-1], val, wt), solve(N-1, W, val, wt));
        } else {
            return t[N][W] = solve(N-1, W, val, wt);
        }
    }

    int knapSack(int N, int W, int val[], int wt[]) 
    {
        memset(t, -1, sizeof(t));
        return solve(N, W, val, wt);
    }
};
