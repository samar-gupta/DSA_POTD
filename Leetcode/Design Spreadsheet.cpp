//Leetcode Link : https://leetcode.com/problems/design-spreadsheet

//Approach (Simple simulation)
// T.C. : Constructor → O(rows), setCell / resetCell → O(1), getValue → O(L) for substr where L = length of formula
// S.C. : O(1)
class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet.assign(rows, vector<int>(26, 0));    
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        sheet[row][col] = value;

    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }
    
    int solve(string &s) {
        if(isdigit(s[0])) {
            return stoi(s);
        }

        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;

        return sheet[row][col];
    }

    int getValue(string formula) {
        //Example : "=X+Y"
        string s = formula.substr(1); //remove =
        int plusIdx = s.find('+');

        string left = s.substr(0, plusIdx);
        string right = s.substr(plusIdx+1);


        return solve(left) + solve(right);
    }
};
