//Approach-1 : (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int N = mat.size();
        int M = mat[0].size();
        
        int flag=0;
        
        for(int i=0; i<N; i++){ 
            for(int j=0; j<M; j++){ 
                if(mat[i][j] == x){
                    flag=1;
                }
            }    
        }
        
        return flag;
    }
};


//Approach-2 : (Binary Search)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int X) {
        // your code here
        int N = mat.size();
        int M = mat[0].size();
        
        int flag=0;
        for(int i=0;i<N;i++){
            int start=0;
            int end=M-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(mat[i][mid]==X){
                    flag=1;
                    break;
                }
                else if(mat[i][mid]<X){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return flag;
    }
};


//Approach-3 : 
//T.C : O(n + m)
//S.C : O(1)
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int X) {
        // your code here
        int N = mat.size();
        int M = mat[0].size();
        
        int row  = 0;
        int col = M-1;

        while(row < N && col >= 0){
            if(mat[row][col] == X){
                return 1;
            }else if(mat[row][col] > X){
                col--;
            }else{
                row++;
            }
        }

        return 0;
    }
};
