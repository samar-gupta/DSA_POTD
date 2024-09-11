Leetcode Link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

//Approach-1 (Bit by Bit check)
//T.C: O(1), maximum we will have 30 bits(as per constraint) to represent the numbers - O(30) ~ 0(1)
//S.C: O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        while(start > 0 || goal > 0) {
            //check right most bit of both if they are equal or not
            if((start & 1) != (goal & 1)) {
                count++;
            }
            
            //rule out the right most bit 
            start = (start >> 1); 
            goal = (goal >> 1);
        }
        
        return count;
    }
};



//Approach-2 (Using XOR)
//T.C: O(1)
//S.C: O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        //Basically we only have to count the bit positions where they both differ
        //XOR can easily help with that
        int XOR = start ^ goal;
        int count = 0;
        //XOR now contains 1 bit set in positions
        //where both bits were different in start and goal
        //So, simply count those
        
        while(XOR) {
            count += (XOR & 1); //If the right most bit is 1
            
            //shift right to rule out the right most bit 
            XOR = (XOR >> 1);
        }
        
        return count;
    }
};



//Approach-3 (Count bits in XOR using Brian Kernighan's Algorithm)
//T.C: O(1)
//S.C: O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        //Basically we only have to count the bit positions where they both differ
        //XOR can easily help with that
       
        int XOR = start ^ goal;
        int count = 0;
        
        //XOR now contains 1 bit set in positions
        //where both bits were different in start and goal
        //So, simply count those using Brian Kernighan's Algorithm
        while(XOR) {
            XOR = XOR & (XOR-1);
            //shift right to rule out the right most bit
            count++;
        }
        
        return count;
    }
};



//Approach-3 (count bits in XOR using_builtin_popcount())
//T.C: O(1)
//S.C: O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        //Basically we only have to count the bit positions where they both differ
        //XOR can easily help with that
        
        int XOR = start ^ goal;
        return_builtin_popcount(XOR); //simply count bits
    }
};
