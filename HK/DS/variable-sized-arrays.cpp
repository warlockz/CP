#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from 
    STDIN. Print output to STDOUT */   
    
    int n,q;

    cin >> n >> q;

    int ** arr = new int*[n];

    int rows  = n;
    int count = 0;
    int queries = q;
    
    for (int i = 0; i < rows; ++i)
    {
    	int k;
    	cin >> k;
    	arr[i] = new int[k];
    	for (int j = 0; j < k; ++j)
    	{
    		cin >> arr[i][j];
    	}
    }

    for (int i = 0; i < queries; ++i)
    {
    	int l,m;
    	cin >> l >> m;
    	cout << arr[l][m] << "\n";
    }

    return 0;
}

/*
	Solution : Using vector :-

int main() {
    
    int n,q;
    cin >> n >> q;
    
    //int **arr = new int *(n);
    
    //vector< std::vector<int> > v(n, std::vector<int> ());
    vector< std::vector<int> > v;
    int k;
    int rows  = n;
    int queries = q;
    while(queries--)
    {
    	cin >> k;

    	if(rows--)
    	{
    		std::vector<int> col(k);
			for (int j = 0; j < k; ++j)
			{
				cin >> col[j];
			}
			v.push_back(col);
		}
    };

    queries = q;
	while(queries--)
    {
    	int l,m;
    	cin >> l >> m;
    	/*std::vector<int> temp = v[1];
    	cout << temp[0] << " ";
    	cout << "\n";*/
    /*	cout << v[l][m];

    };

    return 0;
}*/