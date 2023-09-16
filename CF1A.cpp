

#include <iostream>

using namespace std;

int main(void)
{

	long long n, m, a;

	cin >> n >> m >> a;

	long long t_1 = (n + a - 1) / a;

	long long t_2 = (m + a - 1) / a;

	long long ans = t_1 * t_2;

	cout << ans << endl;


	return 0;

}





