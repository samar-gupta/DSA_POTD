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
