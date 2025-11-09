//Leetcode Link : https://leetcode.com/problems/count-operations-to-obtain-zero

//Approach-1 (Using Maths similar to Euclidean Algorithm - Iterative)
//T.C : O(log(min(a, b)))
//S.C : O(1)
class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;

        while(num1 > 0 && num2 > 0) {
            count += num1/num2;

            num1 %= num2;

            swap(num1, num2);
        }

        return count;
    }
};


//Approach-2 (Using Maths similar to Euclidean Algorithm - Recursion)
//T.C : O(log(min(a, b)))
//S.C : O(1)
class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0)
            return 0;

        if(num1 < num2)
            swap(num1, num2);

        
        return num1/num2 + countOperations(num1%num2, num2);
    }
};
