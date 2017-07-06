#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
// Define specializations for the Traits class template here.

template <typename T>
struct Traits
{
    static string name(int n)
    {
        return "unknown";
    }
};

template<>
struct Traits<Fruit>
{
    static string name(int n)
    {  
        string name;
        switch(n)
        {
            case 0 :
                name = "apple";
            break;
            case 1 :
                name = "orange";
            break;
            case 2 :
                name = "pear";
            break;
            default :
                name = "unknown";
            break;
        }
        return name;
    }
};

template<>
struct Traits<Color>
{
    static string name(int n)
    {
        string name;
        switch(n)
        {
            case 0 :
                name = "red";
            break;
            case 1 :
                name = "green";
            break;
            case 2 :
                name = "orange";
            break;
            default :
                name = "unknown";
            break;
            
        }
        return name;
    }
};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}