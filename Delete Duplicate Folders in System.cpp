//Leetcode Link : https://leetcode.com/problems/delete-duplicate-folders-in-system/description/

/* Approach : 
* Step 1 Build a Tree (Trie) from the Folder Paths

Think of each folder path as a series of nested folders.
We build a tree where each folder is a node, and subfolders are children of that node.
For example
The path ["a", "b", "c"] would become a → b → c in the tree.
This gives us a full folder structure from all the input paths.

* Step 2 Serialize Each Subfolder Tree

We go to each folder node in the tree and serialize its structure.
Example
a folder with subfolders x and y would serialize like "x()y()"
This way, two different folders that look exactly the same will have the same serialized string.

* Step 3 Detect Duplicate Subtrees Using a Hash Map

For each serialization string from Step 2, we store the corresponding folder node in a HashMap.
If two or more folder nodes produce the same serialization string, we know these are duplicates.
We mark all these folder nodes as to be deleted.

* Step 4 Collect All Unique (Non-Duplicate) Paths

We now walk through the tree again from the root.
This time, we skip- any folders that were marked as duplicates.
As we walk through,
We collect the path from the root to each valid folder and add it to our result list.

* Step 5 Return the Final List of Paths

The result is of all folder paths that remain after removing duplicates.
Each path is a list of folder names, just like the input format.

*/
//T.C : O(N∗K)
//S.C : O(M)
class Solution 
{
public:
    struct Node 
    {
        unordered_map<string, Node*> children;
        bool del = false;
    };

    unordered_map<string, vector<Node*>> seen;

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) 
    {
        Node* root = new Node();

        // Step 1: Build Trie (folder tree)
        for (auto& path : paths) 
        {
            Node* cur = root;
            for (const string& dir : path) 
            {
                if (!cur->children.count(dir))
                {
                    cur->children[dir] = new Node();
                }

                cur = cur->children[dir];
            }
        }

        // Step 2: Serialize subtrees
        dfs(root);

        // Step 3: Mark duplicates
        for (auto& [key, nodes] : seen) 
        {
            if (nodes.size() > 1) 
            {
                for (auto* node : nodes)
                {
                    node->del = true;
                }
            }
        }

        // Step 4: Collect valid (non-deleted) paths
        vector<vector<string>> res;
        vector<string> path;
        collect(root, path, res);
        return res;
    }

    string dfs(Node* node) 
    {
        if (node->children.empty())
        {
            return "";
        } 

        vector<string> subs;
        for (auto& [name, child] : node->children) 
        {
            subs.push_back(name + "(" + dfs(child) + ")");
        }

        sort(subs.begin(), subs.end());
        string serial = accumulate(subs.begin(), subs.end(), string());
        seen[serial].push_back(node);
        return serial;
    }

    void collect(Node* node, vector<string>& path, vector<vector<string>>& res) 
    {
        for (auto& [name, child] : node->children) 
        {
            if (child->del)
            {
                continue;
            } 

            path.push_back(name);
            res.push_back(path);
            collect(child, path, res);
            path.pop_back();
        }
    }
};
