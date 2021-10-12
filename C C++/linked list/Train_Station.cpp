#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

/*
quanly khuvuc
							 _______________________		  _______________________
					tail <- |_next_|_thongtin_|__B__| <----- |_next_|_thongtin_|__A__| <- head
										|								  |
									 ___|______						   ___|______
 cac toa:  	tail <-	|_next_|_2_| <- |_next_|_1_| <- head		tail<-|_next_|_1_| <- head			ngan xep




	---->
		____________.___________________.____________________.____________________________._______________
	Tram	        A			        B                    C                            D

		1 danh sach lien ket kiem soat:
		- cac loai toa: A(loai toa giuong nam) va B(loai toa ngoi)
		- so luong toa: head->dau->next->tail
		In ra thong bao moi lan qua tram: 
		- them toa
		- bot  toa

*/

class khuvuc {
public:
	khuvuc* next;
};
class node {
public:
	int id;
	node* next;
};
class tram {
public:
	khuvuc* head_kv, * tail_kv;
	node* head, * tail;
};

//xe_buyt la so luong nguoi mac dinh tren xe
//sum_lenxuong la so luong toi da nguoi len xuong
//max_ppl la so luong toi da ma xe buyt co the tro
int xe_buyt = 3, sum_lenxuong = 10;
const int max_ppl = 5;
tram A, B, C, D, E;

void khoitao() {
	khuvuc* a = new khuvuc;
	A.head_kv = a;
	a->next = B.head_kv;

	khuvuc* b = new khuvuc;
	B.head_kv = b;
	b->next = C.head_kv;

	khuvuc* c = new khuvuc;
	C.head_kv = c;
	c->next = D.head_kv;

	khuvuc* d = new khuvuc;
	D.head_kv = d;
	d->next = E.head_kv;

	khuvuc* e = new khuvuc;
	e->next = NULL;
	E.head_kv = e;
	E.tail_kv = NULL;
}

// create randome 
node* taonut() {
	node* temp = new node();
	temp->id = rand() % 90 + 1;
	temp->next = NULL;
	return temp;
}
// add node
int themtoa(tram& A) {
	node* t = new node();
	t = taonut();
	if (A.head == NULL) {
		A.tail = t;
		A.head = t;
	}
	else {
		A.tail->next = t;
		A.tail = t;
	}
	return 1;
}
// rand how many ppl go in, out
void dulieuvao(tram& A) {
	int n = rand() % sum_lenxuong + 1;
	for (int i = 1; i <= n; i++) {
		themtoa(A);
	}
}
// delete node
int xoatoa(tram& A) {
	node* temp = A.head;
	if (A.head == NULL) return -1;
	A.head = temp->next;
	if (!A.head)
		A.tail = NULL;
	temp->next = NULL;
	delete temp;
	return 1;
}

void dulieura(tram A) {
	node* temp = A.head;
	int i = 1;
	while (temp != NULL) {
		std::cout << "nguoi " << i << " co id " << temp->id << "\n";
		temp = temp->next;
		i++;
	}
	std::cout << "\n";
}
int count_queu(tram A) {
	node* temp = A.head;
	int i = 0;
	while (temp != NULL) {
		temp = temp->next;
		i++;
	}
	return i;
}
void themhoacbot(tram& A,int i) {
	switch (i){
		case 0:
			if (xe_buyt == 0) {
				break;
			}
			xe_buyt--;
			std::cout << "1 nguoi xuong, xe buyt co " << xe_buyt << " khach va co " << max_ppl - xe_buyt << " cho trong";
			std::cout << "\n";
			themtoa(A);
			break;
		case 1:
			if (xe_buyt >= max_ppl) {
				std::cout << "Xe buyt da het cho\n";
				break;
			}
			xe_buyt++;
			std::cout << "1 nguoi len  , xe buyt co " << xe_buyt << " khach va co " << max_ppl - xe_buyt << " cho trong";
			std::cout << "\n";
			xoatoa(A);
	}
}
void xuly(tram& A,char s) {

	std::cout << "Xe buyt chay toi tram " << s << " , trong xe buyt co " << xe_buyt << " nguoi\n";
	int m,n;
	m = count_queu(A);
	n = rand() % 10 + 1;
	for (int i = 1; i <= n; i++) {
		themhoacbot(A,0);
	}
	n = rand() % 10 + 1;
	if (n > m) {
		n = m;
	}
	for (int i = 1; i <= n; i++) {
		themhoacbot(A,1);
	}
	std::cout << "\nTram xe buyt co:\n";
	dulieura(A);
	std::cout << "\n\n";

}
int main() {
	srand(time(NULL));
	khoitao();
	dulieuvao(A);
	dulieuvao(B);
	dulieuvao(C);
	dulieuvao(D);
	dulieuvao(E);
	
	std::cout << "Tram A:\n";
	dulieura(A);
	std::cout << "Tram B\n";
	dulieura(B);
	std::cout << "Tram C\n";
	dulieura(C);
	std::cout << "Tram D\n";
	dulieura(D);
	std::cout << "Tram E\n";
	dulieura(E);

	std::cout << "\n";
	char s;
	s = 'A';
	xuly(A,s);
	s = 'B';
	xuly(B,s);
	s = 'C';
	xuly(C,s);
	s = 'D';
	xuly(D,s);
	s = 'E';
	xuly(E,s);

	system("pause");
	return 0;
}