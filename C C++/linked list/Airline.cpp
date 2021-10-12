#include <iostream>
#include <cstdlib>
#include <time.h>

/*
							
			_______________________________________________
			
							 ___
							 \  \
							  \  \---->
				 |\____________\  \____________
			---->|	   \				       \
				 |      \						\
			     |      /						/
			---->| ____/_______    ____________/
				 |/			   /  /
							  /  /---->
							 /__/
			_______________      ___________________________
						  /    /
						 /    /

	may bay tu tren troi xuong truoc
	thong bao:
	may bay da xuong
	May bay duoi dat bay
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
void xuatloaimaybay(int i);
void chen(tramthuphi& A, nganxep* t, int i);
void dulieuvao(tramthuphi& A, tramthuphi& B, int n, int m);
void xuat(tramthuphi TTP, int n);
void sosanh(tramthuphi& A, tramthuphi& B, int n, int m);
void dulieura(tramthuphi TTP, int n, int k);
void chenvao_cuoi(int loaixe, int bienso, int k);
void nhuongduong(tramthuphi A, int n);

int main() {
	tramthuphi A, B;
	int n, m;
	nhap(n, m);
	dulieuvao(A, B, n, m);
	std::cout << "\n\n";
	sosanh(A, B, n, m);
	system("pause");
	return 0;
}

void nhap(int& n, int& m) {
	std::cout << "nhap vao so luong may bay tren troi: ";
	std::cin >> n;
	std::cout << "nhap vao so luong may bay duoi dat: ";
	std::cin >> m;
	std::cout << "\n\n";
}
nganxep* nutmoi() {
	nganxep* temp = new nganxep();
	temp->xe.bienso = rand() % 6969;
	temp->xe.loaixe = rand() % 4;
	temp->next = NULL;
	return temp;
}
void xuatloaimaybay(int i) {
	switch (i)
	{
	case 0:
		std::cout << "B52 ";
		break;
	case 1:
		std::cout << "VINA ";
		break;
	case 2:
		std::cout << "HONDA ";
		break;
	case 3:
		std::cout << "NGUYEN_VAN_BAY ";
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
		xuatloaimaybay(temp->xe.loaixe);
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
	std::cout << "MAY BAY TREN TROI GOM " << n << " CHIEC:\n";
	xuat(A, n);
	std::cout << "\n\n";
	for (int i = 1; i <= m; i++) {
		nganxep* t = new nganxep();
		t = nutmoi();
		chen(B, t, i);
	}
	std::cout << "MAY BAY DUOI DAT GOM " << m << " CHIEC:\n";
	xuat(B, m);
	std::cout << "\n\n";
}
void sosanh(tramthuphi& A, tramthuphi& B, int n, int m) {

	std::cout << "MAY BAY DUOI DAT NHUONG DUONG\n";
	nhuongduong(B, m);
	std::cout << "\n";
	std::cout << "MAY BAY TREN TROI DAP XUONG\n";
	dulieura(A, n, 1);
	std::cout << "\n";
	std::cout << "MAY BAY DUOI DAT CAT CANH\n";
	dulieura(B, n, 2);
	std::cout << "\n";
}
void nhuongduong(tramthuphi A, int n) {
	nganxep* temp = A.truoc;
	while (temp != NULL) {
		xuatloaimaybay(temp->xe.loaixe);
		std::cout << " DA VAO DUONG TRONG\n";
		temp = temp->next;
	}
}
void dulieura(tramthuphi TTP, int n, int k) {
	if (k == 1) {
		nganxep* temp = TTP.truoc;
		while (temp != NULL) {
			xuatloaimaybay(temp->xe.loaixe);
			std::cout << " DA CHAY VAO DUONG BANG VA HA CANH AN TOAN\n";
			temp = temp->next;
		}
	}
	else {
		int i = 1;
		nganxep* temp = TTP.truoc;
		while (temp != NULL) {
			chenvao_cuoi(temp->xe.loaixe, temp->xe.bienso, i);
			i++;
			temp = temp->next;
		}
		nganxep* t = C.truoc;
		while (t != NULL) {
			xuatloaimaybay(t->xe.loaixe);
			std::cout << " DA VAO DUONG BANG VA CAT CANH\n";
			t = t->next;
		}
	}
}