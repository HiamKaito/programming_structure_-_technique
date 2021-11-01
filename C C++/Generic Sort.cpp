#include <iostream>
using namespace std;

// need for generic
template <class T>
void sortArray(T a[], int n)
{ 
    T temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
           if(a[j]>a[j+1])
           {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
        }
    }
}

// need for generic
template <class T>
void printArray(T a[], int n)
{
    sortArray(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int n[11] = {
		3, 5, 6, 8, 9, 0 , 1, 33 ,4 , 12 , 21
	};
	sortArray(n, 11);
	printArray(n, 11);
	
	string s[4] = {
		"Hello", "my name", "is", "Null"
	};
	sortArray(s, 4);
	printArray(s, 4);
	
	return 0;
}