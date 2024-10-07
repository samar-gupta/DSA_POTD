// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data)
{
    Node *newHead = new Node(data);
    newHead->npx = head;
    return newHead;
}

vector<int> getList(struct Node *head)
{
    vector<int> ans;
    Node *curr = head;
    while (curr)
    {
        ans.push_back(curr->data);
        curr = curr->npx;
    }
    return ans;
}
