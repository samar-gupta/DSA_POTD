//Approach-1 : 
//T.C : O(N)
//S.C : O(N)
class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int l=0, cnt=0;
        unordered_map<int,int> freq;
        for(int r=0;r<arr.size();r++){
            freq[arr[r]]++;
            while(freq.size()>k){
                freq[arr[l]]--;
                if(freq[arr[l]]==0) freq.erase(arr[l]);
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
};


//Approach-1 :
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int ans=0; int i=0; int j=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[arr[j]]++;
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                    mp.erase(arr[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};
