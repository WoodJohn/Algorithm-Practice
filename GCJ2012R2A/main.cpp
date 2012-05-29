#include <iostream>
#include <fstream>
using namespace std;

int m[10001];
int d[10001];
int l[10001];
int n, t, total;

bool calculate()
{
	for(int i=1; i<=n; ++i)
		m[i]=-1;
	if(d[1]>l[1]) return false;
	m[1]=d[1];
	int j=2;
	for(int i=1; i<=n; ++i)
	{
		if(m[i]==-1) return false;
		int longest=d[i]+m[i];
		if(longest>=total) return true;
		for(; j<=n; ++j)
		{
			if(longest<d[j]) break;
			m[j]=d[j]-d[i];
			if(m[j]>l[j])
				m[j]=l[j];
		}
	}
	return false;
}

int main()
{
	cin>>t;
	ofstream fout;
	fout.open("out.out", ios::out);
	for(int i=1; i<=t; ++i)
	{
		cin>>n;
		for(int j=1; j<=n; ++j)
			cin>>d[j]>>l[j];
		cin>>total;
		fout<<"Case #"<<i<<": ";
		fout << (calculate() ? "YES" : "NO") << endl;
	}
	return 0;
}


