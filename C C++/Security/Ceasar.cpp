#include <iostream>
#include <string>
#include <fstream>  

using namespace std;

string encrypt(string text, int s) { 
	string result = ""; 

	for (int i = 0; i < text.length() ; i++) { 
		if (text[i] == 32) 
			result += " ";
		else
			if (isupper(text[i])) 
				result += char(int(text[i]+s-65)%26 +65); 
			else
				result += char(int(text[i]+s-97)%26 +97); 
	} 
	return result; 
} 

int main() {
	string text="hen toi thu bay  hentoithubay"; 
	int key = 9; 
	cout << "Text : " << text; 
	cout << "\nShift: " << key; 
	text = encrypt(text, key);
	cout << "\nCipher: " << text; 
	
	cout<< endl;
	text = encrypt(text, 26 - key); 
	cout << "DeCrypt:" << text << endl;
		
	return 0; 
	
}