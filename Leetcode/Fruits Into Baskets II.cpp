//Leetcode Link : https://leetcode.com/problems/fruits-into-baskets-ii/

//Approach-1 : 
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        int n = fruits.size();

        for(int i = 0; i < n; i++) {
            bool placed = false;
            for(int j = 0; j < n; j++) {
                if(fruits[i] <= baskets[j]) {
                    placed = true;
                    baskets[j] = 0;
                    break;
                }
            }
            if(!placed) {
                unplaced++;
            }
        }

        return unplaced;
    }
};


//Approach-1 : (Using greedy approach)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), alloted = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (fruits[i] <= baskets[j]) {
                    baskets[j] = -1; // mark basket as used
                    alloted++;
                    break;
                }
            }
        }
        return n - alloted;
    }
};
