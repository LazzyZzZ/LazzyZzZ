#include<bits\stdc++.h>
using namespace std;
struct MONHOC{
	char maMH[10];
	char tenMH[15];
	int soTC;
};
struct Node{
	MONHOC infor;
	Node *next;	
};
//Khoi tao danh sach rong
typedef Node *TRO;
void ktds(TRO &L){
	L=NULL;
}
//Ktra ds rong
int empty(TRO L){
	return L==NULL;
}
////Nhap thong tin
//void nhapMH(MONHOC &mh){
//	cout<<"\tNhap ma mon hoc: ";fflush(stdin);
//	gets(mh.maMH);
//	if(strcmp(mh.maMH,"stop")==0)
//		return;
//	cout<<"\tTen mon hoc: ";fflush(stdin);
//	gets(mh.tenMH);
//	cout<<"\tSo tin chi: ";
//	cin>>mh.soTC;
//}
//void nhapDS(TRO &L){
//	ktds(L);
//	MONHOC X;
//	TRO Q,P;
//	int i=1;
//	do{
//		cout<<"Nhap ten mon hoc thu "<<i<<endl;
//		nhapMH(X);
//		if(strcmp(X.maMH,"stop")==0)
//			return;
//		P=new(Node);
//		P->infor=X;
//		P->next=NULL;
//		if(L==NULL)
//			L=P;
//		else
//			Q->next=P;
//		Q=P;
//		i++;
//	}while(1);
//}
void fakeData(TRO &L){
	TRO MH1=new Node();
	TRO MH2=new Node();
	TRO MH3=new Node();
	TRO MH4=new Node();
	TRO MH5=new Node();
	
	strcpy(MH1->infor.maMH,"001");
	strcpy(MH1->infor.tenMH,"C++");
	MH1->infor.soTC=2;
	
	strcpy(MH2->infor.maMH,"002");
	strcpy(MH2->infor.tenMH,"Java");
	MH2->infor.soTC=3;
	
	strcpy(MH3->infor.maMH,"003");
	strcpy(MH3->infor.tenMH,"Python");
	MH3->infor.soTC=2;
	
	strcpy(MH4->infor.maMH,"004");
	strcpy(MH4->infor.tenMH,"C#");
	MH4->infor.soTC=2;
	
	strcpy(MH5->infor.maMH,"005");
	strcpy(MH5->infor.tenMH,"C");
	MH5->infor.soTC=1;
	
	L=MH1;
	MH1->next=MH2;
	MH2->next=MH3;
	MH3->next=MH4;
	MH4->next=MH5;
	MH5->next=NULL;
}
void htDS(TRO L){
	if(L==NULL){
		cout<<"Danh sach rong!"<<endl;
		return;
	}
	cout<<setw(10)<<"Ma mon hoc";
	cout<<setw(20)<<"Ten mon hoc";
	cout<<setw(15)<<"So tin chi"<<endl;
	TRO Q=L;
	while(Q!=NULL){
		MONHOC X=Q->infor;
		cout<<setw(5)<<X.maMH;
		cout<<setw(20)<<X.tenMH;
		cout<<setw(15)<<X.soTC<<endl;
		Q=Q->next;
	}
}
//Tim kiem va hien thi
void seach(TRO L, string ten){
	MONHOC X;
	TRO Q=L;
	while(Q!=NULL&&Q->infor.tenMH!=ten){
		Q=Q->next;
	}
	if(Q!=NULL){
		X=Q->infor;
		cout<<setw(10)<<"Ma mon hoc";
		cout<<setw(20)<<"Ten mon hoc";
		cout<<setw(15)<<"So tin chi"<<endl;
		cout<<setw(5)<<X.maMH;
		cout<<setw(20)<<X.tenMH;
		cout<<setw(15)<<X.soTC<<endl;
	}
}
//Xoa
void Remove(TRO &L, TRO T){
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
	if(Q==NULL){
		cout<<"Ko co MH trong danh sach!\n";
	}
	else{
		Remove(L,T);
		cout<<"Da xoa! Danh sach moi: \n";
		htDS(L);
	}
}
//Chen
void chen(TRO &L){
	int d=1;
	TRO M,Q=L;
	while(Q!=NULL&&d<4){
		M=Q;
		Q=Q->next;
		d++;
	}
	if(Q==NULL){
		cout<<"Vi tri ko thich hop";
		return;
	}
	TRO P=new Node;
	strcpy(P->infor.maMH,"000");
	strcpy(P->infor.tenMH,"JavaScript");
	P->infor.soTC=3;
	P->next=M->next;
	M->next=P;
}
int main(){
	TRO L;
//	nhapDS(L);
	cout<<"===============================================\n";
//	cout<<"Danh sach vua nhap\n";
	fakeData(L);
	htDS(L);
	cout<<"===============================================\n";
	string ten;
	cout<<"Nhap ten mon hoc can tim: ";
	getline(cin,ten);
	cout<<"Hien thi mon hoc do"<<endl;
	seach(L,ten);
	cout<<"===============================================\n";
	xoa(L,ten);
	cout<<"===============================================\n";
	chen(L);
	cout<<"Danh sach da chen"<<endl;
	htDS(L);
	cout<<"===============================================\n";
	return 0;
}