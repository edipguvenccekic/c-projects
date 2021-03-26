#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

typedef struct daire
{
	int daire_no;
	char aile_adi[25];
	char plaka[8];
} daire;
char wait1;

char menu();
void goster();
void ekle();
//void guncelle();
//void sil();
void reset();
//void sorgula();
void kunye();

int main()
{
	int bitir = 0;
	while (bitir <= 0)
	{
		char kayit_menu = menu();
		switch (kayit_menu)
		{
		case '1':
			printf("EKLE____Bir tusa basiniz");
			wait1 =_getch();
			ekle();
			break;
		case '2':
			goster();
			printf("2");
			break;
		case '3':
			printf("3");
			//guncelle();
			break;
		case '4':
			printf("4");
			reset();
			break;
		case '5':
			printf("5");
			//sorgula();
			break;
		case '6':
			printf("6");
			//sil();
			break;
		case '0':
			kunye();
			bitir = 1;
			break;
		default:
			printf("\nLutfen 0-6 arasi bir tusa basiniz.");
			break;
		}
	}
	return 0;
}

char menu()
{
	system("cls");
	printf("\n\n\n\t\t......  SITESI\n\tPLAKA KAYIT VE SORGULAMA SISTEMI");
	printf("\n\n\n\t1. Kayit eklemek icin 1 e");
	printf("\n\t2. Kayitlari gormek icin 2 ye");
	printf("\n\t3. Kayitlari guncellemek icin 3 e");
	printf("\n\t4. Kayitlari resetlemek icin 4 e");
	printf("\n\t5. Kayitlari sorgulamak icin 5 e");
	printf("\n\t6. Kayit silmek icin 6 a");
	printf("\n\t7. Cikis icin 0'a basiniz.\n\t\t");
	char kayit = _getch();
	return kayit;
}

