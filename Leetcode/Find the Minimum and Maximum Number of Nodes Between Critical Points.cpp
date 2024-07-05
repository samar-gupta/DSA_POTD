//Company Tags  : META
//Leetcode Link : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description

//Approach-1 (Using Simple looping)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int currPosition = 1;
        int previousCriticalIndex = 0;
        int firstCriticalIndex = 0;

        while (curr->next != NULL) {
            
            // When we see a critical point
            if ((curr->val < prev->val &&
                 curr->val < curr->next->val) ||
                (curr->val > prev->val &&
                 curr->val > curr->next->val)) {

                    if (previousCriticalIndex == 0) {
                        previousCriticalIndex = currPosition;
                        firstCriticalIndex = currPosition;
                    } else {
                        minDistance =
                            min(minDistance, currPosition - previousCriticalIndex);
                        previousCriticalIndex = currPosition;
                    }
            }

            currPosition++;
            prev = curr;
            curr = curr->next;
        }

        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = previousCriticalIndex - firstCriticalIndex;
        return {minDistance, maxDistance};
    }
};



//Approach-2 (similar code but simple)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCriticalIndex    = 0;
        int previousCriticalIndex = 0;

        int prevValue = 0;
        int currValue = 0;
        int nextValue = 0;

        int minDistance = INT_MAX;
        int index = 0;
        vector<int> result = {-1, -1};

        while (head != NULL) {
            prevValue = currValue;
            currValue = nextValue;
            nextValue = head->val;

            if (prevValue != 0 && currValue != 0 && nextValue != 0 && 
                (prevValue > currValue && currValue < nextValue ||
                prevValue < currValue && currValue > nextValue)) {
                
                if (firstCriticalIndex == 0) {
                    firstCriticalIndex = index;
                } else {
                    minDistance = min(minDistance, index - previousCriticalIndex);
                    result = {minDistance, index - firstCriticalIndex};
                }
                previousCriticalIndex = index;
            }

            index++;
            head = head->next;
        }

        return result;
    }
};
