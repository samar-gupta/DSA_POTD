//Leetcode Link : https://leetcode.com/problems/check-if-n-and-its-double-exist

//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && arr[i] == 2*arr[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};


//Approach-2 (Using extra space)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            if(st.find(arr[i]*2) != st.end()) {
                return true;
            } else if(arr[i]%2 == 0 && st.find(arr[i]/2) != st.end()) {
                return true;
            }
            st.insert(arr[i]);
        }

        return false;
    }
};


//Approach-3 (Using Binary Search)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int bSearch(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size()-1;

        int mid;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(arr[mid] == target) {
                return mid;
            } else if(arr[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return -1;
    }

    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        for(int i = 0; i < n; i++) {
            int j = bSearch(arr, 2*arr[i]);

            if(j != -1 && j != i) {
                return true;
            }
        }

        return false;

    }
};
