//Leetcode Link : https://leetcode.com/problems/maximize-active-section-with-trade-i

//Approach (target 1s and find max pair sum of zero blocks)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        //existing count of 1s
        int activeCount = count(begin(s), end(s), '1');

        vector<int> inactiveBlocks;
        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0') i++;

                inactiveBlocks.push_back(i-start);
            } else {
                i++;
            }
        }

        int maxPairSum = 0;
        //max(inactiveBlocks[i] + inactiveBlocks[i-1])
        for(int i = 1; i < inactiveBlocks.size(); i++) {
            maxPairSum = max(maxPairSum, inactiveBlocks[i] + inactiveBlocks[i-1]);
        }

        return maxPairSum + activeCount;
    }
};
