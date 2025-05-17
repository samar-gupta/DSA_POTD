//Approach-1 : 
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        vector<int>ans;
        for(auto it:arr){
            ans.push_back(A*it*it+B*it+C);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//Approach-2 : 
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n = arr.size();
        int mn = INT_MAX;
        int idx = -1;
        for(int i = 0; i < n; i++){
            int x = arr[i];
            arr[i] = A*x*x + B*x + C;
            if(arr[i] < mn){
                mn = arr[i];
                idx = i;
            }
        }
        
        vector <int> V;
        
        int i = idx;
        int j = (idx + 1) % n;
        
        while(V.size() != n){
            if(arr[i] < arr[j]) V.push_back(arr[i--]);
            else V.push_back(arr[j++]);
            
            if(i < 0) i = n-1;
            j = j % n;
        }
        
        return V;
    }
};
