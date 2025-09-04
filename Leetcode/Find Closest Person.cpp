//Leetcode Link : https://leetcode.com/problems/find-closest-person/

//Approach-1 : 
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(x-z);
        int b = abs(y-z);
        if(a == b) {
            return 0;
        } else if(a < b) {
            return 1;
        }

        return 2;
    }
};


//Approach-1 : 
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(x-z);
        int b = abs(y-z);
        return a==b ? 0 : 2 - (a < b);
    }
};
