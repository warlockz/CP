//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
// The class should have the following functions : 
// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);
// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box
//Overload operator < as specified
//bool operator<(Box& b)
//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

#include <iostream>

using namespace std;

class Box
{
	public :
		Box():l(0),b(0),h(0)
		{}
        // Used explicit keyword to avoid direct conversion operator calling Ex : if(Box b == 1)
        // atleast one arg should not to be default since then Box B will directly call param constructor
        // not the default constructor
		explicit Box(int x,int y = 0,int z = 0):l(x),b(y),h(z)
		{}
		Box(const Box& box)
		{
			l = box.l;
			b = box.b;
			h = box.h;
		}

	public :
		int getLength(); // Return box's length
		int getBreadth (); // Return box's breadth
		int getHeight ();  //Return box's height
		long long CalculateVolume(); // Return the volume of the box
		//Overload operator < as specified
		//bool operator<(const Box& b);
		//Overload operator << as specified
		//ostream& operator<<(ostream& out,const Box& B);
        //fun1 
        bool operator < ( Box& b) 
        {
            bool result = false;    
            if(this->l < b.l)
            {
                result = true; 
            }
            else if((this->b < b.b) && (this->l == b.l))
            {
                result = true;                 
            }
            else if((this->h < b.h) && (this->b == b.b) && (this->l == b.l))
            {
                 result = true;                
            }
        //return ((this->CalculateVolume()) < (b.CalculateVolume())); //const obj(b) cannot call non const functions.
            
            return result;
        }
        // Similar candidate non member function but we have declare data members then as public or use getters 
        // see fun2
        friend ostream& operator<<(ostream& out,const Box& B)
        {
            out<<B.l<<" "<<B.b<<" "<<B.h;
            return out;
        }

        void input(istream& in) const
        {
        	in>>B.l>>B.b>>B.h;
        }

	public :
		long l,b,h;

};

int Box::getLength(){ return l;}
int Box::getBreadth (){ return b;}
int Box::getHeight (){ return h;}
long long Box::CalculateVolume(){ return (l*b*h);}
//fun2
//non member function binary operator implementation fun2
//bool operator < (const Box& b,const Box& c) { return(((b.l < c.l) || (b.b < c.b) || (b.h < c.h))); }
//bool operator > (const Box& b,const Box& c) { return((operator < (b,c))); }

istream& operator>>(istream& in,const Box& B)
{
    B.input(in);
    return in;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
