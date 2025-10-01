//Approach-1 : (Using Recursion)
class Solution {
  public:
    void helper(vector<int> &A, int curr, int n,set<vector<int>> &s){
        if(curr>=n){
            s.insert(A);
            return;
        }
        for(int i=curr;i<n;i++){
            swap(A[curr],A[i]);     //swap
            helper(A,curr+1,n,s);  //deal with it
            swap(A[curr],A[i]);   //return back to previous state
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int>& A) {
        // code here
        int n = A.size();
        set<vector<int>> s;
        vector<vector<int>> res;
        helper(A,0,n,s);
        for(auto itr: s){
            res.push_back(itr);
        }
        return res;
    }
};


//Approach-1 : (Using recursion)
class Solution {
  public:
  
    set<vector<int>>st;
    
    void solve (int index, vector<int> &arr , int n){
        // Base Case : if the current index reached n then insert it to the set
        if(index == n) {
            st.insert(arr);
            return ;
        }
        
        for(int i=index; i<n; i++){
            // avoiding duplicate elements
            if(i!= index && arr[index] == arr[i])
                continue;
            swap(arr[i], arr[index] );
            // calling the recursive function
            solve(index+1, arr , n);
            // backtracking
            swap(arr[i], arr[index] );
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        int n = arr.size();
        // to avoid duplicate values
        sort(arr.begin(), arr.end());
        // calling the recursive function
        solve(0, arr , n);
       
        // inserting all permutaions in set into the answer vector
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};


//Approach-2 : (Using using next_permutation inbuild function)
//next_permutaion is an funtion that creates the permutation automatically in the greater lexicographic way.
class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        ans.push_back(arr);
        while(next_permutation(arr.begin() , arr.end())) ans.push_back(arr); 
        return ans;
    }
};



//old
class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        ans.push_back(arr);
        st.insert(arr);
        if(n==1) return ans;
        while(true){
            int ind = -1;
            for(int i = n-2; i>=0; i--){
                if(arr[i]<arr[i+1]){
                    ind = i;
                    break;
                }
            }
            for(int i = n-1; i > ind && ind!=-1; i--){
                if(arr[i] > arr[ind]){
                    swap(arr[i], arr[ind]);
                    break;
                }
            }
            reverse(arr.begin()+ind+1, arr.end());
            if(st.find(arr)!=st.end()) 
                break;  
            ans.push_back(arr);
            st.insert(arr);
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};
