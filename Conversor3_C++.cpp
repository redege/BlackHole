#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SAIR 0
#define BINARIO 2
#define OCTAL 8 
#define HEXADECIMAL 16
#define DECIMAL 10

using namespace std;

int entrada();
int saida();
int ler();
void Dec_Bin(int valor);
int Dec_Oct(int valor);
int Dec_Hex(int valor);
void converter_bases(void);
void bin_dec(void);

int main(int argc, char** argv){
	    int ler();
		int resultado;
		char valor;
		resultado = -1;
		while(resultado == -1){
			cout << "\n";
			cout << "\nMenu Principal\n";
			cout << "--------------\n\n";
			cout << "S - Sair" << endl;
			cout << "B - Binário" << endl;
			cout << "H - Hexadecimal" << endl;
			cout << "O - Octal" << endl;
			cout << "Y - Escrever Binário/Decimal" << endl;
			cout << "X - Escrever Hexadecimal/Decimal" << endl;
			cout << "L - Ler número em decimal para converter" << endl;
			cin >> valor;
			
			switch(valor){
				case 's': case 'S': resultado = SAIR;
				system("cls");
				  break;
				case 'b': case 'B': resultado = BINARIO;
				  break;
				case 'h': case 'H': resultado = HEXADECIMAL;
				  break;
				case 'o': case 'O': resultado = OCTAL;
				  break;
				case 'y': case 'Y': resultado = DECIMAL;
				  break;
				saida();	
			}	
		}
		return(resultado);
}
void Dec_Bin(int valor){
		int quociente, resto;
		    if (valor!=0){
		    	quociente = valor / 2;
		    	resto = valor - quociente*2;
		    	Dec_Bin(quociente);
		    	cout << resto;
			}
	}
	
	int Dec_Oct(int valor){
		register int quociente;
		/*if ((quociente = (valor/8) != 0){
			return(valor - (quociente * 8))
		}*/
		if (quociente = (valor >> 3 )){
			cout << Dec_Oct(quociente);
			return (valor - quociente << 3);
		}        
	}
	
	int Dec_Hex(int valor){
		    int quociente, resto;
		    if(valor){
		    	quociente = valor / 16;
		    	resto = valor - quociente * 16;
		    	Dec_Hex(quociente);
		    	
		    	switch(resto){
		    		case 10: cout << 'A'; break;
		    		case 11: cout << 'B'; break;
		    		case 12: cout << 'C'; break;
		    		case 13: cout << 'D'; break;
		    		case 15: cout << 'E'; break;
		    		case 16: cout << 'F'; break;
		    		default: cout << '0' + resto;
				}
			}
	}
	
    void bin_dec(void){
		int pos, decimal=0;
		char numb[17];
		int cont=0;
		
		cout << "Digite um número binário qualquer: " << endl;
		cin >> numb;
		
		for(pos=strlen(numb)-1; pos>=0; pos--){
			decimal = decimal + (numb[cont++] - '0') * pow(2,pos);
			cout << "O número em binário é: " << decimal << endl;
		}
	}
	
	void converter_bases(void){
	    int oper = DECIMAL, numero;
	    cout << "Digite um número e selecione uma opção abaixo: " << endl;
	    
	    while(oper != SAIR){
	    	switch(oper){
	    		case 2: Dec_Bin(numero); break;
	    		case 8: cout << Dec_Oct(numero); break;
	    		case 16: Dec_Hex(numero); break;
	    		case 10: cin >> numero; break;
			}
			oper = ler();
			cout << "O número digitado na base solicitada é: " << endl;
		}
	}
