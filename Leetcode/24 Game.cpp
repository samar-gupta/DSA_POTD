//Company Tags  : Google
//Leetcode Link : https://leetcode.com/problems/24-game/description

//Approach (Khandani Backtracking template and all possible options)
//T.C : O(1), size of input is constant and of size 4
//S.C : O(1), size of input is constant and of size 4
class Solution {
public:
    double epsilon = 0.1; //0.01, 0.001 etc will work too.
    // Tolerance for floating-point comparison. To avoid floating point precission errors 

    bool solve(vector<double>& cards) {
        if(cards.size() == 1) {
            return abs(cards[0] - 24) <= epsilon;
        }

        //pick two possible numbers
        for(int i = 0; i < cards.size(); i++) {
            for(int j = 0; j < cards.size(); j++) {
                if(i == j)
                    continue;
                
                vector<double> temp;
                for(int k = 0; k < cards.size(); k++) {
                    if(k != i && k != j) {
                        temp.push_back(cards[k]);
                    }
                }

                double a = cards[i];
                double b = cards[j];
                vector<double> possibleVal = {a+b, a-b, b-a, a*b};

                if(abs(b) > 0.0) {
                    possibleVal.push_back(a/b);
                }

                if(abs(a) > 0.0) {
                    possibleVal.push_back(b/a);
                }

                for(double val : possibleVal) {
                    temp.push_back(val); //Do
                    if(solve(temp) == true) //Explore
                        return true;
                    temp.pop_back(); //Undo
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i = 0; i < cards.size(); i++) {
            nums.push_back(1.0 * cards[i]);
        }
        return solve(nums);
    }
};
