//Approach-1 : 
//T.C : O(n) + O(nlogn) + O(n) ~ O(nlogn)
//S.C : O(n)
class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int target = (n + 1) / 2; 
        
        int count = 0;
        vector<int> req;
        
        for (int num : arr) {
            if (num % k == 0) count++;
            else req.push_back(k - (num % k));
        }
        
        if (count >= target) return 0;
        
        sort(req.begin(), req.end());
        
        int res = 0;
        int need = target - count;
        
        for (int i = 0; i < need; i++) {
            res += req[i];
        }
        
        return res;
    }
};
