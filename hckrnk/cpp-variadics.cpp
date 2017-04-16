#include <iostream>
using namespace std;
// Enter your code for reversed_binary_value<bool...>()
static int count = 0;
template<bool... digits>
int reversed_binary_value()
{   
    int z = 0;
    bool valarr[] = {digits...};
    int size = sizeof...(digits);
    int temp = 1;
    cout<<"\n start : " << count++ <<"\n \n";
    for(int i = 0; i < size; ++i)
    {
        cout<<valarr[i]<<" ";
        if(valarr[i])
        z += temp;
        temp = temp * 2;
    }
    
    /*
    int z = 0; int mul = 1;
    for(bool val : valarr){
        if(val)
            z |= mul;
        mul <<= 1;
    }
    */
    cout << "\n  \n";
    return z;
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}