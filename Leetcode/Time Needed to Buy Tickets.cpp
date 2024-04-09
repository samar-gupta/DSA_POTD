//Approach-1 (Brute Force)
//Time Complexity = O(n*tickets[k])        , n->size of the given array
//Space Complexity = O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int time = 0;
        int index = 0;
        
        while(index < tickets.size())
        {
            if(tickets[index] != 0)
            {
                time++;
                tickets[index]--;
            }
            
            if(tickets[k] == 0)
                return time;
            
            index++;
            if(index == tickets.size())
                index = 0;
        }
        return time;
    }
};



//Approach-2 
//Time Complexity = O(n)
//Space Complexity = O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int time = 0;
        
        // O(n)
        for(int index = 0; index < tickets.size(); index++)
        {
            if(index <= k)
                time += min(tickets[index],tickets[k]);
            else
                time += min(tickets[index],tickets[k]-1);
        }
        return time;
    }
};
