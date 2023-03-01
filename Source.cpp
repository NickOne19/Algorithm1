#include <iostream>
using namespace std;
bool NextSet(int* a, int n, int m)
{
	if (a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[0] + a[2] == a[1] * 1000 + a[4] * 100 + a[5] * 10 + a[6])
		// Ï - 0. Ð - 1. Î - 2. Ð - 3 . Ö - 4. È - 5. ß - 6
	{
		cout << a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[0] << " : " << a[2] << " = " << a[1] * 1000 + a[4] * 100 + a[5] * 10 + a[6];
		return false;
	}
	int j = m - 1;
	while (j >= 0 && a[j] == n) j--;
	if (j < 0) return false;
	if (a[j] >= n)
		j--;
	a[j]++;
	if (j == m - 1) return true;
	for (int k = j + 1; k < m; k++)
		a[k] = 1;
	return true;
}
void Print(int* a, int n)
{
	static int num = 1;
	cout.width(3);
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int n, m, * a;
	cout << "N = ";
	cin >> n;
	cout << "M = ";
	cin >> m;
	a = new int[m];
	for (int i = 0; i < m; i++)
		a[i] = 1;
	Print(a, m);
	while (NextSet(a, n, m))
		Print(a, m);
	cin.get();
	return 0;
}