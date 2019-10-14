/*
	binario para decimal
	decimal para binario
	
	13/10/19 Lucas Vinicius
*/

#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <stack>

using namespace std;

// Global variables
char op;
int   i;

// Functions
void DecimalForBinary();
void BinaryForDecimal();

int main() {
	
	static bool sair = true;
	
	do {
		
		system("cls");
		
		cout << endl <<"         ---Menu---";
		cout << endl;
		cout << endl << "Decimal para binario: [1]";
		cout << endl << "Binario para Decimal: [2]";
		cout << endl;
		cout << endl << "        Sair:   [3]";
		op = getch();
			
		switch (op) {
			case '1': {
				DecimalForBinary();
				break;
			}
			case '2': {
				BinaryForDecimal();
				break;
			}
			case '3': {
				sair = false;
				break;
			}
		}
	} while (sair);
	
	
	return 0;
}

void DecimalForBinary() {
	
	int num, resto =0;
	int tam = 0;
	stack <int> binar;
	
	do {
		system("cls");
		
		cout << "Informe o numero: ";
		cin >> num;
		
		for ( ;num>0; ) {
			
			resto = num%2;
			num /= 2;
			binar.push(resto);
		}
		
		tam = binar.size();
		
		for ( ;tam>0;tam--) {
			
			cout << binar.top();
			binar.pop();
		}
		
		cout << endl << "Deseja continuar\?";
		cout << "[S-N]";
		op = toupper(getch());
	} while (op == 'S');
	
	
} // end DecimalForBinary()

	
void BinaryForDecimal() {
	
	stack <int> decimal;
	int tam = 0;
	int resul=0;
	char num;
	int i, x;
	
	decimal.push(0);
	
	do {
	 	
		system("cls");
		cout << "Informe o numero em binario(0 ou 1): ";
		
		for ( ; ; ) {
			
			num = getche();
			
			if (num == '1') 
				decimal.push(1);
			else if (num == '0')
				decimal.push(0);
			else 
				break;
		}	
		
		tam = decimal.size();
		
		cout << endl;
		
		for (i=0 ;i<tam-1; i++) {
			x = pow(2,i);
			resul += (decimal.top()*x);
			decimal.pop();
		}
		
		cout << endl << endl << resul;
		
		cout << endl << "Deseja continuar\?";
		cout << "[S-N]";
		op = toupper(getch());	
	} while (op == 'S');
	
	
} // end BinaryForDecimal()



