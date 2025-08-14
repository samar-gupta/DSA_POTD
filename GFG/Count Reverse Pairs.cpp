//Approqch-1 : 
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    int countRevPairs(vector<int> &nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
    int mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        
        int m = l + (r - l) / 2;
        int count = mergeSort(nums, l, m) + mergeSort(nums, m + 1, r);

        int j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - m - 1);
        }

        merge(nums, l, m, r);
        return count;
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        
        while (i <= m) temp[k++] = nums[i++];
        while (j <= r) temp[k++] = nums[j++];
        
        for (i = l, k = 0; i <= r; i++, k++) {
            nums[i] = temp[k];
        }
    }
};
