//Approach-1:
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        vector<int> v;
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        for(int i=0; i<k; i++) {
            mp[arr[i]]++;
        }
        v.push_back(mp.size());
        
        for(int right=k; right<n; right++) {
            mp[arr[left]]--;
            if(mp[arr[left]] == 0) {
                mp.erase(arr[left]);
            }
            left++;
            
            mp[arr[right]]++;
            v.push_back(mp.size());
        }
        
        return v;
    }
};


//Approach-2:
class Solution {
  public:
    vector<int> countDistinct(vector<int> &A, int k) {
        // code here.
        int n = A.size();
        vector<int> v;
        unordered_map<int,int> mp;
        int i=0,j=0;
        while(j<n)
        {
            mp[A[j]]++;
            if(j-i+1==k)
            {
                v.push_back(mp.size());
                mp[A[i]]--;
                if(mp[A[i]]==0)
                mp.erase(A[i]);
                i++;
            }
            j++;
        }
        return v;
    }
};
