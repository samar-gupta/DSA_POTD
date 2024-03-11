//Company Tags   : Facebook, Amazon
//Leetcode Link  : https://leetcode.com/problems/custom-sort-string/

//Approach-1 (Just making use of frequency of each char) : 
//T.C : O(str.length())
//S.C : O(26) ~ O(1)
class Solution {
public:
    string customSortString(string order, string str) {
        int count[26] = {0};
        
        for(char &x : str)
            count[x-'a']++;
        
        string result = "";
        for(char &ch : order) {
            while(count[ch-'a']--) {
                result.push_back(ch);
            }
        }
        
        //Add the characters which are not present in 'order'
        for(char &ch : str) {
            if(count[ch-'a'] > 0) {
                result.push_back(ch);
            }
        }
        
        return result;
    }
};

//Approach-2 (Using comparator)
//T.C : O(nlogn)
//S.C : O(26) ~ O(1)
class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> index(26, -1);
        
        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;
        
        
        auto lambda = [&index](char &ch1, char &ch2) {
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(begin(str), end(str), lambda);
        return str;
        
    }
};

/*What was actually asked in Facebook :
FOLLOW UP NOTE : The original questions that was asked by Facebook was similar to
this but there was one small variation that "The characters which don't
occur in "str" must be sorted as per English Alphabet order".  In that case
one slight change will do the job in comparator function below :
*/
class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> index(26, INT_MAX);
        
        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;
        
        
        auto lambda = [&](char &ch1, char &ch2) {
            if(index[ch1-'a'] == index[ch2-'a'])
                return ch1 < ch2;
            
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(begin(str), end(str), lambda);
        return str;
        
    }
};
