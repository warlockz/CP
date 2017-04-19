#include <iostream>
using namespace std;
// Enter your code for reversed_binary_value<bool...>()
//1st solution
static int count = 0;
template<bool... digits>
int reversed_binary_value()
{   
    int z = 0;
    bool valarr[] = {digits...};
    int size = sizeof...(digits);
    int temp = 1;
    cout<<"\n reversed_binary_value start : " << count++ <<"\n \n";
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
//1st solution
/*
//2nd solution
// Enter your code for reversed_binary_value<bool...>()
template<bool... digits>
struct BitSolver;

template<bool bit,bool... digits>
struct BitSolver<bit,digits...>
{
    static int reversed_bit_solver()
    {
        return (bit + 2*BitSolver<digits...>::reversed_bit_solver());

    }
};

template<>
struct BitSolver<>
{
    static int reversed_bit_solver()
    {
        return 0;
    }
};

template<bool... digits>
int reversed_binary_value()
{ 
    return (BitSolver<digits...>::reversed_bit_solver());
}


//2nd solution
*/

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
      cout<<"\n check n-1 start : " << count++ <<"\n \n";
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
      cout<<"\n check() start : " << count++ <<"\n \n";
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