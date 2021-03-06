#include<iostream>
using namespace std;

// Nhap danh s�ch ki�n ket don c�c so nguy�n
// ============ KHAI B�O C?U TR�C DANH S�CH LI�N K?T �ON ============
struct node
{
	int data; // du lieu cua 1 node
	struct node *pNext; // con tro d�ng de li�n ket giua c�c node voi nhau
};
typedef struct node NODE;

// khai b�o cau tr�c danh s�ch li�n ket don
struct list
{ 
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
// ============ KHOI TAO CAU TR�C DANH S�CH LI�N KET �ON ===========
void KhoiTaoDSLK(LIST &l)
{
	// cho 2 node dau v� cuoi tro den v�ng nho rong
	l.pHead = NULL;
	l.pTail = NULL;
}

// h�m khoi tao 1 c�i node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // g�n x cho data
	p->pNext = NULL;
	return p;
}


// h�m th�m node p v�o dau danh s�ch
void ThemVaoDau(LIST &l, NODE *p)
{
	// danh s�ch dang rong
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; // d�ng con tro cua node p li�n ket voi l.pHead
		l.pHead = p; // cap nhat lai l.pHead l� p
	}
}

// h�m th�m node p v�o cuoi danh s�ch
void ThemVaoCuoi(LIST &l, NODE *p)
{
	// danh s�ch dang rong
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p; // cap nhat lai l.pTail l� p
	}
}

// xuat danh s�ch li�n ket don
void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// Th�m node p v�o sau node q(nam trong danh s�ch li�n ket don)
void ThemNode_p_VaoSauNode_q(LIST &l, NODE *p) //them bat ky vi tri
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	// neu danh s�ch chi c� 1 phan tu v� phan tu d� cung ch�nh l� node q ==> b�i to�n tro th�nh ki thuat th�m v�o cuoi danh s�ch
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoCuoi(l, p);
	}
	else
	{
		// duyet tu dau danh s�ch den cuoi danh s�ch de t�m node q
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			// neu node q c� t?n t?i th�....
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNode(p->data); // khoi tao node h moi de th�m v�o sau node q 
				NODE *g = k->pNext; // cho node g tro den node nam sau node q
				h->pNext = g; // Buoc 1: Tao moi li�n ket tu node h den node g <=> cung ch�nh l� tao moi li�n ket tu node h den node nam sau node q
				k->pNext = h; // Buoc 2: Tao moi li�n ket tu node q den node h <=> ch�nh l� node k den node h
			}
		}
	}
}
void xoaDau(LIST &l)
{
	l.pHead=l.pHead->pNext;
}
void xoaCuoi(LIST &l)
{
	NODE *p=l.pHead;
	while(p->pNext->pNext!=NULL) {
		p=p->pNext;
	}
	p->pNext=NULL;	
}
// menu
void Menu(LIST &l)
{
	int luachon;
	while (69)
	{
		system("cls");
		cout << "\n\n\t\t========== Menu ==========";
		cout << "\n\t1. Them node vao danh sach";
		cout << "\n\t2. Xuat danh sach lien ket don";
		cout << "\n\t3. Them node p vao sau node q trong danh sach";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t========== End ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon < 0 || luachon > 3)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai !";
			system("pause"); // dung m�n h�nh
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x); // khoi tao 1 c�i node
			ThemVaoCuoi(l, p); // th�m node v�o cuoi danh s�ch
		}
		else if (luachon == 2)
		{
			XuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao sau: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoSauNode_q(l, p); // th�m node p v�o sau node q trong danh s�ch l
		}
		else
		{
			break; // tho�t khoi v�ng lap hien tai
		}
	}
}

int main()
{
	LIST l;
	KhoiTaoDSLK(l); // lu�n lu�n goi h�m khoi tao danh s�ch li�n ket don truoc khi thao t�c voi danh s�ch
	Menu(l);

	system("pause");
	return 0;
}
