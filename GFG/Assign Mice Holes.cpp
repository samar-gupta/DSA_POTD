//Approach-1 : (Sorting)
//T.C : O(nlogn) + O(n)
//S.C : O(1)
class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int res = 0;
        for (int i = 0; i < (int)mices.size(); i++) {
            res = max(res, abs(mices[i] - holes[i]));
        }
        
        return res;
    }
};
