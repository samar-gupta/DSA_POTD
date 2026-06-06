class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        int flips = 0;
    
        while(pos > 1) {
            // 2nd child (even), isnt like parent
            if((pos & 1) == 0) {
                flips++;
            }
        
            // Parent index, 1&2 -> 1, 3&4 -> 2
            // When we half the pos, its essentially going up, the first half of current level is same as previous level
            // So pos == 1, is level 1, so is the limit
            pos = (pos + 1) / 2;
        }
    
        // Starts with E, in 1 flip -> D, in 2 flips again -> E
        return ((flips & 1) == 0) ? "Engineer" : "Doctor";
    }
};
