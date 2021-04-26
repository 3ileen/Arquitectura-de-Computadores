#include<iostream>

using namespace std;
//funciones 
void add(int p[], int s[], int q);

void complemento(int p[], int q) {
	int s[8] = { NULL }; 
	s[0] = 1;
	for (int i = 0; i < q; i++) {p[i] = (p[i] + 1) % 2;}
	add(p, s, q);
}

void add(int ac[], int s[], int q) {
	int b = 0;
	for (int i = 0; i < q; i++) {
		ac[i] = ac[i] + s[i] + b;
		if (ac[i] > 1) {
			ac[i] = ac[i] % 2;
			b = 1;}
		else b = 0;
	}
}

void t_a(int ac[], int qr[], int &qn, int q) {
	int temp, i;
	temp = ac[0];
	qn = qr[0];
	for (i = 0; i < q - 1; i++) {
		ac[i] = ac[i + 1];
		qr[i] = qr[i + 1];
	}
	qr[q - 1] = temp;
}

void mostrar(int ac[], int qr[], int qrn) {
	int i;
	for (i = qrn - 1; i >= 0; i--)
		cout << ac[i];
	cout << " ";
	for (i = qrn - 1; i >= 0; i--)
		cout << qr[i];
}

int main(int argc, char **argv) {
	int mt[10], br[10], qr[10], sc, ac[10] = { 0 };
	int multiplicando, multiplicador, i, qn, temp;
	
	cout << "*****    Algoritmo de booth    *****";
	cout<<"\n Give space while providing the binary number number between the two bits";
	cout << "\n No. Multipplicando: ";
	cin >> multiplicando;
	
	
	for (i = multiplicando - 1; i >= 0; i--)
		cin >> br[i];                //multiplicando
	for (i = multiplicando - 1; i >= 0; i--)
		mt[i] = br[i];
	complemento(mt, multiplicador);
	cout << "\nMultiplicador: ";
	cin >> multiplicador;
	sc = multiplicador;

	
	for (i = multiplicador - 1; i >= 0; i--)
		cin >> qr[i];
	qn = 0;
	temp = 0;
	cout << "qn\tq[n+1]\t\tBR\t\tAC\tQR\t\tsc\n";
	cout << "\t\t\tinicia\t\t";
	
	mostrar(ac, qr, multiplicador);
	cout << "\t\t" << sc << "\n";
	
	while (sc != 0) {
		cout << qr[0] << "\t" << qn;
		if ((qn + qr[0]) == 1) {
			if (temp == 0) {
				add(ac, mt, multiplicador);
				cout << "\t\trestando BR\t";
				for (i = multiplicador - 1; i >= 0; i--)
					cout << ac[i];
				temp = 1;
			}
			else if (temp == 1) {
				add(ac, br, multiplicador);
				cout << "\t\tsumando BR\t";
				for (i = multiplicador - 1; i >= 0; i--)
					cout << ac[i];
				temp = 0;
			}
			cout << "\n\t";
			t_a(ac, qr, qn, multiplicador);
		}
		else if (qn - qr[0] == 0)
			t_a(ac, qr, qn, multiplicador);
		mostrar(ac, qr, multiplicador);
		cout << "\t";
		sc--;
		cout << "\t" << sc << "\n";
	}
	
	cout << "Resultado: ";
	mostrar(ac, qr, multiplicador);
}
