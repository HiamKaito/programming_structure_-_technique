#include <iostream>
#include <cstdlib>
#include <time.h>

/*
							 \    \
							  \    \____________________
			___________________\					<----
			---->			     ___________________________	
			_______________     /
						  /    /
						 /    /
	
	xe ben nao it hon thi nhuong duong cho xe ben kia
	thong bao:
	xe ben nao nhuong duong, xe nao di vao hang doi.
	xe luu thong.
	xe lui.
	xe di chuyen.
*/
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

tramthuphi C;

void nhap(int& n, int& m);
nganxep* nutmoi();
void xuatloaixe(int i);
void chen(tramthuphi& A, nganxep* t, int i);
void dulieuvao(tramthuphi& A, tramthuphi& B, int n, int m);
void xuat(tramthuphi TTP, int n);
void sosanh(tramthuphi& A, tramthuphi& B, int n, int m);
void dulieura(tramthuphi TTP, int n,int k);
void chenvao_cuoi(int loaixe, int bienso, int k);
void nhuongduong(tramthuphi A, int n);

int main() {
	tramthuphi A, B;
	int n,m;
	nhap(n,m);
	dulieuvao(A,B,n,m);
	std::cout << "\n\n";
	sosanh(A, B, n, m);
	system("pause");
	return 0;
}

void nhap(int& n, int& m) {
	std::cout << "nhap vao so luong xe ben trai: ";
	std::cin >> n;
	std::cout << "nhap vao so luong xe ben phai: ";
	std::cin >> m;
}
nganxep* nutmoi() {
	nganxep* temp = new nganxep();
	temp->xe.bienso = rand() % 6969;
	temp->xe.loaixe = rand() % 4;
	temp->next = NULL;
	return temp;
}
void xuatloaixe(int i) {
	switch (i)
	{
	case 0:
		std::cout << "xe con ";
		break;
	case 1:
		std::cout << "xe khach ";
		break;
	case 2:
		std::cout << "xe tai ";
		break;
	case 3:
		std::cout << "xe contener ";
		break;
	}
}
void chenvao_cuoi(int loaixe, int bienso, int k)
{
	nganxep* p = new nganxep();
	p->xe.loaixe = loaixe;
	p->xe.bienso = bienso;
	p->next = NULL;
	if (k == 1)
		C.truoc = C.sau = p;
	else
	{
		p->next = C.truoc;
		C.truoc = p;
	}
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
void xuat(tramthuphi TTP, int n) {
	nganxep* temp = TTP.truoc;
	while (temp != NULL) {
		xuatloaixe(temp->xe.loaixe);
		temp = temp->next;
	}
}
void dulieuvao(tramthuphi& A, tramthuphi& B, int n, int m) {
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		nganxep* t = new nganxep();
		t = nutmoi();
		chen(A, t, i);
	}
	std::cout << "XE BEN TRAI GOM " << n << " CHIEC:\n";
	xuat(A, n);
	std::cout << "\n\n";
	for (int i = 1; i <= m; i++) {
		nganxep* t = new nganxep();
		t = nutmoi();
		chen(B, t, i);
	}
	std::cout << "XE BEN PHAI GOM " << m << " CHIEC:\n";
	xuat(B, m);
	std::cout << "\n\n";
}
void sosanh(tramthuphi& A, tramthuphi& B, int n, int m) {
	if (n > m) {
		std::cout << "XE BEN PHAI NHUONG DUONG\n\n";
		nhuongduong(B, m);
		std::cout << "\n";
		std::cout << "XE BEN TRAI DI\n\n";
		dulieura(A, n, 1);
		std::cout << "\n";
		std::cout << "XE BEN PHAI DI\n\n";
		dulieura(B, n, 2);
		std::cout << "\n";
	}
	else {
		std::cout << "XE BEN TRAI NHUONG DUONG\n\n";
		nhuongduong(A, n);
		std::cout << "\n";
		std::cout << "XE BEN PHAI DI\n\n";
		dulieura(B, m, 1);
		std::cout << "\n";
		std::cout << "XE BEN TRAI DI\n\n";
		dulieura(A, n, 2);
		std::cout << "\n";
	}
}
void nhuongduong(tramthuphi A, int n) {
	nganxep* temp = A.truoc;
	while (temp != NULL) {
		xuatloaixe(temp->xe.loaixe);
		std::cout << " da chay vao noi de nhuong duong\n";
		temp = temp->next;
	}
}
void dulieura(tramthuphi TTP, int n,int k) {
	if ( k==1 ) {
		nganxep* temp = TTP.truoc;
		while (temp != NULL) {
			xuatloaixe(temp->xe.loaixe);
			std::cout << " da chay vao ngo hep\n";
			temp = temp->next;
		}
	}
	else {
		int i=1;
		nganxep* temp = TTP.truoc;
		while (temp != NULL) {
			chenvao_cuoi(temp->xe.loaixe, temp->xe.bienso, i);
			i++;
			temp = temp->next;
		}
		nganxep* t = C.truoc;
		while (t != NULL) {
			xuatloaixe(t->xe.loaixe);
			std::cout << " da lui ra ngoai va chay qua ngo hep\n";
			t = t->next;
		}
	}
}
