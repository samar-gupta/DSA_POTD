//Approach : (Using Trie)
#define ll long long int

class Node{
    
    Node* links[2];     
    ll count=0;
    public:
        bool containsKey(int bit)
        {
            return (links[bit]!=NULL);
        }
        Node* get(int num)
        {
            return links[num];
        }
        void put(int bit,Node* node)
        {
            links[bit]=node;
        }
        ll getCount()
        {
            return count;
        }
        void addCount()
        {
            count++;
        }
    
};

class Trie{
    
    private:
        Node* root;
    public:
        Trie()
        {
            root=new Node();
        }
        
        void insert(int num)
        {
            Node* node=root;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(!node->containsKey(bit))
                {
                    node->put(bit,new Node());
                }
                node=node->get(bit);
                node->addCount();
            }
        }
        int getPairs(int num,int k)
        {
            Node* node=root;
            int ans=0;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(((k>>i)&1))
                {
                    if(node->containsKey(bit))
                    {
                        ans+=node->get(bit)->getCount();
                    }
                    if(node->containsKey(1-bit))
                    {
                        node=node->get(1-bit);
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(node->containsKey(bit))
                    {
                        node=node->get(bit);
                    }
                    else{
                        break;
                    }
                }
                
            }
            return ans;
        }
    
};

class Solution {
  public:
    int cntPairs(vector<int>& arr, int k) {
        // code here
        Trie trie;
        int ans=0;
        
        for(auto it:arr)
        {
            ans+=trie.getPairs(it,k);
            trie.insert(it);
        }
        return ans;
    }
};
