//Approach-1 : TLE
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += arr[(i + j)%n];
            }
            ans = max(ans, sum);
        }
        
        return ans;
    }
};


//Approach-2 : (Slicing Window)
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += arr[(i + j)%n];
            }
            ans = max(ans, sum);
        }
        
        return ans;
    }
};


//Approach-2 :
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        
        int sum = 0;
        
        // First window
        for (int i = 0; i < m; i++) {
            sum += arr[i];
        }
        
        int ans = sum;
        
        // Slide the window
        for (int i = 1; i < n; i++) {
            sum -= arr[i-1];
            sum += arr[(i+m-1) % n];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
