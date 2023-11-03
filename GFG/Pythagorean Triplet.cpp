//Approach - 1
class Solution{
public:
	// Function to check if the Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    for(int i=0; i<n; i++) {
	        arr[i] = arr[i] * arr[i];
	    }
	    
	    unordered_set<int> st(arr, arr+n);
	    
	    for(int i = 0; i<n; i++) {
	        for(int j=i+1; j<n; j++) {
	            if(st.find(arr[i]+arr[j]) != st.end()) return true;
	        }
	    }
	    return false;
	}
};




//Approach - 2
class Solution{
public:
	bool checkTriplet(int arr[], int n) {
	    if(n<3) return false;
	    sort(arr,arr+n);
	    for(int i=0;i<n;i++) arr[i]=arr[i]*arr[i];
	    
	    for(int k=n-1;k>=2;k--){
	        int i=0,j=k-1;
	        while(i<j){
	            if(arr[i]+arr[j]==arr[k]) return true;
	            else if(arr[i]+arr[j]<arr[k]) i++;
	            else j--;
	        }
	    }
	    return false;
	}
};
