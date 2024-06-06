//Company Tags  : Google
//Leetcode Link : https://leetcode.com/problems/hand-of-straights

//Approach : (Simply using ordered map) (to get elements in sorted order)
//T.C  : O(nlogn) + O(n*groupSize)
//S.C  : O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize) {
            return false;
        }

        map<int, int> mp;
        for(int &handNumber : hand) {
            mp[handNumber]++; //O(nlogn)
        }

        while(!mp.empty()) { //O(n*groupSize)

            int curr = mp.begin()->first; //->second : frequency

            for(int i = 0; i < groupSize; i++) {
                if(mp[curr + i] == 0) {
                    return false;
                }

                mp[curr+i]--;
                if(mp[curr+i] < 1) {
                    mp.erase(curr+i);
                }
            }

        }

        return true;
    }
};
