#include <iostream>

using namespace std;

void zoomout(int no)
{
	switch(no)
	{

		case 0 :

			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					if((i > 0) && (i < 4))
					{
						if((j > 0) && (j < 4))
						{
							cout << " ";
							continue;
						}
					}
					cout << "*";
				}
				cout << "\n";
			}

		break;

		case 1:

		break;

		default:

		break;

	};

}

int main(int argc, char const *argv[])
{
	cout << "Please enter no ?";
	int x;
	cin >> x;
	zoomout(x);
	return 0;
}
