class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int totalZero = 0;
        for (int x : arr){
            if (x == 0){
                totalZero++;
            }
        }

        int leftOnes = 0;
        int rightZeros = totalZero;
        int ans = rightZeros;

        for (int x : arr) {
            if (x == 1)
                leftOnes++;
            else
                rightZeros--;
            ans = min(ans, leftOnes + rightZeros);
        }
        
        return ans;
    }
};
