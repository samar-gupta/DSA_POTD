//Approach-1 :
class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        map<int, vector<int>> mp;

        for (int num : arr) {
            int diff = abs(num - x);
            mp[diff].push_back(num);
        }

        int index = 0;
        for (auto& it : mp) {
            for (int num : it.second) {
                arr[index++] = num;
            }
        }
    }
};


//Approach-2 : 
class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};

/*
Q. Why can't we use only sort in place of stable sort in the answer?
Ans : bcuz according to the given examples ,where there are elements with same absolute difference , the one which occurs first in the input array do appear first in the output array. and stable sort means not disturbing the occurrence of the same elements i.e here the absolute difference. this is reason we use stable sort.
• Use sort when performance matters more and you don’t care about the relative order of equal elements. Worst TC = O(NlogN)
• Use stable_sort when the original order among equals must be preserved (like sorting people by age but keeping their input order if they’re the same age).Worst TC = O(Nlog^2*N)
• Personally , I don't prefer this solution for interviews it is more of showing of C++ in_built functions knowledge and one need to show off his algorithmic skills I will go for mergeSort.
*/
//working code
class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        stable_sort(arr.begin(), arr.end(), [&](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};
