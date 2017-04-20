
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
        LRUCache(int capacity)
        {
            cp = capacity;
            tail = NULL;
            head = NULL;
            //cout << "capacity = "<<cp<<"\n";
            mp.clear();
        }
        void set(int key,int val)
        {
            //cout << "set cp = "<<cp<<"map size =" <<mp.size()<< " \n";
            if(mp.size() < cp)
            {
               //cout << "set ss   \n";
                if(mp.size())
                {
                    //cout << "set 1\n";
                    if(mp.find(key) != mp.end())
                    {
                        //cout << "set 2\n";
                        Node* node = mp[key];
                        node->value = val;
                    }
                    else
                    {
                        //cout << "set 3\n";
                        Node* node = new Node(NULL,head,key,val);
                        head = node; 
                        mp.insert(std::make_pair(key,node));
                    }
                }
                else
                {
                    Node* node = new Node(key,val);
                    head = node;
                    tail = node;
                    mp.insert(std::make_pair(key,node));
                }
            }
            else
            {
               Node* temp = tail;
               Node* node = new Node(tail->prev,tail->next,key,val);
               tail = node;   
               mp.insert(std::make_pair(key,node));
               std::map<int,Node*>::iterator it = mp.find(temp->key);
               if(it != mp.end())
               {
                  mp.erase(it);
               }
               delete temp;
            }
        }

        int get(int key)
        {
            //cout << "get cp = "<<cp<<"map size =" <<mp.size()<< " \n";
            if(cp && mp.size())
            {
               if (mp.find(key) != mp.end())
               {
                  //cout << "get 111"<< " \n";
                  Node* node = mp[key];
                  //cout << "get 222"<< " \n";
                  if(mp.size() > 1 && node)
                  {

                     Node* prev = node->prev;
                     Node* next = node->next;
                     if(prev)
                     {
                        prev->next = next;   
                     } 
                     if(next)
                     {
                     
                        next->prev = prev;
                     }
                     //cout << "get 333"<< " \n";
                     node->prev = head->prev;
                     node->next = head->next;
                     head = node;
                  }
                  //cout << "get 4444"<< " \n";
                  return (node->value);           
               }   
               else
               {
                  return -1;
               }
            }
            else
            {
               return -1;
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
