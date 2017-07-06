#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::vector<int> v;
    int n,x;
    cin>>n;
    while(n--)
    {
    	cin>>x;
    	v.push_back(x);
    }
    sort(v.begin(),v.end());

    for (std::vector<int>::iterator it = v.begin(); it != v.end() ; ++it)
    {
    	cout<<*it<<' ';
    }


    cin>>x;
    v.erase(v.begin()+(x-1)); 
    cin>>x>>n;
    v.erase(v.begin()+(x-1),v.begin()+(n-1));
    
    for (std::vector<int>::iterator it = v.begin(); it != v.end() ; ++it)
    {
    	cout<<*it<<' ';
    }

    cin>>n;
    while(n--)
    {
        cin>>x;
        std::vector<int>::iterator it,low;
        /*
        it = find(v.begin(),v.end(),x);
        if(it != v.end())
        {
            cout<<"Yes "<<((it - v.begin())+1)<<endl;
            //cout<<"Yes "<<std::distance(vec.begin(), it);
        }
        else
        {
    	   low = lower_bound(v.begin(),v.end(),x);
           cout<<"No "<<((low - v.begin())+1)<<endl;
        }
        */
        //since above approach time complexity is less.
        low = lower_bound(v.begin(),v.end(),x);
        if((low != v.end()) && (*low == x))
        {
            cout<<"Yes "<<((low - v.begin())+1)<<endl;
            //cout<<"Yes "<<std::distance(vec.begin(), it);
        }
        else
        {
           cout<<"No "<<((low - v.begin())+1)<<endl;
        }
  
    } 

	return 0;
}