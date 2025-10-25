//Leetcode Link : https://leetcode.com/problems/calculate-money-in-leetcode-bank

//Approach-1 (Simple simulation)
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int result = 0;

        int monday_money = 1; //1dollar

        while(n > 0) {

            int money = monday_money; //1
            for(int day = 1; day <= min(n, 7); day++) {
                result += money;
                money++;
            }

            n -= 7;
            monday_money++;
        }

        return result;
    }
};



//Approach-2 (Using AP and a for loop)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7; //Weeks

        int first = 28;
        int last  = 28 + (terms - 1) * 7; //AP formula for n-th term

        int result = terms * (first + last) / 2; //Sum of nth terms in an AP


        //Final week remaining days = n%7
        int start_money = 1 + terms;

        for(int day = 1; day <= (n%7); day++) {
            result += start_money;
            start_money++;
        }

        return result;
    }
};


//Approach-3 (Using AP completely)
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7; //Weeks

        int first = 28;
        int last  = 28 + (terms - 1) * 7; //AP formula for n-th term

        int result = terms * (first + last) / 2; //Sum of nth terms in an AP


        //remaining days
        int remain = n%7;
        int first_term = (1 + terms);
        int last_term  = first_term + remain - 1;
        result += remain * (first_term + last_term) / 2;

        return result;
    }
};