void ekle()
{
	system("cls");
	int i = 0;
	daire goster[10];
	FILE* kayit;
	errno_t err1;
	err1 = fopen_s(&kayit, "kayit.txt", "r+");
	while (fread(&goster[i], sizeof(goster[i]), 1, kayit) == 1)
	{
		i++;
	}
	fclose(kayit);
	printf("\nKayitli daire numaralari asagida verilmistir, bunlarin disinda bir daire numarasi seciniz:\n");
	int sira = 1;
	int j;
	for (sira = 1; sira < 10; sira++)
	{
		for (j = 0; j < i; j++)
		{
			if (goster[j].daire_no == sira)
			{
				printf("\n\t*%d", goster[j].daire_no);
			}
		}
	}

	int no;
	char buff[256];
	char aile_ad[25];
	char plaka_ekle[8];
	daire daire_ekle;

	printf("\nKayit ekle:");
	int a = 0;
	while (a < 1)
	{
		printf("\n\tEklemek istediginiz dairenin numarasini giriniz: ");
		fgets(buff, sizeof buff, stdin);
		no = atoi(buff);
		if (no <= 0 || no > 10)
		{
			printf("\n\t\tDikkat!!\n\t1-10 arasinda bir sayi giriniz.");
		}
		else
		{
			a = 1;
		}
		int b;
		for (b = 0; b < i; b++)
		{
			if (no == goster[b].daire_no)
			{
				printf("\n\t\tDikkat!!!\n\tBoyle bir kayit var.\n\t\tHerhangi bir tusa basiniz..\n");
				a = 0;
				char wait1 = _getch();
				return;
			}
		}
	}
	daire_ekle.daire_no = no;
	printf("\n%i", no);
	printf("\n\tEklemek istediginiz dairenin adini giriniz: ");
	fgets(aile_ad, sizeof aile_ad, stdin);
	strcpy_s(daire_ekle.aile_adi, sizeof aile_ad, aile_ad);
	
	printf("\n\tEklemek istediginiz dairenin plaka no giriniz: ");
	fgets(plaka_ekle, sizeof plaka_ekle, stdin);
	strcpy_s(daire_ekle.plaka, sizeof plaka_ekle, plaka_ekle);
	
	errno_t err4;
	err4 = fopen_s(&kayit, "kayit.txt", "a+");
	if (fwrite(&daire_ekle, sizeof daire_ekle, 1, kayit) != 1);
	{
		fclose(kayit);
		printf("\nKayit yapildi..");
		char wait1 = _getch();
	}
}
void goster()
{
	system("cls");
	printf("\n\tDaire no\tAile Adi\t\tPlaka");
	FILE* kayit;
	errno_t err1;
	err1 = fopen_s(&kayit, "kayit.txt", "r");

	daire goster[10];
	int i = 0;
	while (fread(&goster[i], sizeof(goster[i]), 1, kayit) == 1)
	{
		i++;
	}
	fclose(kayit);
	int sira;
	int j;
	for (sira = 1; sira < 10; sira++)
	{
		for (j = 0; j < i; j++)
		{
			if (goster[j].daire_no == sira)
			{
				printf("\n\t*%d\t\t%s\t\t%.*s", goster[j].daire_no, goster[j].aile_adi, goster[j].plaka);
			}
		}
	}
	printf("\nHerhangi bir tusa basiniz.");
	char wait2 = _getch();
}
/*
void guncelle()
{
	int no;
	int i = 0;
	FILE* kayit;
	errno_t err1;
	err1 = fopen_s(&kayit, "kayit.txt", "r");

	daire goster[10];
	system("cls");
	printf("\nKayitli Daireler:\n");
	printf("\tDaire no\tAile Adi\tPlaka\n");
	while (fread(&goster[i], sizeof(goster[i]), 1, kayit) == 1)
	{
		//printf("\n\t%d\t\t%s\t\t%s", goster[i].daire_no, goster[i].aile_adi, goster[i].plaka);
		i++;
	}
	fclose(kayit);

	int j;
	int sira;
	for (sira = 1; sira <= 10; sira++)
	{
		for (j = 0; j < i; j++)
		{
			if (goster[j].daire_no == sira)
			{
				printf("\n\t*%d\t\t%s\t\t\t%s", goster[j].daire_no, goster[j].aile_adi, goster[j].plaka);
			}
		}
	}
	int onay = 0;
	while (onay < 1)
	{
		printf("\n\nGuncellemek istediginiz dairenin numarasini yaziniz, cikis icin 0'a basiniz");
		scanf("%d", &no);
		if (no == 0)
		{
			return;
		}
		for (j = 0; j < i; j++)
		{
			if (no == goster[j].daire_no)
			{
				char yeniad[25];
				char yeniplaka[8];
				printf("\nAile adini giriniz:\t");
				scanf("%s", yeniad);
				strcpy(goster[j].aile_adi, yeniad);
				printf("\nPlaka giriniz:\t");
				scanf("%s", yeniplaka);
				strcpy(goster[j].plaka, yeniplaka);
				onay = 1;
			}
		}
	}
	kayit = fopen("kayit.txt", "w+");
	j = 0;
	for (j = 0; j < i; j++)
	{
		fwrite(&goster[j], sizeof(goster[j]), 1, kayit);
	}
	printf("Kayit guncellendi\n Bir tusa basiniz.");
	char wait1 = _getch();
	fclose(kayit);
}
*/
void reset()
{
	char onay;
	system("cls");
	printf("\n\tKayit resetleme islemi!!\n\tBu islem geri dondurulemez!!!\n\n\n\tDevam etmek icin 'E' tusuna basin yoksa herhangi bir tusa basin.");
	onay = _getch();
	switch (onay)
	{
	FILE* kayit;
	case 'e':
		printf("\nResetlendi...\nBir tusa basiniz...");
		errno_t err;
		err = fopen_s(&kayit, "kayit.txt", "w+");
		fclose(kayit);
		wait1 = _getch();
		break;
	case 'E':
		printf("\nResetlendi...\nBir tusa basiniz...");
		err = fopen_s(&kayit, "kayit.txt", "w+");
		fclose(kayit);
		wait1 = _getch();
		break;
	default:
		return;
	}
}
/*
void sorgula()
{
	bool kapi_acik = false;
	int i = 0;
	FILE* kayit;
	kayit = fopen("kayit.txt", "r");
	daire sorgula[10];
	while (fread(&sorgula[i], sizeof(sorgula[i]), 1, kayit) == 1)
	{
		i++;
	}
	fclose(kayit);
	int onay = 0;
	while (onay < 1)
	{
		system("cls");
		char plaka_sor[8];
		printf("\n\n\tPlaka Sorgulama:\n\t\tCikis icin \"menu\" yaziniz.\n\t\tArabanin plakasini giriniz: ");
		scanf("%s", plaka_sor);
		int j;
		if (strcmp(plaka_sor, "menu") == 0)
		{
			onay = 1;
			break;
		}
		int kayit_var = 0;
		for (j = 0; j < i; j++)
		{
			if (strcmp(plaka_sor, sorgula[j].plaka) == 0)
			{
				printf("\nKapi acildi....\n");
				printf("%s ailesi hosgeldiniz\n", sorgula[j].aile_adi);
				int bekle;
				kapi_acik = true;
				for (bekle = 5; bekle > 0; bekle--)
				{
					printf("\n%d", bekle);
					sleep(1);
				}
				kayit_var = 1;
				kapi_acik = false;
				break;
			}
		}
		if (kayit_var == 0)
		{
			printf("Boyle bir kayit yok.\nHerhangi bir tusa basiniz.\n");
			getch();
		}
	}
}

void sil()
{
	FILE* kayit;
	kayit = fopen("kayit.txt", "r+");
	daire sorgula[10];
	int i = 0;
	while (fread(&sorgula[i], sizeof(sorgula[i]), 1, kayit) == 1)
	{
		i++;
	}
	int j;
	system("cls");
	printf("\n\t\tKayit Silme: \n\t\tKayitli Daireler:\n");
	printf("\n\tDaire no\tAile Adi\t\tPlaka");
	for (j = 0; j < i; j++)
	{
		printf("\n\t\t%d\t\t%s\t\t%s", sorgula[j].daire_no, sorgula[j].aile_adi, sorgula[j].plaka);
	}
	fclose(kayit);
	int sil;
	printf("\n\nSilmek istediginiz kaydin daire numarasini giriniz\n");
	scanf("%d", &sil);
	getch();

	kayit = fopen("kayit.txt", "w+");
	for (j = 0; j < i; j++)
	{
		if (sil != sorgula[j].daire_no)
		{
			fwrite(&sorgula[j], sizeof(sorgula[j]), 1, kayit);
		}
	}
	fclose(kayit);
	printf("Kayit silindi.\nHerhangi bir tusa basiniz.\n");
	getch();
}
*/
void kunye()
{
	system("cls");
	printf("\n\n\t\tDersin sorumlu ogretim uyesi:\tDr. Ogr. Uyesi Guncel SARIMAN");
	printf("\n\t\tOdev sahibi:\t\t\tEdip Guvenc CEKIC");
	printf("\n\t\tOgrenci no:\t\t\t201601012");
	printf("\n\t\tHerhangi bir tusa basiniz.");
	char a = _getch();
}