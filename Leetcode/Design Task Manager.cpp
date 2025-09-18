//Leetcode Link : https://leetcode.com/problems/design-task-manager

//Approach (Using proper Data Structures)
// T.C. : add -> O(log n), edit -> O(log n), rmv -> O(1), execTop -> O(n log n) worst case
// S.C. : O(n)
class TaskManager {
    typedef pair<int, int> Task; // (priority, taskId)

    priority_queue<Task> maxHeap;                  // tasks sorted by priority, then taskId
    unordered_map<int, int> taskPriorityMap;       // taskId -> current priority
    unordered_map<int, int> taskOwnerMap;          // taskId -> userId

public:
    // Initialize with a list of [userId, taskId, priority]
    TaskManager(vector<vector<int>>& initialTasks) {
        for (const auto& task : initialTasks) {
            add(task[0], task[1], task[2]);
        }
    }

    // Add new task
    void add(int userId, int taskId, int priority) {
        maxHeap.push({priority, taskId});
        taskPriorityMap[taskId] = priority;
        taskOwnerMap[taskId] = userId;
    }

    // Edit existing task priority
    void edit(int taskId, int newPriority) {
        maxHeap.push({newPriority, taskId});
        taskPriorityMap[taskId] = newPriority;
    }

    // Remove a task from the system
    void rmv(int taskId) {
        taskPriorityMap[taskId] = -1; // mark as invalid
    }

    // Execute the top task and return its userId
    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, taskId] = maxHeap.top();
            maxHeap.pop();

            if (priority == taskPriorityMap[taskId]) {
                taskPriorityMap[taskId] = -1; // mark as executed
                return taskOwnerMap[taskId];
            }
        }
        return -1; // no tasks available
    }
};
