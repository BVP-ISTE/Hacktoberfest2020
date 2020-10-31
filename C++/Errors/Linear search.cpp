// Program of Linear Search of an element


#include <bits/stdc++.h>
using namespace std;


int linearSearch(int *arr, int n, int x)
{

        for(int k=0;k<n;k++){
            if(arr[k]==x){

                return 1;
            }

        }
        return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		int val;
		cin >> val;
		cout << linearSearch(arr, n, val) << endl;
	}
	return 0;
}


