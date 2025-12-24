//Approach: Using Binary Search || O(logN) Time || O(1) Space
class Solution {
public:
    int getPivot(vector<int>& arr, int st, int en) {
        if (st >= en)
            return st;
        int mid = (st + en) / 2;
        if (arr[mid] > arr[en])
            return getPivot(arr, mid + 1, en);
        return getPivot(arr, st, mid);
    }
    
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int pivot = getPivot(arr, 0, n - 1);
        if (pivot)
            return (upper_bound(arr.begin(), arr.begin() + pivot, x) -
                    arr.begin()) +
                   (upper_bound(arr.begin() + pivot, arr.end(), x) -
                    (arr.begin() + pivot));
        return upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    }
};


//Approach: 
/*
First find the point of separation 
i.e. pivot element where array is divided into 
left sorted half and right sorted half, 
then either you can use upper bound or do binary search. 
Binay search is more preferred than STL functions. 
Count numbers <= x and return them
*/
class Solution {
public:
    int findpivot(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {  
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int countLE(vector<int>& arr, int l, int r, int x) {
        int last = -1;
        int start = l;         

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= x) {
                last = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (last == -1) return 0;
        return last - start + 1;
    }

    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int pivot = findpivot(arr);

        int leftcnt = countLE(arr, 0, pivot - 1, x);
        int rightcnt = countLE(arr, pivot, n - 1, x);

        return leftcnt + rightcnt;
    }
};
