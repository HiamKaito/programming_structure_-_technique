#include <iostream>
#include <cstdlib>
#include <time.h>

/*
									|\
									| \
									|  \
									|  /	 
									| /
						 ______	____|/_______1__2__3__4_____N___ 
						/      |-|
				  _____/	   |-|
				 /			   |-|
				/			   |-|
			   /			   |-|
	   _______/				   |-|
				

		Tro choi du cau tut
		Nguoi thu 1tut xuong sau do vong ra sau nguoi thu N
		Lam nhu vay den so lan nhat dinh
		Moi lan lam la xuat ra thong bao
*/
class thongtin {
public:
	int gioitinh;
	int sothutu;//xe tai,xe con,xe khack,xe con-te-ner
};
class nganxep {
public:
	thongtin nguoi;
	nganxep* next;
};
class tramthuphi {
public:
	nganxep* truoc, * sau;
};

void nhap(int& n, int& m);
nganxep* nutmoi(tramthuphi& A, int i);
void chen(tramthuphi& A, nganxep* t, int i);
void dulieuvao(tramthuphi& A, int n);
void xuatgioitinh(int k);
void chay(tramthuphi& A, int m);

int main() {
	tramthuphi A;
	int n,m;
	nhap(n,m);
	dulieuvao(A, n);
	chay(A, m);
	system("pause");
	return 0;
}

void nhap(int& n,int& m) {
	std::cout << "nhap vao so luong nguoi: ";
	std::cin >> n;
	std::cout << "nhap vao so lan toi da nguoi choi: ";
	std::cin >> m;
}
nganxep* nutmoi(tramthuphi& A, int i) {
	nganxep* temp = new nganxep();
	temp->nguoi.gioitinh = rand() % 2;
	temp->nguoi.sothutu = i;
	temp->next = A.truoc;
	return temp;
}
void chen(tramthuphi& A, nganxep* t, int i) {
	if (i == 1) {
		A.sau = t;
		A.truoc = t;
	}
	else {
		A.sau->next = t;
		A.sau = t;
	}
}
void dulieuvao(tramthuphi& A, int n) {
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		nganxep* t = new nganxep();
		t = nutmoi(A,i);
		chen(A, t, i);
	}
}
void xuatgioitinh(int k) {
	if (k == 1) {
		std::cout << "nam";
	}
	else {
		std::cout << "nu";
	}
}
void chay(tramthuphi& A, int m) {
	nganxep* temp = A.truoc;
	for (int k = 1; k <=m ; k++) {
		std::cout << "Lan " << k << " ban ";
		xuatgioitinh(temp->nguoi.gioitinh);
		std::cout<<" voi stt la " << temp->nguoi.sothutu << " nhay!\n";
		temp = temp->next;
	}
}
