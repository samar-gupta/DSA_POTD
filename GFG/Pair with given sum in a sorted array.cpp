//Approach-1 : 
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        unordered_map<int, int> mp;
        int count = 0;
        
        for (int i = 0; i < arr.size(); i++) 
        {
            int cp = target - arr[i];
            if (mp.find(cp) != mp.end()) 
            {
                count += mp[cp];
            }
            mp[arr[i]]++;
        }
        
        return count;
    }
};


//Apprapch-2 : 
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int i=0 , j=n-1;
        int count = 0;
        while(i<j){
            if(arr[i] + arr[j] == sum) {
                count++;
                i++;
                j--;
            } else if(arr[i]+arr[j] > sum) {
                j--;
            } else {
                i++;
            }
        }
        if(count != 0)
            return count;
        else
            return -1;
    }
};
