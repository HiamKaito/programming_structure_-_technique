#include <iostream>
#include <string>
#include <fstream>

using namespace std;

long modexp(long a, long x, long n) {
	long r=1;
	while (x>0){
		if (x%2==1)
			r=(r*a)%n;
		a=(a*a)%n;
		x/=2;
	}
	return r;
}  
	
int main() {
	long a, x, n;
	cout << "Thuat toan a^x mod n" << endl;
	cout << "Nhap a:";
	cin >> a;
	cout << "Nhap x";
	cin >> x;
	cout << "Nhap n:";
	cin >> n;
	long res = modexp(a,x,n);
	cout << "Ket qua: " <<res << endl;
	system("PAUSE");
	return 0;
}