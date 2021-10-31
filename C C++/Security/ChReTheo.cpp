#include <iostream.h>

/**
Cai dat giai thuat phan du Trung Hoa de t�m nghiem x
bat ki cua he phuong tr�nh dong du sau:
x = a1 (mod m1)
x = a2 (mod m2)
x = a3 (mod m3)
Goi y: +Input: a1, a2, a3, m1, m2, m3

+Output: x
**/	
int main() {
	//khai bao bien
	int  m1, m2, m3;
	int a[3], m[3];
	int x, M, M1, M2, M3, y1, y2, y3;
	
	for (int i = 0 ; i < 3 ; i++) {
		cout << "Nhap a" << i << " :";
		cin >> a[i];
	}
	
	for (int i = 0 ; i < 3 ; i++) {
		cout << "Nhap m" << i << " :";
		cin >> m[i];
	}

	M = m[0] * m[1] * m[2];
	M1 = M / m[0];
	M2 = M / m[1];
	M3 = M / m[2]; 
	y1 = M1 % m[0];
	y2 = M2 % m[1];
	y3 = M3 % m[2];
	
	x = a[0]*M1*y1 + a[1]*M2*y2 + a[2]*M3*y3;
	x = x % M;
	cout << x;
	
	cout << endl;
	system("PAUSE");
	return 0;
}