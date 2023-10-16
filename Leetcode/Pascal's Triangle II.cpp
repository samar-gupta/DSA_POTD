/*
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/pascals-triangle-ii/
*/

/********************************************* C++ *********************************************/

//Approach-1 (Using the same code of Pascal's Triangle-I
//T.C : O(rowIndex * rowIndex)
//S.C : O(rowIndex * rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);
        
        for(int i = 0; i<rowIndex+1; i++) {
            
            result[i] = vector<int>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                
                result[i][j] = result[i-1][j] + result[i-1][j-1];
                
            }
            
            if(i == rowIndex) //Just return when you find rowIndex
                return result[i];
            
        }
        
        return {};
    }
};



//Approach-2 (Using less space from Approach-1 above)
//We only need prev array to find current result
//T.C : O(rowIndex * rowIndex)
//S.C : less than O(rowIndex * rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        
        for(int i = 0; i<rowIndex+1; i++) {
            
            vector<int> curr = vector<int>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                
                curr[j] = prev[j] + prev[j-1];
                
            }
            prev = curr;
        }
        
        return prev;
    }
};
