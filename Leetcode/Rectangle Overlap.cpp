//Leetcode Link : https://leetcode.com/problems/rectangle-overlap/description/

/* Intuition - 
  Two rectangles overlap only if their horizontal ranges and vertical ranges overlap.
  So, check that neither rectangle is completely to the left/right or above/below the other.
*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return recl[0] < rec2[2] && rec2[0] < recl[2] && 
            recl[1] < rec2[3] && rec2[1] < recl[3];
    }
};
