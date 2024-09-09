//Leetcode Link : https://leetcode.com/problems/spiral-matrix-iv/description

//Simple SImulation
//T.C : O(m*n)
//S.C : O(1) (I am not considering the result matrix we have to return as result)
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int id    = 0; //0, 1, 2, 3
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;

        while(top <= down && left <= right) {
            if(id == 0) { //left to right
                for(int i = left; head != NULL && i <= right; i++) {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            if(id == 1) { //top to down
                for(int i = top; head != NULL && i <= down; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }

            if(id == 2) { //right to left
                for(int i = right; head != NULL && i >= left; i--) {
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }

            if(id == 3) { //down to top
                for(int i = down; head != NULL && i >= top; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            id = (id+1)%4; //0, 1, 2, 3
        }

        return matrix;
    }
};
