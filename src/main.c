/*
 * Davi Pincinato - RA 157810
 * EA 879 - Prof. Tiago Tavares
 * Atividade 1
 * Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 * Tabela ASC II extraída de : http://www.spectrum.eti.br/news/tabela_ascii_completa 
 */

#include <stdio.h>
#include <string.h>
 

char texto[1000];
int qtd_de_caracteres, qtd_de_palavras = 0;
int i=0;

int main() {

scanf("%[^\n]s", &texto);
qtd_de_caracteres = strlen(texto); 

	while(i <= qtd_de_caracteres){
 
//Se o ponteiro verificar um caractere de separação de palavras (como " ", "-", "!", "." ou "," - vide tabela ASC II), considerar o fim de uma palavra.
 		if(     (32 <= texto[i] && texto[i] <= 47) ||
			(58 <= texto[i] && texto[i] <= 64) ||
			(91 <= texto[i] && texto[i] <= 96) ||
			(texto[i] == '\0')){

		 	i++;

//Se após um dos caracteres de separação de palavras (como " ", "-", "!", "." ou "," - vide tabela ASC II) houver novamente um desses caracteres, somente incrementar o ponteiro.
			while( 
				(32 <= texto[i] && texto[i] <= 47) ||
				(58 <= texto[i] && texto[i] <= 64) ||
				(91 <= texto[i] && texto[i] <= 96)){ 
				
 				i++;
			}

//Se entre o "." ou "," haviam 2 números (caracteres 48 a 57 da tabela ASC II), não considerar somando uma nova palavra.
			if(texto[i-1] == '.' || texto[i-1]==','){
					if(48 <= texto[i] && texto[i] <= 57){ 
						qtd_de_palavras= qtd_de_palavras - 1;
				}	
		
			} 
				qtd_de_palavras++; 
		}
		i++;
	}

// Imprime na tela a quantidade de palavras digitadas na entrada.
printf("%d\n", qtd_de_palavras);

return 0;
}





