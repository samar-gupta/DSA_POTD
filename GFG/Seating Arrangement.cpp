class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        const int size = seats.size();
    
        // Edge Cases
        if(k > size) {
            return false;
        }
        if(k == 0) {
            return true;
        }
        if(size == 1) {
            return (seats[0] == 0);
        }
    
        // First and last
        if(seats[0] == 0 && seats[1] == 0) {
            seats[0] = 1;
            k--;
        }
        if(seats[size-1] == 0 && seats[size-2] == 0) {
            seats[size-1] = 1;
            k--;
        }
    
        // Rest all
        for(int i = 1; i < size-1; i++) {
            if(seats[i-1] == 0 && seats[i] == 0 && seats[i+1] == 0) {
                seats[i] = 1;
                k--;
            }
        }
    
        return (k <= 0);
    }
};
