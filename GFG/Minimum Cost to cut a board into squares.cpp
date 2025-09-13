/* IDEA:
    1) Phle question smjho, hme ek M * N size ka board de rkha hai aur hme hr ek edge ke
    according cutting piece de rkhi hai. 
    2) Hmara task hai ki hme uss M * N size ke board ko M * N number of pieces main break
    krna hai, aur iss tarah break krna hai ki cost minimum ho.
    
    3) this is a greedy problem, see we know intially that piece is 1 (means only board).
    4) since we want to minimise our cost, so we will try to spend the maximum value cost 
    when we have minimum number of pieces. (most important line)
    5) That means we will sort the array in decreasing order and then start cutting the board.
    6) Becuase intially we have a single piece only.
    7) Intially we have a single horizontal piece and a single vertical piece.
    8) Now, If we want to make a cut in x directon, then we have to multiply it 
    with vertical number of piece, 
    like this (visuliaze)
    
             (this three vertical piece we have and we want to make a horizontal cut)
              ⇝ ⇝ ⇝ ⇝ ⇝ (like this) so, see we multiply it with vertical pieces
              |   |   |     (we multily with 3, because we have three verical piece here)
              |   |   |
              
              and after making a horizontal cut, horizontal numberof pieces will increase
              |   |   | 
              ⇝ ⇝ ⇝ ⇝ ⇝ (like this) so we increase horizontal pieces, 
              |   |   |
    
    
    9) Now, If we want to make a cut in y directon, then we have to multiply it 
    with horizontal number of piece, 
    same can be visuliaze in making vertical cuts, 
          (↓↓↓↓↓) (like this) so, see we multiply it with horizontal pieces
          -------------
          -------------
          
           and after making a vertical cut, vertical number of pieces will increase
            ----  ↓↓↓ ----
            ----  ↓↓↓ ----   (like this) so we increase vertical pieces,
*/
//Approach-1 : (Greedy using Sorting)
//T.C : O(n*logn + m*logm)
//S.C : O(1)
class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.begin(), x.end(), greater<int>()); // sort in decreasing order
        sort(y.begin(), y.end(), greater<int>()); // sort in decreasing order
        
        int horizonatalPieces = 1, verticalPieces = 1;
        
        int i = 0, j = 0;
        int ans = 0;
        
        while(i < x.size() && j < y.size())
        {
            if(x[i] >= y[j])
            {
                ans += (x[i] * verticalPieces);
                horizonatalPieces++;
                i++;
            }
            else 
            {
                ans += (y[j] * horizonatalPieces);
                verticalPieces++;
                j++;
            }
        }
        
        while(i < x.size())
        {
            ans += (x[i] * verticalPieces);
            horizonatalPieces++;
            i++;
        }
        
        while(j < y.size())
        {
            ans += (y[j] * horizonatalPieces);
            verticalPieces++;
            j++;
        }
        
        return ans;
    }
};
