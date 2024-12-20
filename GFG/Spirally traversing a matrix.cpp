//Approach-1 : 
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        vector<int> ans;
        int top=0;
        int left=0;
        int right= matrix[0].size()-1;
        int bottom=matrix.size()-1;
        
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int j=top;j<=bottom;j++){
                ans.push_back(matrix[j][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if(left<=right){
                for(int j=bottom;j>=top;j--){
                    ans.push_back(matrix[j][left]);
                }
            }
            left++;
        }
    
        return ans;
    }
};


//Approach-2 :
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        int left=0,right=m-1,bottom=n-1,top=0;
       int direction=1;
       vector<int> v;
       while(left<=right && top<=bottom)
       {
           if(direction==1)
           {
               for(int i=left;i<=right;i++) 
                   v.push_back(matrix[top][i]);
               direction=2;
               top++;
           }
           
           else if(direction==2)
           {
               for(int i=top;i<=bottom;i++)
                   v.push_back(matrix[i][right]);
               direction=3;
               right--;
           }
           
           else if(direction==3)
           {
               for(int i=right;i>=left;i--)
                   v.push_back(matrix[bottom][i]);
               direction=4;
               bottom--;
           }
           
           else if(direction==4)
           {
               for(int i=bottom;i>=top;i--) 
                   v.push_back(matrix[i][left]);
               direction=1;
               left++;
           }
       }
       return v;
    }
};
