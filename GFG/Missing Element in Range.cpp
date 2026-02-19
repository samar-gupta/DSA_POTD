//Approach-1 :
class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        set<int> s;
        for(int i = low; i <= high; i++){
            s.insert(i);
        }
        for(int i = 0; i <arr.size(); i++){
            if(s.find(arr[i]) != s.end()) s.erase(arr[i]);
        }
        vector<int>ans(s.begin(),s.end());
        return ans;
    }
};


//Approach-2 : 
class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_map<int,int>u;
        vector<int>v;
        for(int i=0;i<arr.size();i++){
            u[arr[i]]++;
        }
        for(int i=low;i<=high;i++){
            if(u[i]==0){
                v.push_back(i);
            }
        }
        return v;
    }
};
