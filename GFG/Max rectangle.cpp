//Approach-1 : 
class Solution {
  public:
  
    int area(vector<int>heights){
        int n = heights.size();
        stack<int>st;
        int res=0;
        for(int i=0; i<n; i++){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                int t=st.top();
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                res=max(res,heights[t]*width);
            }
            st.push(i);
        }
        while(!st.empty()){
            int t=st.top();
            st.pop();
            int width=st.empty()?n:n-st.top()-1;
            res=max(res,heights[t]*width);
        }
        return res;
    }
    
    int maxArea(vector<vector<int>> &mat) {
        //code here
        vector<int>heights(mat[0].size(),0);
        int mxArea = 0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0) heights[j]=0;
                else heights[j]++;
            }
            mxArea = max(mxArea, area(heights));
        }
        return mxArea;
    }
};
