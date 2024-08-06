//Leetcode Link : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

//Approach-1 (Using Map and doing as asked in Problem)
//T.C : O(n) + O(26log26) (for sorting)
//S.C : O(n)
class Solution {
public:
    //I am sorting to give priority to the char which has highest frequency
    //Because I would want it to come first in any button(key)
    void sortFunc(string &word) {
        unordered_map<char, int> mp;
        
        for(const char &ch : word) {
            mp[ch]++;
        }
        
        auto lambda=[&](const char &ch1, const char &ch2){
            return mp[ch1] > mp[ch2];
        };
        
        sort(begin(word), end(word), lambda);
    }
    
    int minimumPushes(string word) {
        if(word.length() <= 8) {
            return word.length();
        }
        sortFunc(word);
        unordered_map<int, unordered_set<char>> myMap;
        unordered_map<char, pair<int, int>> mp; //char is stored in which key in myMap and at what position it came
        
        int result = 0 ;
        int assign = 2;
        
        for(char &ch : word) {
            if(assign > 9) {
                assign = 2;
            }
            
            
            if(mp.find(ch) == mp.end()) {
                myMap[assign].insert(ch);
                mp[ch]            = {assign, (int)myMap[assign].size()};
                
                result += mp[ch].second;
                assign++;
            } else {
                result += mp[ch].second;
            }
        }
        
        return result;
        
    }
};


//Approach-2 (Simplifying and using same generic code as Part-1 of this problem)
//T.C : O(n) + O(26log26)
//S.C : O(1)
class Solution {
public:
    int minimumPushes(string word) {
        
        //Generic solution
        vector<int> mp(26, 0);
        for(char &ch: word)
            mp[ch - 'a']++; //Mentioned in qn, all letters will be distinct
    
        sort(begin(mp), end(mp), greater<int>()); //descending order of frequency
        
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += mp[i]*((i/8) + 1);
        }
        return ans;
    }
};
