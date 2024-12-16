//Approach-1 : 
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        int m=b.size();
        
        int ans=0,i=0,j=0;
        while(k>0 && i<n && j<m){
            if(a[i]<b[j]){
                ans=a[i];
                i++;
            }
            else{
                ans=b[j];
                j++;
            }
            k--;
        }
        
        while(k>0 && i<n){
            ans=a[i];
            i++;
            k--;
        }
        
        while(k>0 && j<m){
            ans=b[j];
            j++;
            k--;
        }
        
        return ans;
    }
};


//Approach-2 :
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
         int n1 = arr1.size() , n2 = arr2.size() ;
        if(k == n1+n2)return max(arr1[n1-1],arr2[n2-1]);
        if(k==1)return min(arr1[0],arr2[0]);
        int i = 0 , j = 0 ;
        while(i<n1 && j<n2 && k>1){
            if(arr1[i]<=arr2[j]){
                i++;
            }
            else j++;
            k--;
        }
        
        while(i<n1 && k>1){
            i++;
            k--;
        }
        while(j<n2 && k>1){
            j++;
            k--;
        }
        if(i==n1)return arr2[j];
        else if(j==n2)return arr1[i];
        return min(arr1[i],arr2[j]);
    }
};
