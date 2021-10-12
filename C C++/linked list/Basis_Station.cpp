#include <iostream>
#include <cstdlib>
#include <time.h>

class thongtin {
public: 
	int bienso;
	int loaixe;//xe tai,xe con,xe khack,xe con-te-ner
};
class nganxep {
public:
	thongtin xe;
	nganxep* next;
};
class tramthuphi {
public:
	nganxep* truoc, * sau;
};
tramthuphi TTP;

int nhap() {
	int n;
	std::cout << "nhap vao so luong xe: ";
	std::cin >> n;
	return n;
}
nganxep* nutmoi() {
	nganxep* temp = new nganxep();
	temp->xe.bienso = rand() % 6969;
	temp->xe.loaixe = rand() % 4;
	temp->next = NULL;
	return temp;
}
void dulieuvao(int n) {
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		nganxep* t = new nganxep();
		t = nutmoi();
		if (i == 1) {
			TTP.sau = t;
			TTP.truoc = t;
		}
		else {
			TTP.sau->next = t;
			TTP.sau = t;
		}
		std::cout << "xe da qua tram!\n";
	}
}
void dulieura() {
	int a[] = { 0,0,0,0 };
	nganxep* temp = TTP.truoc;
	while (temp != NULL) {
		a[temp->xe.loaixe]++;
		temp = temp->next;
	}
	for (int i = 0; i <= 3; i++) {
		std::cout << "xe loai: ";
		switch (i) {
		case 0:
			std::cout << "xe tai co tong cong: " << a[i] << " chiec\n";
			break;
		case 1:
			std::cout << "xe con co tong cong: " << a[i] << " chiec\n";
			break;
		case 2:
			std::cout << "xe khack co tong cong: " << a[i] << " chiec\n";
			break;
		case 3:
			std::cout << "xe con-te-ner co tong cong: " << a[i] << " chiec\n";
			break;
		}
	}
}
int main() {
	dulieuvao(nhap());
	dulieura();
	system("pause");
	return 0;
}