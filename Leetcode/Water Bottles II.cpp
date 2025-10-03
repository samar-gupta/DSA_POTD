//Leetcode Link : https://leetcode.com/problems/water-bottles-ii/description/

//Approach-1 Simple Simulation
//T.C : O(root(numBottles))
//S.C : O(1)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;

        int drank = numBottles;

        while(empty >= numExchange) {
            empty -= numExchange;

            drank++;

            empty++;

            numExchange++;
        }

        return drank;
    }
};


//Approach-2 (Maths derivation - Using Sridharacharya formula)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return numBottles + ((-2*numExchange + 3 + sqrt(4*numExchange*numExchange+8*numBottles - 12 * numExchange + 1))/2);
    }
};



//Approach-1 :
/*
Intuition : 
   Unlike the standard problem where the exchange rate is fixed, here the exchange rate increases by 1 after each exchange.
   So, every time you manage to exchange, the next exchange becomes harder.
   We simulate the process step by step.

Approach :
   1. Start with numBottles bottles and drink them all.
   2. Keep a count emptyBottles for empty bottles.
   3. While you have enough empties for the current exchange rate:
         • Subtract numExchange empties.
         • Increment numExchange (next exchange harder).
         • Increment bottleDrunk (you got a new bottle to drink).
         • Add 1 empty bottle back.
   4. Stop when you cannot exchange anymore.
*/
//T.C : O(bottleDrunk) (each loop iteration drinks one more bottle).
//S.C : O(1) (only counters).
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottleDrunk = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            emptyBottles -= numExchange; // use empties for exchange
            numExchange++;               // cost of exchange increases
            bottleDrunk++;               // got one more bottle
            emptyBottles++;              // the new bottle becomes empty
        }
        return bottleDrunk;
    }
};
