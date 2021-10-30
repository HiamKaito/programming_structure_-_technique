#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>

#define MAX 1000000001
using namespace std;

bool mark[MAX];

void mark_I(long x,long n);   
long Eratosthenes(long min);
long gcdExtended(long a, long b, long *x, long *y);
long findA_inv(long a, long n);
void prlongArray(long arr[], long size);
void createVectorKey(long aPrivate[], long N);
long sum(long array[], long N);
long getRandomPrime(long min);
void getRandomW_W(long &w,long &w1, long maxLength);
long enCrypt(long a[], long N, string p);
void deCrypt(long T, long w1, long m, long aPrivate[], long N);
string convertToString(char* a, long size);
char* convertIntegerToChar(long N);
string mult(long numb1, long numb2);
long mod(string num, long a);
long modulo(long a, long m);
long modulo(long a, long b, long m);

int main() {	
	string p = "0011001100110011001100110011001100110011";
	cout << "Plaintext: " << p << endl;
		
	long N;
	cout << "N(Max is 26): "; 
	cin >> N;
	
	// create array Private
	long aPrivate[N];
	createVectorKey(aPrivate,N);

	//prlong array	
	cout<< "Array private: " << endl;
	prlongArray(aPrivate, N);
	
	// get m: m > Sum array + m is Prime
	long m = getRandomPrime(sum(aPrivate, N));
	cout << "\nm: " <<  m << endl;

	// get w and w^-1
	long w, w1;
	getRandomW_W(w,w1,m);
	cout << "w: " << w << endl;
	cout << "w1: " << w1 << endl;			

	long aPublic[N];
	
	// find array a Public
	for (long i = 0 ; i < N ; i++) {
		aPublic[i] = modulo(w, aPrivate[i], m);
	}	
	
	// a'
	cout<< "Array public: " << endl;
	prlongArray(aPublic, N);
	
	// en crypt
	long T = enCrypt(aPublic, N, p);
	T = T % m;
	cout << "T: " << T << endl;

	// de crypt
	deCrypt(T, w1, m, aPrivate, N);

	return 0;
}

void mark_I(long x,long n) {
	long i = 2, num;
			
	// mark none prime number
	while ((num = i*x) <= n) {
		mark[num] = true;
		i++;
	}
}   
	
long Eratosthenes(long min) {
	srand(time(NULL)); 	
	long j = rand() % (5 + 1) + 1;
	long count = 0;
	
	for (long i = min ; i <= MAX ; i++) {
		// if is prime number
		// mark none prime number
		if (mark[i] == false) {
			mark_I(i,MAX);
			
			count ++;
			if (count == j)
				return i;
		}
	} 	
}

// euclid extend
long gcdExtended(long a, long b, long *x, long *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	
	long x1, y1;
	long gcd = gcdExtended(b%a, a, &x1, &y1);
	
	*x = y1 - (b/a) * x1;
	*y = x1;
	
	return gcd;
}

// find a^-1
long findA_inv(long a, long m) {
	long k = m;
        long xa = 1;
        long xm = 0;
        while (m != 0) {
            long q = a / m;
            long xr = xa - q * xm;
            xa = xm;
            xm = xr;
            long r = a % m;
            a = m;
            m = r;
        }
        long res = xa;
        if (res < 0) {
            return (k + res);
        } else {
            return res;
        }
}
void prlongArray(long arr[], long size) {
    for (long i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void createVectorKey(long aPrivate[], long N) {
	srand(time(NULL)); 	
	
	for (long i = 0 ; i < N ; i++) {
		long x = rand() % 2 + 1;
		
		// a[i] > sum a[(0 -> i)]
		aPrivate[i] = x + sum(aPrivate, i);
	}
}
long sum(long array[], long N) {
	long sum = 0;
	
	for (long i = 0 ; i < N ; i++) 
		sum += array[i];
	return sum;		
}
long getRandomPrime(long min) {	
	long primeNumb = Eratosthenes(min);
	return primeNumb;
} 
void getRandomW_W(long &w,long &w1, long maxLength) {
	srand(time(NULL)); 	
	long x,y;
	
	// avoid gcd != 1
	do {
		w = rand() % (maxLength + 1);
	} while (gcdExtended(w, maxLength, &x, &y) != 1 || w <= 1);
	//cout << "Gcd: " << gcdExtended(w, maxLength, &x, &y) << endl;
	
	// find w^-1
	do {
		w1 = findA_inv(w, maxLength);				
	} while(w1 == 1 || w1 == 0);
	
} 
long enCrypt(long a[], long N, string p) {
	long T = 0;

	for (long i = 0 ; i < N ; i++) {
 		// the plalongext (p) have mark
		if (p[i] == '1'){
			T += a[i]; 		
			//cout << a[i] << " ";
		}
	}
 	//cout << endl;
	return T; 	
}
void deCrypt(long T, long w1, long m, long aPrivate[], long N) {
	// update v3
	long T1 = modulo(T, w1, m);
	
	cout << "T1: " << T1 << endl;
	string res;
	
	// use look like algorithm KnapSack
	// run from N to 0
	for (long i = N - 1; i >= 0 ; i--) {
		// if the item can be place in
		// put it in and minus it
		if (aPrivate[i] <= T1) {
			T1 -= aPrivate[i];
			res += "1";
		//	cout << aPrivate[i] << " ";
		}
		else 
			res += "0";
			
	}	
	//cout << endl;
	
    reverse(res.begin(), res.end()); 
	cout << "DeCrypt : " << res << endl;
}
string convertToString(char* a, long size)
{
    long i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

char* convertIntegerToChar(long N) {
    long m = N;
    long digit = 0;
    while (m) {
        digit++;
        m /= 10;
    }
    char* arr;
    char arr1[digit];

    arr = (char*)malloc(digit);

    long index = 0;
    while (N) {
        arr1[++index] = N % 10 + '0';
        N /= 10;
    }
    long i;
    for (i = 0; i < index; i++) {
        arr[i] = arr1[index - i];
    }

    // Char array truncate by null
    arr[i] = '\0';

    // Return char array
    return (char*)arr;
}

string mult(long numb1, long numb2) {
	long a[100],b[100];
    long ans[200]={0};
    long i,j,tmp;
    
    char* s1 = convertIntegerToChar(numb1);
    char* s2 = convertIntegerToChar(numb2);
	
	long l1 = strlen(s1);
    long l2 = strlen(s2);
    
	for(i = l1-1,j=0;i>=0;i--,j++) {
        a[j] = s1[i]-'0';
    }
    
    for(i = l2-1,j=0;i>=0;i--,j++) {
        b[j] = s2[i]-'0';
    }
    
    for(i = 0;i < l2;i++) {
        for(j = 0;j < l1;j++) {
            ans[i+j] += b[i]*a[j];
        }
    }
    
    for(i = 0;i < l1+l2;i++) {
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0;i--) {
        if(ans[i] > 0)
            break;
    }
    
    //prlongf("Product : ");
    
	string res = "";
	
	for(;i >= 0;i--) {
    //   cout << ans[i];
	char c[10];
		itoa(ans[i], c, 10);
		res +=  c;
	}
	//cout << endl;
	
	//cout << "res: " << res<< endl;  
    return res;
}

long mod(string num, long a) {
    long res = 0;

    for (long i = 0; i < num.length(); i++)
		res = (res*10 + (long)num[i] - '0') %a;
    return res;
}
long modulo(long a, long m) {
	return (a%m + m) % m;	
}
long modulo(long a, long b, long m) {	
	return mod( mult(a, b), m);
}