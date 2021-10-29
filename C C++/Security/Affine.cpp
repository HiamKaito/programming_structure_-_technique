#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int a, b;
int a1;

// euclid extend
int gcdExtended(int a, int b, int *x, int *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	
	int x1, y1;
	int gcd = gcdExtended(b%a, a, &x1, &y1);
	
	*x = y1 - (b/a) * x1;
	*y = x1;
	
	return gcd;
}

// find a^-1
int findA_inv() {
	int x, y;
	
	int res = gcdExtended(a, 26, &x, &y);
	
	for (int i = 26 / a ; i < 26 ; i++) {	
		x = 1, y = 1;
		res = gcdExtended(i, 26, &x, &y);
			
		if ( res == 1 ) {
			if (x > 0) {
				if ( x == a ) {
					return i;
				}
			}
			else {
				if ( (26 + x) == a ) {
					return i;
				}
			}
		}
	}
	
}

string enCrypt(char* p) {
	string res = "";
	
	for (int i = 0 ; i < strlen(p) ; i++) {
		// ek = a*x + b mod 26
		res += ( (a * (p[i] - 'a') + b)  % 26 ) + 'a' ; 
	}
	
	return res;
}

string deCrypt(char* p) {
	string res = "";
	
	for (int i = 0 ; i < strlen(p) ; i++) {
		// dk = a^-1 * (y - b) mod 26 
		int x = ( (a1 * ((p[i] - 'a') - b)) % 26 );
		if (x < 0) {
			// + 26: number alphabel
			x += '4' / 2;
		}
		x += 'a';
		//cout << p[i] <<" : "<< x << " " << endl;
		res += x;
	}
	
	return res;
}


int main() {
	
	a = 5; b = 6;
	char* p = "hentoithubay";
    
    // convert string to char*
    // en crypt
	char* cipher;
    cipher = &enCrypt(p)[0];
    cout << cipher << endl;
	
	// find a^-1
	a1 = findA_inv();
	//cout << a1 << endl;
	
	// de crypt
	cout << deCrypt(cipher) << endl;
	
	// end
	system("PAUSE");
	return 0;	
}