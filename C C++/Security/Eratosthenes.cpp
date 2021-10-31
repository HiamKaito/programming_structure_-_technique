#include <iostream>
#include <string>
#include <fstream>

#define MAX 1000000001
using namespace std;

	bool mark[MAX];


	void mark_I(int x,int n) {
		int i = 2, num;
			
		while ((num = i*x) <= n) {
			mark[num] = true;
			i++;
		}
	}   
	
	void Era(int n) {
		for (int i = 2 ; i <= n ; i++) {
			if (mark[i] == false) {
				cout << i << " ";
				mark_I(i,n);
			}
		} 
	
	}  
	
	int main() {
		int n;
		cout << "Nhap vao so nguyen N:" ;
		cin >> n;
		Era(n);
		
		system("PAUSE");
		return 0;
	}  