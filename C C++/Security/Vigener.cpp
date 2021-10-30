#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string enCrypt(char* p, char* key, int m) {
	string res = "";
	int count_m = 0;
	
	for (int i = 0 ; i < strlen(p) ; i++) {
		int x = p[i] + key[count_m] - 'A';
		if (x > 122) {
			x -=26;
		}
		if (x < 97) {
			x +=26;
		}
		res += (char) x;
		count_m++;
		if (count_m >= m) {
			count_m = 0;
		}	
	}
	
	return res;
}

void deCrypt(char* p, char* key, int m) {
	int count_m = 0;

	for (int i = 0 ; i < strlen(p) ; i++) {
		//cout << p[i];
		int x = p[i] - key[count_m] + 'A';
		
		if (x > 122) x -= 26;
		if (x < 97) x += 26;
		
		count_m++;
		
		if (count_m >= m) {
			count_m = 0;
		}
		
		cout << (char) x;	
	}
	
}

int main() {
	char* p = "thiscryptosystemisnotsecure";
	char* key = "CIPHER";
	int m = 6;
	cout << "PlainText: " << p << endl;
	cout << "key: " << key << endl;
	
	cout << "enCrypt: ";
	// encrypt
	char* cipher;
    cipher = &enCrypt(p, key, m)[0];
    cout << cipher << endl;
    
	cout << "deCrypt: ";
    //deCrypt
    deCrypt(cipher, key, m);
	cout << endl;
	system("PAUSE");		
	return 0;
}