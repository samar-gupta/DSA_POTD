//Approach:
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size();
        int m = b.size();
        int low = min(a[0], b[0]), high = max(a[n-1], b[m-1]);
        
        while(low < high){
            int mid = (low + high)/2;
            
            int x = upper_bound(a.begin(), a.end(), mid)-a.begin();
            int y = upper_bound(b.begin(), b.end(), mid)-b.begin();
            
            if(x+y < k) low = mid+1;
            else high = mid;
        }
        
        return low;
    }
};


//Approach:
class Solution {
public:
    // Counts how many elements in arr are <= val
    int helper(const vector<int>& arr, int val) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= val) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;  // Number of elements <= val
    }

    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int size_a = a.size();
        int size_b = b.size();

        // Handle edge cases: arrays might be empty
        if (size_a == 0) return b[k - 1];
        if (size_b == 0) return a[k - 1];

        int low = min(a[0], b[0]);
        int high = max(a[size_a - 1], b[size_b - 1]);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = helper(a, mid) + helper(b, mid);

            if (count >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;  // low is the k-th smallest element
    }
};



//old
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
