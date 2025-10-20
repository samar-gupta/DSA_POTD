//Leetcode Link : https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/

//Approach-1 :
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        
        for(const string& op : operations) {
            if(op == "--X" || op == "X--") {
                x--;
            } else {
                x++;
            }
        }

        return x;
    }
};


//Approach-2 : (constant time checking)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        
        for(const string& op : operations) {
            if(op[1] == '-') //constant tome check
                x--;
            else
                x++;
        }

        return x;
    }
};
