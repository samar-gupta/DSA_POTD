class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = n1 + n2;
        vector<int> ans;
        int i=0,j=0;
        
        while(i<n1 && j<n2){
            if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else{
                ans.push_back(arr2[j++]);
            }
        }
        while(i<n1){
            ans.push_back(arr1[i++]);
        }
        while(j<n2){
            ans.push_back(arr2[j++]);
        }
        
        int sum = 0;
        
            int mid1 = n/2;
            int mid2 = mid1-1;
            sum = ans[mid1] + ans[mid2];
            
        return sum;
    }
};



//Short
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        
        int n = arr1.size();
        sort(arr1.begin(), arr1.end());
        int sum = arr1[n/2] + arr1[(n/2) -1];
        return sum;
    }
};
