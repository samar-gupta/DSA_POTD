/*
To solve this problem efficiently, 
we can utilize the sorted nature of each row in the binary matrix. 
Instead of counting the number of 1s in each row individually, 
we can traverse the matrix column by column from left to right. 
As soon as we encounter a 1, we can conclude that the current row is the first row with the maximum number of 1s. 
This method ensures an optimal solution with a time complexity of O(n*m), 
where n is the number of rows and m is the number of columns.
*/
//Approach:
//Traverse column-wise, i.e. find number 1 in each column 
//and if find just return cuz the array is sorted 
//and we have to retrn the first row.
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        for(int j=0; j<arr[0].size(); j++){
            for(int i=0; i<arr.size(); i++){
                if(arr[i][j]==1){
                    return i;
                }
            }
        }
        return -1;
    }
};


//Approach: 
/*
Understanding the Problem:
We have a 2D boolean array where each row is sorted (all 0s are to the left and all 1s are to the right).
We need to find the index of the row with the maximum number of 1s. If there is a tie, return the lower index.

Key Insight:
Since rows are sorted, encountering a 0 means all elements to its left are also 0s.
Encountering a 1 means all elements to its right are also 1s.

Optimal Traversal Strategy:
  Starting Point:
    Begin at the top-right corner of the matrix (first row, last column).
  Movement Logic:
    If the current element is 1:
      Move left to potentially find more 1s in the same row.
      Update the tracker to the current row index, as this row has the most 1s so far.
    If the current element is 0:
      Move down to the next row since this row cannot have more 1s than already found.

Why This Traversal Works:
Efficiency:
  Starting from the top-right allows us to:
    Move left to explore all potential 1s in the current row.
    Move down to skip rows that can't improve the maximum count of 1s found so far.
  Ensures finding the first row (lowest index) with the most 1s efficiently.
*/
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n =arr.size();
        int m=arr[0].size();
             
        int maxRow = -1; 
        int row = 0; 
        int col = m - 1; 
 
        while (row < n && col >= 0) {
            if (arr[row][col] == 1) {
                maxRow = row;            //updating row value
                col--;      
            } else {
                row++;                 //switch to next row
            }
        }
    
        return maxRow;
    }
};



//old
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        int ans=-1;
        int n=arr.size();
        int m=arr[0].size();
        int i=0;
        int j=m-1;
        while(i<n && j>=0){
            if(arr[i][j]==1){
                ans=i;
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
