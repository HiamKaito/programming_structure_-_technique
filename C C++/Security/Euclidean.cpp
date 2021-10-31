#include <iostream>
#include <string>
#include <fstream>

using namespace std;

long x1, y1;

long gcdExtended(long a, long b, long *x, long *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	
	long x1, y1;
	long gcd = gcdExtended(b%a, a, &x1, &y1);
	
	*x = y1 - (b/a) * x1;
	*y = x1;
	
	return gcd;
}
	
int main() {
	//khai bao bien
	long x, y, a, N;
	long count = 1;
			
	cout << "thuat toan tim nghich dao cua mot so A ";
	cout << "trong vanh ZN voi (A, N)" <<endl;
	
	cout << "Nhap A: ";
	cin >> a;
	cout << "Nhap N: ";
	cin >> N;
	
	long res = gcdExtended(a, N, &x, &y);
	
	if (res > 1) {
		cout << "khong co phan tu nghich dao";
	}
	else {
		cout << "";
		for (long i = N / a ; i < N ; i++) {	
			x = 1, y = 1;
			res = gcdExtended(i, N, &x, &y);
			
			if ( res == 1 ) {
				if (x > 0) {
					if ( x == a ) {
						cout << i << " ";
						break;
					}
				}
				else {
					if ( (N + x) == a ) {
						cout << i << " ";
						break;
					}
				}
			}
		}
	}
	
	cout<<endl;
	system("PAUSE");
	return 0;
}