#include <iostream>
using namespace std;

void printDigit(int n)
{
	switch(n) {
		case 0: cout <<"zero"; break;
		case 1: cout <<"one"; break;
		case 2: cout <<"two"; break;
		case 3: cout <<"three"; break;
		case 4: cout <<"four"; break;
		case 5: cout <<"five"; break;
		case 6: cout <<"six"; break;
		case 7: cout <<"seven"; break;
		case 8: cout <<"eight"; break;
		case 9: cout <<"nine"; break;
	}
}
void printDigits(int n)
{
	if(n<10) 
		printDigit(n);
	else {
		printDigits(n/10);
			cout <<" ";
		printDigit(n%10);
	}
}

int main()
{
	int k;
		cout <<"Enter a number (k>=0): k=";
		cin >>k;
	printDigits(k);

}

	
