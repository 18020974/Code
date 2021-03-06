#include <iostream>
#include <math.h>
using namespace std;

int i, j, n; //khai bao bien toan cuc
struct sinhVien
{
	float toan;
	float ly;
	float anh;
	float dtb;
	float stt;
};
typedef struct sinhVien sv; //thay the 'struct sinhVien' thanh 'sv'

bool dieuKienDiem(float mark) //ham kiem tra dieu kien diem thuoc [0, 10]
{
	if(mark<0 || mark>10) {
		cout <<"\nDiem khong hop le! Xin vui long nhap lai!";
		return false;
	}
	return true;
}
void nhap(sinhVien sv[], int n)
{
	int i;
		cout <<"\n\t\t=====NHAP THONG TIN SINH VIEN=====";
	for(i=0; i<n; i++) {
		fflush(stdin); //xoa bo nho dem moi khi nhap, tranh luu du lieu cu
		sv[i].stt=i+1;
		do {
		cout <<"\nSinh vien " <<i+1 <<": ";
			cout <<"\n- Diem Toan: ";
			cin >>sv[i].toan;
		}
		while(dieuKienDiem(sv[i].toan)==false); //dieu kien diem sai thi lap lai buoc nhap
		fflush(stdin);
		do {
			cout <<"\n- Diem Ly: ";
			cin >>sv[i].ly;
		} while(dieuKienDiem(sv[i].ly)==false);
		fflush(stdin);
		do {
			cout <<"\n- Diem Anh: ";
			cin >>sv[i].anh;
		} while(dieuKienDiem(sv[i].anh)==false);
	sv[i].dtb=(sv[i].toan + sv[i].ly + sv[i].anh)/3; //tinh diem trung binh
	}
}

void hoanVi(sinhVien *sv1, sinhVien *sv2) //ham doi cho sinh vien voi nhau
{
	sinhVien temp; //chu y: bien temp thuoc kieu sinhVien
	temp=*sv1;
	*sv1=*sv2;
	*sv2=temp;
}
void sapXep(sinhVien *sv, int num)
{
	//hoan vi Toan
	if(num==1) {
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				if((sv+i)->toan < (sv+j)->toan) //sap xep giam dan
					hoanVi(sv+i, sv+j); 
			}
		}
	}
	//hoan vi Ly
	if(num==2) {
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				if(sv[i].ly < sv[j].ly)
					hoanVi(sv+i, sv+j);
			}
		}
	}
	//hoan vi tieng Anh
	if(num==3) { 
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				if(sv[i].anh < sv[j].anh)
					hoanVi(sv+i, sv+j);
			}
		}
	}
	//hoan vi DTB
	if(num==4) {
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				if((sv+i)->dtb < (sv+j)->dtb)
					hoanVi(sv+i, sv+j);
			}
		}
	}
		cout <<"\t\t\tToan" <<"\t\tLy" <<"\t\tAnh" <<"\t\tTrung Binh" <<endl; //in ra man hinh danh sach da sap xep
	for(i=0; i<n; i++) {
		cout <<"Sinh vien " <<sv[i].stt <<" :\t\t" <<sv[i].toan <<"\t\t" <<sv[i].ly <<"\t\t" <<sv[i].anh <<"\t\t" <<sv[i].dtb <<endl;
	}			
}
int main()
{
	sinhVien sv[100]; //mang 'sv' thuoc kieu 'sinhVien'
		cout <<"Nhap so luong sinh vien: n=";
		cin >>n;
	nhap(sv, n);
	int key;
		system("cls"); //lenh xoa man hinh (trinh bay cho dep)
        cout <<("****************************************\n");
        cout <<("**    	SAP XEP DANH SACH SINH VIEN    **\n");
        cout <<("**      1. Theo diem mon Toan         **\n");
        cout <<("**      2. Theo diem mon Ly           **\n");
        cout <<("**      3. Theo diem mon Anh          **\n");
        cout <<("**      4. Theo diem Trung Binh       **\n");
        cout <<("**      0. Thoat                      **\n");
        cout <<("****************************************\n");
        cout <<("**       Nhap lua chon cua ban        **\n");
        cin >>key;
	switch(key) { //lua chon
		case 1: cout <<"\nSap xep theo diem mon Toan:\n";
			sapXep(&sv[0], 1);  break;
		case 2: cout <<"\nSap xep theo diem mon Ly:\n";
			sapXep(&sv[0], 2);  break;
		case 3: cout <<"\nSap xep theo diem mon Anh:\n";
			sapXep(&sv[0], 3);  break;
		case 4: cout <<"\nSap xep theo diem Trung Binh:\n";
			sapXep(&sv[0], 4);  break;
		case 0: cout <<("\nBan da chon thoat chuong trinh!");
                break;
    }
}

