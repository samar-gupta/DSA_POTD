//Leetcode Link : https://leetcode.com/problems/create-grid-with-exactly-one-path/description/

//Approach-1 : 
//T.C: O(m*n)
//S.C: O(n)
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string topRow(n, '.');
        string remaining = string(n-1, '#') + '.';
        
        vector<string> result;
        result.push_back(topRow);
        
        for(int i = 1; i < m; i++) {
            result.push_back(remaining); 
        }
        
        return result;
    }
};



//Approach-2 : 
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m,string(n,'#'));

        for(int i=0;i<n;i++){
            grid[0][i]='.';
        }
        for(int j=0;j<m;j++){
            grid[j][n-1]='.';
        }
        return grid;
    }
};
