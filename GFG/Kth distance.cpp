//Approach-1 : 
//T.C : O(n^2)
//S.C : O(1)
class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        for(int i = 0; i < arr.size(); i++){
            for(int j = i+1; j < arr.size(); j++){
                if(arr[i] == arr[j] && j - i <= k){
                    return true;
                }
            }
        }
        return false;
    }
};


//Approach-2 :
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        int n = arr.size();
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++) {
            if(mp.find(arr[i])!=mp.end()) {
                if(i-mp[arr[i]]<=k) {
                    return true;
                }
            }
            
            mp[arr[i]]=i;
        }
        
        return false;
    }
};


//Approach-3 :
//T.C : O(N), where N is the size of the array. We perform a single pass through the array, and each operation (insert, erase, and lookup) on a set takes O(1) on average.
//S.C : O(k), as the set will hold at most k elements at any time.
class Solution {
public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // Use a set to track elements within the last 'k' positions
        set<int> st;

        // First pass: Check the first 'k' elements
        for (int i = 0; i < k; ++i) {
            // If the current element is already in the set, we have a duplicate
            if (st.count(arr[i])) return true;
            st.insert(arr[i]); // Add the element to the set
        }

        // Second pass: Sliding window from index 'k' to the end of the array
        for (int i = k; i < arr.size(); ++i) {
            // Check if the current element is a duplicate
            if (st.count(arr[i])) return true;

            // Remove the element that is 'k' distance away from the current index
            st.erase(arr[i - k]);

            // Add the current element to the set
            st.insert(arr[i]);
        }

        // If no duplicates are found within 'k' distance, return false
        return false;
    }
};


//Approach-4 : (Using Two Pointer)
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        int n = arr.size();
        int i = 0,j = 0;
        int count=0;
        while(i < n-1)
        {
            if(j<i+k && j<n-1)
            {
                j++;   
            }
            else
            {
                i++;
                j = i;
                count=0;
            }
            if(arr[i]==arr[j])
            {
                count++;
                if(count==2) return true;
            }
        }
        
        return false;
    }
};
