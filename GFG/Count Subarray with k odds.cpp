//Approach:
class Solution {
  public:
    int solve(vector<int>& arr, int k) {
        int n =  arr.size();
        int i = 0, j = 0, odd = 0, ans = 0;
        
        while(i<n) {
            if(arr[i] % 2 == 1) {
                odd++;
            }
            
            while(odd > k) {
                if(arr[j] % 2 == 1) {
                    odd--;
                }
                j++;
            }
            
            ans += (i-j+1);
            i++;
        }    
        
        return ans;
    }
    
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return solve(arr, k) - solve(arr, k-1);
    }
};


//Approach:
class Solution {
  public:
    int atMostK(vector<int>& arr, int k) {
        int l = 0, oddCount = 0, res = 0;
    
        for (int r = 0; r < arr.size(); r++) {
            if (arr[r] % 2 == 1)
                oddCount++;
    
            while (oddCount > k) {
                if (arr[l] % 2 == 1)
                    oddCount--;
                l++;
            }
    
            res += (r - l + 1);
        }
        return res;
    }
    
    int countSubarrays(vector<int>& arr, int k) {
        return atMostK(arr, k) - atMostK(arr, k - 1);
    }
};
