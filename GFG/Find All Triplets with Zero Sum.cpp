//Approach-1 : 
//T.C : O(n^3)
//S.C : (1) //not including result vector
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>> ans;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(arr[i]+arr[j]+arr[k] == 0){
                        ans.push_back({i, j, k});
                    }
                }
            }
        }
        
        return ans;
    }
};


//Approach-2 :
//T.C : O(n*n* count of same element)
//S.C : O(n*count of same element)
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> result;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = -1 * (arr[i] + arr[j]);       //arr[i]+arr[j]+arr[k]=0   =>   arr[k] (target) = -(arr[i]+arr[j])
                if (mp.find(target) != mp.end()) {
                    for (int idx : mp[target]) {
                        if (i < idx && j < idx) {
                            result.push_back({i, j, idx});
                        }
                    }
                }
            }
        }
        return result;
    }
};


//Approach-1 : (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>>result;
        
        for(int i=0;i<arr.size();i++) {
            for(int j=i+1;j<arr.size();j++) {
                for(int k=j+1;k<arr.size();k++) {
                    
                    if(arr[i]+arr[j]+arr[k]==0) {
                      result.push_back({i,j,k});
                    }
                    
                }
            }
        }
        
        return result;
    }
};


//Approach-2 : (Using Hashmap)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>> ans; // To store the result triplets
        unordered_map<int, vector<int>> mp; // Hashmap to store each element and its indices

        // Step 1: Populate the hashmap with each element and its corresponding index
        for(int i = 0; i < arr.size(); ++i) {
            mp[arr[i]].push_back(i);
        }

        // Step 2: Iterate through each pair (i, j) using two nested loops
        for(int i = 0; i < arr.size(); ++i) {
            for(int j = i + 1; j < arr.size(); ++j) {
                int tt = arr[i] + arr[j];  // Calculate the sum of the current pair
                int req = -tt;             // Calculate the required third element to make the sum zero

                // Check if the required element exists in the hashmap
                if(mp.find(req) != mp.end()) {
                    for(int x : mp[req]) { // Iterate over all indices of the required element
                        // Ensure that the indices satisfy i < j < k
                        if(x != i && x != j && i < j && j < x) {
                            vector<int> temp = {i, j, x}; // Form the triplet
                            ans.push_back(temp);          // Add the triplet to the result
                        }
                    }
                }
            }
        }

        return ans; // Return all the valid triplets
    }
};
