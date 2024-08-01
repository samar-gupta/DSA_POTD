class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(string &detail : details) {
            int secondDigit = detail[11] - '0';
            int firstDigit  = detail[12] - '0';

            int age    = secondDigit*10 + firstDigit;

            if(age > 60)
                count++;
        }

        return count;
    }
};
