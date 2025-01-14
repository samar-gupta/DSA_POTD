//Leetcode Link : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        for(int i = 0 ; i < n; i++) {
            int count = 0;

            for(int x = 0; x <= i; x++) { //A
                //Find if we have A[x] in B or not till index i
                for(int y = 0; y <= i; y++) { //B
                    if(B[y] == A[x]) {
                        count++;
                        break;
                    }
                }
            }

            result[i] = count;

        }

        return result;
    }
};


//Approach-2 (Better Approach)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        vector<bool> isPresentA(n+1, false); //isPresent[i] = true, means i is present in A
        vector<bool> isPresentB(n+1, false); //....

        for(int i = 0; i < n; i++) {
            isPresentA[A[i]] = true;
            isPresentB[B[i]] = true;

            int count = 0;
            for(int num = 1; num <= n; num++) {
                if(isPresentA[num] == true && isPresentB[num] == true) {
                    count++;
                }
            }

            result[i] = count;
        }

        return result;
    }
};


//Approach-3 (Optimal Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        unordered_map<int, int> mp;

        int count = 0;
        for(int i = 0; i < n; i++) {
            mp[A[i]]++;
            if(mp[A[i]] == 2) {
                count++;
            }

            mp[B[i]]++;
            if(mp[B[i]] == 2) {
                count++;
            }

            result[i] = count;
        }

        return result;
    }
};
