#include<bits/stdc++.h>

using namespace std;

struct Workshop
{
    Workshop(){}
	Workshop(int x,int y,int z = 0):st(x),d(y),et(z){}
	void set(int x,int y,int z = 0)
	{
		st = x;
		d = y;
		et = z;
	}
	// using sort
    bool operator<(const Workshop& w) const
    {
    	return (et < w.et);
    }

	int st,d,et;
};

struct Available_Workshops
{
    Available_Workshops(){}
	Available_Workshops(int s):n(s)
	//,ws(NULL)
	{}
	int n;
	// Workshop* ws; changing vector since timeoutd
	//below vector<Workshop> can be used and as an easy way to do
	std::vector<Workshop> v;
};

void sortWorkshop(int n,Workshop* ws)
{  
	Workshop temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < (n - 1); ++j)
		{
			if (ws[j+1].et < ws[i].et)
			{
				temp = ws[i];
				ws[i] = ws[j+1];
				ws[j+1] = temp;
			}
		}
	}

}

Available_Workshops* initialize (int start_time[], int duration[], int n) 
{

	Available_Workshops* AW = new Available_Workshops(n);
	
	for (int i = 0; i < n; ++i)
	{
		//	AW->ws[i].set(start_time[i],duration[i],(start_time[i]+duration[i]));
		Workshop temp;
		temp.set(start_time[i],duration[i],(start_time[i]+duration[i]));
		AW->v.push_back(temp);
	}
	return AW;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int no = 0,et = -1;
	//if vector use sort() which will diectly invoke operator <
	int size = (ptr->n);
	// 	sortWorkshop(size,ptr->ws);
	// changed to stl sort due to timeout
	sort(ptr->v.begin(),ptr->v.end());
	/*
	for (int i = 0,n = 0; i < size; ++i)
	{
        if(ptr->ws[i].st >= et)
        {
            et = ptr->ws[i].et;
            no++;
        }
	}
	*/
	for (int i = 0,n = 0; i < size; ++i)
	{
        if(ptr->v[i].st >= et )
        {
            et = ptr->v[i].et;
            no++;
        }
	}

	return no;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}