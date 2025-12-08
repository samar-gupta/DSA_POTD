//Approach
//Use HASHSET to store frequencies 
//and find the freq which are repeated twice as per the question 
//and store them into the vector.
class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int,int> hashset;
        vector<int> res;
        for(auto x:arr){
            hashset[x]++;
        }
        for(auto pair:hashset){
            if(pair.second==2){
               res.push_back(pair.first);
            }
        }
        if(!res.empty()){
            return res;
        }
        else{
            return {};
        }
    }
};


//old
// "Cyclic Sort" has T.C - O(n) but with condition that elements are 0-(n-1) for size N , normal sort has O(nlogn)
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        
        vector<int> ans;
        
        int i=0;
        while(i<n) {
            if(arr[i]==-1 || arr[i]==i) i++;
            else {
                if(arr[i] == arr[arr[i]]) {
                    arr[arr[i]] = -1;
                    i++;
                }
                else if(arr[arr[i]] == -1) {
                    i++;
                }
                else {
                    swap(arr[i], arr[arr[i]]);
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(arr[i] == -1){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {-1};
        return ans;
    }
};
