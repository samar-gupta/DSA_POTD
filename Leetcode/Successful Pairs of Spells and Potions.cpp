//Company Tags  : MICROSOFT
//Leetcode Link : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

//Approach-1 : Using lower_bound STL
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        
        int n = potions.size();
        
        sort(begin(potions), end(potions));
        
        int maxPotion = potions[n-1];
        
        vector<int> answer;
        
        
        for(int i = 0; i<m; i++) {
            
            int spell = spells[i];
            
            long long minPotion = ceil((1.0*success)/spell);
            
            if(minPotion > maxPotion) {
                answer.push_back(0);
                continue;
            }
            
            int index = lower_bound(begin(potions), end(potions), minPotion) - begin(potions);
            
            answer.push_back(n-index);
            
        }
        
        return answer;
    }
};


//Approach-2 : Using self written Binary Search for lower bound
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    
    int BinarySearch(int l, int r, vector<int>& potions, int target) {
        
        //we have to find the index of first element greater than or equal to target (minPotion)
        
        int index = -1;
        int mid = 0;
        
        while(l <= r) {
            
            mid = l + (r-l)/2;
            
            if(potions[mid] >= target) {
                index = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
            
        }
        
        return index;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        
        int n = potions.size();
        
        sort(begin(potions), end(potions));
        
        int maxPotion = potions[n-1];
        
        vector<int> answer;
        
        
        for(int i = 0; i<m; i++) {
            
            int spell = spells[i];
            
            long long minPotion = ceil((1.0*success)/spell);
            
            if(minPotion > maxPotion) {
                answer.push_back(0);
                continue;
            }
            
            int index = BinarySearch(0, n-1, potions, minPotion);//lower_bound(begin(potions), end(potions), minPotion) - begin(potions);
            
            answer.push_back(n-index);
            
        }
        
        return answer;
    }
};


//Approach-3 (Using 2 pointers)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int,int>> sortedSpells;
        for (int i = 0; i< spells.size(); ++i) {
            sortedSpells.push_back({ spells[i], i });
        }

        // Sort the 'spells with index' and 'potions' array in increasing order.
        sort(sortedSpells.begin(), sortedSpells.end());
        sort(potions.begin(), potions.end());

        vector<int> answer(spells.size());
        int m = potions.size();
        int potionIndex = m - 1;
        
        // For each 'spell' find the respective 'minPotion' index.
        for (const auto& [spell, index] : sortedSpells) {
          
            while (potionIndex >= 0 && (long long) spell * potions[potionIndex] >= success) {
                potionIndex -= 1;
            }
            answer[index] = m - (potionIndex + 1);
          
        }
        
        return answer;
    }
};
