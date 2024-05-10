#include<bits/stdc++.h>
using namespace std;
struct MonHoc{
  char maMH[10];
  char tenMH[20];
  int soTC;
};
struct Node{
  MonHoc infor;
  Node *next;
};
typedef Node *TRO;
void kTao(TRO &L){
    L=NULL;
}
int empty(TRO L){
    return L==NULL;
}
void fakeData(TRO &L){
    TRO A1=new Node();
    TRO A2=new Node();
    TRO A3=new Node();
    TRO A4=new Node();
    TRO A5=new Node();
    
    strcpy(A1->infor.maMH,"001");
    strcpy(A1->infor.tenMH,"C++");
    A1->infor.soTC=3;
    
    strcpy(A2->infor.maMH,"002");
    strcpy(A2->infor.tenMH,"C");
    A2->infor.soTC=2;
    
    strcpy(A3->infor.maMH,"003");
    strcpy(A3->infor.tenMH,"Python");
    A3->infor.soTC=3;
    
    strcpy(A4->infor.maMH,"004");
    strcpy(A4->infor.tenMH,"Java");
    A4->infor.soTC=4;
    
    strcpy(A5->infor.maMH,"005");
    strcpy(A5->infor.tenMH,"C#");
    A5->infor.soTC=3;
    
    L=A1;
    A1->next=A2;
    A2->next=A3;
    A3->next=A4;
    A4->next=A5;
    A5->next=NULL;
}
void hienThiDS(TRO L){
    if(L==NULL){
        cout<<"Danh sach rong!"<<endl;
        return;
    }
    cout<<setw(10)<<"Ma mon hoc: ";
    cout<<setw(20)<<"Ten mon hoc: ";
    cout<<setw(15)<<"So tin chi: "<<endl;
    TRO Q=L;
    while(Q!=NULL){
        MonHoc X=Q->infor;
        cout<<setw(5)<<X.maMH;
        cout<<setw(20)<<X.tenMH;
        cout<<setw(15)<<X.soTC<<endl;
        Q=Q->next;
    }
}
void seach(TRO L, string ten){
	MonHoc X;
	TRO Q=L;
	while(Q!=NULL&&Q->infor.tenMH!=ten){
		Q=Q->next;
	}
	if(Q!=NULL){
		X=Q->infor;
		cout<<setw(10)<<"Ma mon hoc: ";
    	cout<<setw(20)<<"Ten mon hoc: ";
    	cout<<setw(15)<<"So tin chi: "<<endl;
    	cout<<setw(5)<<X.maMH;
        cout<<setw(20)<<X.tenMH;
        cout<<setw(15)<<X.soTC<<endl;
	}
}
void remove(TRO &L, TRO T){
	TRO Q;
	if(T==L)
		L=T->next;
	else{
		Q=L;
		while(Q->next!=T)
			Q=Q->next;
		Q->next=T->next;
	}
	delete T;
}
void xoa(TRO &L, string ten){
	TRO Q=L;
	while(Q!=NULL&&Q->infor.tenMH!=ten){
		Q=Q->next;
	}
	TRO T=Q;
	if(Q==NULL)
		cout<<"Khong co mon hoc trong danh sach!\n";
	else{
		remove(L,T);
		cout<<"Da xoa mon hoc! Danh sach mon hoc moi: \n";
		hienThiDS(L);
	}
}
void chen(TRO &L){
	int d=1;
	TRO M,Q=L;
	while(Q!=NULL&&d<4){
		M=Q;
		Q=Q->next;
		d++;
	}
	if(Q==NULL){
		cout<<"Vi tri chen khong thich hop!";
		return;
	}
	TRO P=new Node;
	strcpy(P->infor.maMH,"000");
	strcpy(P->infor.tenMH,"HDT");
	P->infor.soTC=3;
	P->next=M->next;
	M->next=P;
}
int main() {
    TRO L;
    fakeData(L);
    cout<<"===============================================\n";
    hienThiDS(L);
    cout<<"===============================================\n";
    string ten;
    cout<<"Nhap ten mon hoc muon tim: ";
    getline(cin,ten);
    cout<<"Mon hoc do la: "<<endl;
    seach(L,ten);
    cout<<"===============================================\n";
    xoa(L,ten);
    cout<<"===============================================\n";
    chen(L);
    hienThiDS(L);
    return 0;
}
