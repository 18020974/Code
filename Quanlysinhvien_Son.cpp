#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct sinhVien
{
	string name;
	string id;
	string home;
	float mark;
};
struct node
{
	sinhVien data;
	node *pNext;
};
struct linkedList
{
	node *pHead;
	node *pTail;
	int size;
	linkedList() {
		pHead=NULL;
		pTail=NULL;
		size=0;
	}
};
node *newnode(sinhVien sv)
{
	node* p = new node;
	p->data=sv;
	p->pNext=NULL;
}
bool trungLapMSSV(linkedList &l, string id)
{
	for(node *i=l.pHead; i!=NULL; i=i->pNext) {
		if(id==i->data.id)
			return true;
	}
	return false;
}
bool dieuKienDiem(float mark)
{
	if(mark<0 or mark>10)
		return false;
	return true;
}
sinhVien inPut(sinhVien &sv)
{
		cout <<"Ten: ";
	fflush(stdin);
	getline(cin, sv.name);
		cout <<"Ma SV: ";
	fflush(stdin);
	getline(cin, sv.id);
		cout <<"Que quan: ";
	fflush(stdin);
	getline(cin, sv.home);
	do {
		cout <<"Diem: ";
		cin >>sv.mark;
		if(dieuKienDiem(sv.mark)==false)
			cout <<"Diem khong hop le!" <<endl;
	} while(dieuKienDiem(sv.mark)==false);
	return sv;
}

void addHead(linkedList &l, sinhVien data)
{
	node *p=newnode(data);
	if(l.pHead==NULL)
		l.pHead=l.pTail=p;
	else {
		p->pNext=l.pHead;
		l.pHead=p;
	}
	l.size++;
}
void addTail(linkedList &l, sinhVien data)
{
	node *p=newnode(data);
	if(l.pHead==NULL)
		l.pHead=l.pTail=p;
	else{
		l.pTail->pNext=p;
		l.pTail=p;
	}
	l.size++;
}
void addBefore(linkedList &l, sinhVien data, node *point) 
{
	node *p=newnode(data);
	for(node *i=l.pHead; i!=NULL; i=i->pNext) {
		if(i->pNext==point){
			p->pNext=point;
			i->pNext=p;
			l.size++;
			break;
		}
	}
}
void outPut(linkedList l)
{
	int count=0;
	if(l.size==0) {
		cout <<"Danh sach trong";
		exit(0);
	}
	cout <<"DANH SACH SINH VIEN:" <<endl;
	cout <<setfill('-');
	cout <<setw(88) <<"-" <<endl;
	cout <<setfill(' ');
	cout <<left <<setw(11) <<"|STT" <<left <<setw(31) <<"|Ho va ten" <<left <<setw(13) <<"|MSSV" <<left <<setw(21) <<"|Que quan" <<left <<setw(11) <<"|Diem" <<"|" <<endl;
	for(node *i=l.pHead; i!=NULL; i=i->pNext) {
		count++;
		cout <<setfill('-');
		cout <<setw(88)<<"-" <<endl;
		cout <<setfill(' ');
		cout <<"|"<<left<<setw(10) <<count;
		cout <<"|"<<left<<setw(30) <<i->data.name;
		cout <<"|"<<left<<setw(12) <<i->data.id;
		cout <<"|"<<left<<setw(20) <<i->data.home;
		cout <<"|"<<left<<setw(10) <<i->data.mark <<"|" <<endl;
	}
	cout <<setfill('-');
	cout <<setw(88) <<"-"<<endl;
	cout <<setfill(' ');
}
void softByMark(linkedList &l)
{
	for(node *i=l.pHead; i!=NULL; i=i->pNext)
		for(node *j=i->pNext; j!=NULL; j=j->pNext){
			if(j->data.mark < i->data.mark)
				swap(i->data,j->data);
		}
}
void remove(linkedList &l)
{
	string id_key;
	cout <<"Nhap MSSV can xoa: ";
	fflush(stdin);
	getline(cin,id_key);
	int size=l.size;
	for(node *i=l.pHead; i!=NULL; i=i->pNext) {
		if(i==l.pHead and i->data.id==id_key) {
		l.pHead=l.pHead->pNext;
		l.size--;
		break;
		}
		else if(i->pNext->data.id==id_key and i->pNext==l.pTail) {
				l.pTail=i;
				i->pNext=NULL;
				l.size--;
				break;
			}
		else if(i->pNext->data.id==id_key) {
			node *p=i->pNext;
			i->pNext=p->pNext;
			delete p;
			l.size--;
			break;
		}
	}
	if(l.size==size-1) {
		system("cls");
		cout <<"Xoa thanh cong!" <<endl;
	}
}
void add(linkedList &list)
{
	int loc;
	do {
		cout <<"Nhap vi tri can them: ";
		cin >>loc;
		if(loc<1 or loc>list.size+1) {
			cout <<"Vi tri khong hop le!" <<endl;
		}
	} while(loc<1 or loc>list.size+1);
	sinhVien data;
	inPut(data);
	int size=list.size;
	if(loc==1)
		addHead(list, data);
	else if(loc==list.size+1)
		addTail(list, data);
	else {
		int temp_count=0;
		for(node *i=list.pHead; i!=NULL; i=i->pNext){
			temp_count++;
			if(temp_count==loc) {
				addBefore(list, data, i);
				break;
			}
		}
	}
	if(list.size==size+1) {
		system("cls");
		cout <<"Them thanh cong!" <<endl;
	}
	else{
		cout <<"Them khong thanh cong!" <<endl;
	}
}
inputList(linkedList &list)
{
	sinhVien sv;
	int count=0;
	while(1) {
		count++;
		cout <<"Sinh vien " <<count <<endl;
		cout <<"Ten: ";
		fflush(stdin);
		getline(cin, sv.name);
		if(sv.name=="")  //neu bo trong o ten thi dung thao tac nhap;
			break;
		do {
			cout<<"Ma SV: ";
			fflush(stdin);
			getline(cin, sv.id);
			if(trungLapMSSV(list, sv.id)==true)
				cout<<"MSSV bi trung!"<<endl;
		} while(trungLapMSSV(list, sv.id)==true);
		cout<<"Que quan: ";
		fflush(stdin);
		getline(cin, sv.home);
		do {
			cout <<"Diem: ";
			cin >>sv.mark;
			if(dieuKienDiem(sv.mark)==false)
				cout <<"Diem khong hop le!" <<endl;
		} while(dieuKienDiem(sv.mark)==false);
		addTail(list, sv);
		system("cls");
	}
}
int main()
{
	linkedList list;
	sinhVien sv;
	inputList(list);
	system("cls");
	softByMark(list);
	outPut(list);
	while(1) {
		int choice;
		cout <<"1.Xoa" <<endl <<"2.Them" <<endl <<"Bam phim khac de ket thuc!" <<endl;
		cout <<"Nhap lua chon: ";
		cin >>choice;
		switch(choice) {
			case 1: remove(list); break;
			case 2: add(list); break;
			default: {
				cout<<"Chuong trinh ket thuc!";
				exit(0);
			} 
		}
	outPut(list);
	}
}
