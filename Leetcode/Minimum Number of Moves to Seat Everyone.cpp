//Leetcode Link : https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

//Approach-1: (Sorting both arrays)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        
        int moves = 0;
        
        int n = seats.size();
        for(int i = 0; i < n; i++){
            moves += abs(seats[i] - students[i]);
        }
        
        return moves;
    }
};

//Approach-2: Counting Sort (constraints only 100)
//T.C : O(n+n+n) ~ O(n)
//S.C : O(101 + 101) 
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = students.size();
        vector<int> position_seat(101, 0);
        vector<int> position_stud(101, 0);

        for(int &x : seats) {
            position_seat[x]++;
        }
        for(int &x : students) {
            position_stud[x]++;
        }

        int i = 0;
        int j = 0;
        int result = 0;

        while(i <= 100 && j <= 100) {
            if(position_seat[i] == 0) i++;
            if(position_stud[j] == 0) j++;
            
            if(i <= 100 && j <= 100 && position_seat[i] != 0 && position_stud[j] != 0) {
                result += abs(i-j);
                position_seat[i]--;
                position_stud[j]--;
                n--;
            }
        }

        return result;
    }
};
