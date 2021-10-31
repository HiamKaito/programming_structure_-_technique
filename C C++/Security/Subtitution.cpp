#include <iostream>
#include <string>

using namespace std;

char alpha[] = {
'a', 'b', 'c', 'd', 'e'
, 'f', 'g', 'h', 'i', 'j'
, 'k', 'l', 'm', 'n', 'o'
, 'p', 'q', 'r', 's', 't'
, 'u', 'v', 'w', 'x', 'y'
, 'z'
};
char keyAlpha[26];

void stringToChar(char c[], string s) {	
	for (int i = 0 ; i < s.size() ; i++) {
		c[i] = s[i];
	}
}

void toString(char c[]) {
	for (int i = 0 ; i < 26 ; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
}

void getKey(string keyWord) { 	
	toString(alpha);
	stringToChar(keyAlpha, keyWord);
	toString(keyAlpha);
}

void crypt(string plain, bool enFlag) {
	char charPlain[plain.size()];
	stringToChar(charPlain, plain);

	if (enFlag) {
		cout << "Encrypt: ";
	}
	else {
		cout << "Decrypt: ";
	}

	for (int i = 0 ; i < plain.size() ; i++) {
		for (int j = 0 ; j < 26 ; j++) {
			if (enFlag) {
				if (charPlain[i] == alpha[j]) {
					cout << keyAlpha[j];
				}
			}
			else {
				if (charPlain[i] == keyAlpha[j]) {
					cout << alpha[j];
				}
			}
		}
	}
	
	cout << endl;
}

int main() {
	cout << "Plaintext: ghenvoicovid" << endl;
        
	getKey("xnyahpogzqwbtsflrcvmuekjdi");
	crypt("ghenvoicovid", 1);
	crypt("oghsefzyfeza", 0);
		
	system("PAUSE");	
	return 0; 
}