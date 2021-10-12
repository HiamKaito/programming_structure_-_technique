#include <iostream>
#include <cstdlib>
#include <time.h>

/*
	1 chiec pha co gioi han khoi luong bang 1 xe contener
	1 xe contener = 2 xe tai
	1 xe tai	  = 2 xe khack
	1 xe khack	  = 2 xe con
	************************
	quy_uoc:
	1	xe con      = 150  kg
	2	xe khach    = 300  k
	3	xe tai      = 600  kg
	4	xe contener = 1200 kg
*/

class thongtin {
public:
	int bienso;
	int loaixe;
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

const int PHA = 1200;
tramthuphi TTP;
int sopha=0,s=0;//s dung de tinh tong khoi luong sau khi xe len
int mangpha[100];

int nhap() {
	int n;
	std::cout << "nhap vao so luong xe qua pha: ";
	std::cin >> n;
	mangpha[n]=1;
	return n;
}
nganxep* nutmoi() { 
	nganxep* temp = new nganxep();
	temp->xe.bienso = rand() % 6969;
	temp->xe.loaixe = rand() % 4;
	temp->next = NULL;
	return temp;
}
int gioihan(int k) {
	s += k;
	if (s == PHA)
		return 0;
	if (s < PHA)
		return 1;
	s -= k;
	return -1;
}
int quyuoc(int k) {
	//tuy theo quy uoc
	if (k == 0) return 150;
	if (k == 1) return 300;
	if (k == 2) return 600;
	if (k == 3) return 1200;
}
void chen(nganxep* t,int i) {
	if (i == 1) {
		TTP.sau = t;
		TTP.truoc = t;
	}
	else {
		TTP.sau->next = t;
		TTP.sau = t;
	}
}
void xuatloaixe(int i) {
	switch (i)
	{
	case 0:
		std::cout << "xe con";
		break;
	case 1:
		std::cout << "xe khach";
		break;
	case 2:
		std::cout << "xe tai";
		break;
	case 3:
		std::cout << "xe contener";
		break;
	}
}
void dulieuvao(int n) {
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		nganxep* t = new nganxep();
		t = nutmoi();
		int sum = gioihan(quyuoc(t->xe.loaixe));
		//neu nhu xe len nua thi pha se chim
		if (sum == -1) {
			std::cout << "xe qua nang,xe khong the len pha do khoi luong cua " ;
			xuatloaixe(t->xe.loaixe);
			mangpha[sopha] = s;
			sopha++;
			s = 0;
			std::cout << " nen pha di\n";
			sum = gioihan(quyuoc(t->xe.loaixe));
			std::cout << "1 xe len pha!: ";
			xuatloaixe(t->xe.loaixe);
			chen(t, i);
			std::cout << "\n";
		}
		//neu nhu pha da dat khoi luong toi da
		if (sum == 0) {
			chen(t, i);
			std::cout << "pha da du cho do ";
			xuatloaixe(t->xe.loaixe);
			mangpha[sopha] = s;
			sopha++;
			s = 0;
			std::cout << " nen pha di\n";
		}
		//neu nhu bt thi thoi
		if (sum == 1) {
			std::cout << "1 xe len pha!: ";
			xuatloaixe(t->xe.loaixe);
			//tranh truong hop xe cuoi cung len nhung pha khong di
			if (i==n){
				mangpha[sopha] = s;
				sopha++;
			}
			chen(t, i);
			std::cout << "\n";
		}
	}
}
void dulieura() {
	std::cout << "\n";	
	int a[] = { 0,0,0,0 };
	nganxep* temp = TTP.truoc;
	while (temp != NULL) {
		a[temp->xe.loaixe]++;
		temp = temp->next;
	}
	//xuat tong so xe tung loai
	for (int i = 0; i <= 3; i++) {
		std::cout << "xe loai:";
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
	//xuat ra so pha va so khoi luong tung pha
	std::cout << "tong so pha la :" << sopha << "\n";
	for (int i = 0; i <sopha; i++) {
		std::cout << "pha thu " << i << " co khoi luong la: " << mangpha[i] << "\n";
	}
}
int main() {
	dulieuvao(nhap());
	dulieura();
	system("pause");
	return 0;
}