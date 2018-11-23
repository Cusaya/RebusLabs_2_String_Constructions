#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(){

	char s[100] = "abcd";
	char p[100] = {'\0'};

	p[0] = s[0]; //a

	int s_iter = 1; // arzulanan ilk index

	int dolar = 1;
	printf("Satin almak lazim!\n");
	printf("Satin alinmis hali: %s\n", p);

yenilendi:;

	/////////////////////////////////// Calisan substring! 
	int p_lenght = strlen(p);

	int kombinasyon_sayisi = p_lenght * (p_lenght + 1) / 2;

	int tutmama_sayisi=0;


	//bitis kontrolu!
	if (strlen(p) == strlen(s))
		goto finish;


	for (int i = p_lenght; i > 0; i--){  // max substring uzunlugundan(strlen) -> min substring(1) uzunluguna!
		for (int k = 0; k <= p_lenght-i; k++) {   // yalnızca baslangic indisi! baska bir sey degil! kac adet olabilecekse ve sira ile!
			int final_indis = k + i - 1; // baslangic indisine bagli "final indisi"!
			char temp[100] = { '\0' };

			for (int gez = k; gez <= final_indis; gez++) { // kombinasyon (substring) dizisi olusturucu !
				printf("%c ", p[gez]);
				temp[gez-k] = p[gez];
			}

			printf("\n");
			printf("temp : %s \n", temp);   // kombinasyon (substring) dizisi!  ( indis'i 0'dan i-1'e kadar! Daima!)

			int count = 0;
			for (int comparor = 0; comparor <= i - 1; comparor++)
				if (s[s_iter + comparor] == temp[comparor])
					count++;
			if (count == i) {
				printf("Yuzde yuz tuttu! Yapistiriyoruz!\n");
				strcat(p,temp);
				printf("Yeni p = %s\n", p);
				s_iter += i;
				goto yenilendi;
			}
			else {
				tutmama_sayisi++;
				if (tutmama_sayisi == kombinasyon_sayisi) {
					printf("Satin almak lazim!\n");					
					p[s_iter] = s[s_iter];
					s_iter++;
					printf("Satin alinmis hali: %s\n", p);
					dolar++;
					goto yenilendi;
				}
			}
		}
	}

finish:;
	printf("Toplam maliyet : %d $ !\n", dolar);

	return dolar;

}
