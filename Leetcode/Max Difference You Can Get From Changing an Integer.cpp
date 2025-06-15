//Leetcode Link : https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/

//Approach (replacing with 9 for maximum and carefully minimizing the number using greedy)
//T.C : O(log10(num))
//S.C : O(log10(num))
class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        //We can't directly choose 0th index character and make it 0
        //because qn says we can't have leading zeros
        for(int i = 0; i < str2.length(); i++) {
            char ch = str2[i];
            if(i == 0) {
                if(ch != '1') {
                    replace(begin(str2), end(str2), ch, '1');
                    break;
                }
            } else if(ch != '0' && ch != str2[0]) {
                //example : 111, even if we skip 1 at str2[0], we see again at str2[1]
                //But we can't change 1 to 0 because it will replace 1 of str2[0] as well
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
        }
        return stoi(str1) - stoi(str2);
    }
};
