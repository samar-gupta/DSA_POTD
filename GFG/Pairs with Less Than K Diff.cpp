//Approach-1 : 
class Solution {
  public:
    int countPairs(vector<int>& a, int k) {
        // code here
        int n = a.size();
        int count = 0;
        sort(begin(a), end(a));
        int i = 1;
        int j = 0;
        while(i < n){
            while(a[i] - a[j] >= k){
                j++;
            }   
            if((a[i] - a[j]) < k){
                count = count + (i - j);
            }
            i++;
        }
        return count;
    }
};



//Approach-2 : 
class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        int ans=0;
        sort(arr.begin(), arr.end());
      
        int n=arr.size();
        for(int i=0; i<n; i++){
            int li = lower_bound(arr.begin(), arr.end(), arr[i]+k) - arr.begin();
            if((li-1-i) > 0) ans+=(li-1-i);
        }
      
        return ans;
    }
};
