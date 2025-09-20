//Leetcode Link : https://leetcode.com/problems/implement-router

//Approach (Queue for FIFO, Map for quick retrieval and sorted vector for binary search)
// T.C. : 
// addPacket()       -> O(k) worst-case (due to forwardPacket() + vector erase at front)
// forwardPacket()   -> O(k) worst-case (erase from vector front for destination timestamps)
// getCount()        -> O(log k) per query (binary search in vector)
// k = number of packets for a particular destination

// S.C. : 
// O(MAX_SIZE) total
// packetStore     -> O(MAX_SIZE)
// que             -> O(MAX_SIZE * key length)
// destTimestamps  -> O(MAX_SIZE)
class Router {
private:
    int MAX_SIZE;  // memory limit
    unordered_map<string, vector<int>> packetStore;  // key -> packet [source, dest, timestamp]
    unordered_map<int, vector<int>> destTimestamps;  // destination -> sorted timestamps
    queue<string> que;  // FIFO order

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (packetStore.find(key) != packetStore.end()) {
            return false;  // duplicate
        }

        if ((int)packetStore.size() >= MAX_SIZE) { //remove the oldest packet
            forwardPacket();
        }

        packetStore[key] = {source, destination, timestamp};
        que.push(key);
        destTimestamps[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty())
            return {}; //If there are no packets to forward, return an empty array.

        string key = que.front(); 
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        destTimestamps[dest].erase(destTimestamps[dest].begin()); // remove earliest timestamp

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end() || it->second.empty())
            return 0;

        int i = lower_bound(begin(it->second), end(it->second), startTime) - begin(it->second);//log(size of vec)
        int j = upper_bound(begin(it->second), end(it->second), endTime) - begin(it->second); //log(size of vec)

        return j - i;   // rightIdx - leftIdx
    }
};
