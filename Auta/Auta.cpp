// Auta.cpp : Defines the entry point for the application.
//

#include "Auta.h"

#include <stdio.h>
#include <ctype.h>              // tolower
#include <stdlib.h>				// system

#include "AutaDB.h"

struct t_album* prvni = NULL; // globalni ukazatel na prvni auto

void OnAdd()
{
	char my_name[JMENO_ALBA];
	char in_name[JMENO_INTERPRETA];
	int my_year;

	printf("\nJmeno alba : ");         // dotazeme se na polozky
	scanf_s("%[^\n]s", my_name, JMENO_ALBA);
	while (getchar() != '\n');
	printf("\nJmeno interpreta : ");
	scanf_s("%[^\n]s", in_name, JMENO_INTERPRETA);
	while (getchar() != '\n');
	printf("\nRok Vydani : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	add(my_name, my_year, in_name, &prvni);         // volame pridavaci funkci
}

void OnDel()
{
	int my_year;

	printf("\nRok Vydani : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	del(my_year, &prvni);         // volame mazaci funkci
}

void ShowCars()
{
	struct t_album* aktAlbum = prvni; // ukazatel na aktualni auto
	printf("\n\n");
	while (aktAlbum) // prochazeni seznamu
	{
		printf("%d: %s , %s \n", aktAlbum->rok, aktAlbum->jmeno_alba, aktAlbum->jmeno_interpreta); // tisk radku
		aktAlbum = aktAlbum->dalsi; // posun na dalsi auto
	}
	getchar();
}


int main()
{
	char  cmd;

	do
	{
		system("cls");		// smaze obrazovku
		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("Q: Konec\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			OnAdd();					// volame pridani
			break;
		case 'd':
			OnDel();					// volame mazani
			break;
		case 'p':
			ShowCars();
			break;
		}
	} while (cmd != 'q');     // koncime az pri Q
	return 0;
}

