#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int> s;
    int n;
    cin>>n;
    
    while(n--)
    {
        int ch,no;
        cin>>ch>>no;
        if(ch == 1)
        {
            s.insert(no);
        }
        else if(ch == 2)
        {
            s.erase(no);
        }
        else if(ch == 3)
        {
            if(s.find(no) != s.end())
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
                
        }
    }
    
    return 0;
}