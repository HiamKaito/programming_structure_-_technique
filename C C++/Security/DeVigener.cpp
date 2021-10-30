#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;
string p;
string c;
string key;
int m;

string crypt() {
	string res = "";
	int count = 0;
	
	for (int i = 0 ; i < p.length() ; i++) {
		int x = c[i] - p[i] + 'A' +26;
		
		if (x > 'Z') x -=26;
		if (x < 'A') x +=26;
				
		res += (char) x;
		count++;
		
		if (count == m) 
			break;
	}	
	
	return res;
}
void readFile(char* filename) {
	fstream f;
	f.open(filename, ios::in);
	
	getline(f, p); 
	getline(f, c);
	
	string data;
	getline(f, data);
    stringstream geek(data);
    geek >> m;
    
	f.close();	
}

int main() {	
	readFile("input.txt");
	key = crypt();
	return 0;
}