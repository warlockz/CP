#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
    public:
        LRUCache(int capacity):cp(capacity),tail(NULL),head(NULL)
        {
            mp.clear();
        }
        void set(int key,int val)
        {
            if(cp)
            {
                if(mp.size())
                {
                    if(mp.find(key) != mp.end())
                    {
                        
                    }
                    else if(mp.size() < cp)
                    {
                    
                    }
                    else
                    {
                        Node* node = new Node(tail->prev,tail->next,key,val);
                        tail = node;
                    }
                }
                else
                {
                    Node* node = new Node(key,val);
                    head = node;
                    tail = node;
                }
            }
        }

        int get(int key)
        {
            if((cp) && (mp.size() < cp))
            {
                
            }
        }
    
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}