#include<bits/stdc++.h>
#define max 100
using namespace std;
struct MonHoc {
    char maMH[10];
    char tenMH[25];
    int soTC;
};

struct List {
    int count;
    MonHoc e[max];
};

void create(List &L) {
    L.count = -1;
}

int empty(List L) {
    return L.count == -1;
}

int full(List L) {
    return L.count == max - 1;
}

int add(List &L, MonHoc X) {
    if (full(L))
        return 0;
    else {
        L.count++;
        L.e[L.count] = X;
        return 1;
    }
}
void fakeData(List &L) {
    L.count = 4;
    MonHoc a1=MonHoc{"RT1","C++",2};
    MonHoc a2=MonHoc{"RT2","C",2};
    MonHoc a3=MonHoc{"RT3","Python",3};
    MonHoc a4=MonHoc{"RT4","Java",3};
    MonHoc a5=MonHoc{"RT5","C#",3};
    L.e[0] = a1;
    L.e[1] = a2;
    L.e[2] = a3;
    L.e[3] = a4;
    L.e[4] = a5;
}
void hienThiDS(List L) {
    cout << setw(10) << "Ma mon hoc: ";
    cout << setw(20) << "Ten mon hoc: ";
    cout << setw(15) << "So tin chi: " << endl;
    for (int i = 0; i <= L.count; i++) {
        cout << setw(5) << L.e[i].maMH;
        cout << setw(20) << L.e[i].tenMH;
        cout << setw(15) << L.e[i].soTC << endl;
    }
}
void seach(List L, string ten) {
    int i=0;
    while(i<=L.count&&L.e[i].tenMH!=ten){
    	i++;
	}
	if(i<=L.count){
		cout << setw(10) << "Ma mon hoc: ";
    	cout << setw(20) << "Ten mon hoc: ";
    	cout << setw(15) << "So tin chi: " << endl;
    	cout << setw(5) << L.e[i].maMH;
        cout << setw(20) << L.e[i].tenMH;
        cout << setw(15) << L.e[i].soTC << endl;
	}
}
int xoa(List &L, string ten) {
    int i=0;
    while(i<=L.count&&L.e[i].tenMH!=ten){
    	i++;
	}
	if(i<=L.count){
		for(int j=i;j<=L.count;j++){
			L.e[j]=L.e[j+1];
		}
		L.count++;
		return 1;
	}
	else
		return 0;
}
void chen(List &L) {
	MonHoc a=MonHoc{"RT0","HDT",4};
	if(full(L)==0&&3<=L.count+1){
		cout<<"Chen mon hoc vao vi tri thu 3"<<endl;
		for(int i=L.count;i>=3;i--){
			L.e[i+1]=L.e[i];
		}
		L.count=L.count+1;
		L.e[3]=a;
	}
	hienThiDS(L);
}
int main() {
    List L;
    fakeData(L);
    cout<<"===============================================\n";
    hienThiDS(L);
    cout<<"===============================================\n";
    string ten;
    cout << "Nhap ten mon hoc can tim: ";
	getline(cin,ten);
    seach(L,ten);
    cout<<"===============================================\n";
    xoa(L,ten);
    hienThiDS(L);
    cout<<"===============================================\n";
    chen(L);
    return 0;
}
