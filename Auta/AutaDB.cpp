#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AutaDB.h"

void add(char* Jmeno, int rok_vydani, char* Jmeno_I, struct t_album** uk_prvni) // pridani auta
{
	struct t_album* noveAlbum; // ukazatel pro nove vkladane auto
	struct t_album* aktAlbum; // ukazatel na aktualni auto

	// alokace dynamicke promenne
	noveAlbum = (struct t_album*)malloc(sizeof(struct t_album));

	strcpy_s(noveAlbum->jmeno_alba, JMENO_ALBA, Jmeno); // naplneni struktury
	strcpy_s(noveAlbum->jmeno_interpreta, JMENO_INTERPRETA, Jmeno_I);
	noveAlbum->rok = rok_vydani;
	noveAlbum->dalsi = NULL;

	if (*uk_prvni == NULL) // linearni seznam je prazdny
	{
		*uk_prvni = noveAlbum;
		return;
	}
	else if (strcmp(noveAlbum->jmeno_interpreta , (*uk_prvni)->jmeno_interpreta)>0) // vlozime na zacatek
	{
		noveAlbum->dalsi = *uk_prvni;
		*uk_prvni = noveAlbum;
		return;
	}

	aktAlbum = *uk_prvni;
	while (aktAlbum) // prochazeni seznamu
	{
		if (aktAlbum->dalsi == NULL) // jsme na poslednim aute
		{
			aktAlbum->dalsi = noveAlbum; // pridavame na konec
			return;
		}
		else if (strcmp(noveAlbum->jmeno_interpreta , aktAlbum->dalsi->jmeno_interpreta)>0)
		{
			noveAlbum->dalsi = aktAlbum->dalsi; // vlozime za aktAuto
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		aktAlbum = aktAlbum->dalsi; // posun na dalsi auto
	}
}

void del(int rok, struct t_album** uk_prvni)
{
	struct t_album* aktAlbum;

	while (*uk_prvni && (*uk_prvni)->rok == rok)
	{
		struct t_album* newPrvni = (*uk_prvni)->dalsi;
		free(*uk_prvni);  // uvolneni auta z pameti
		*uk_prvni = newPrvni;
	}

	aktAlbum = *uk_prvni;
	while (aktAlbum && aktAlbum->dalsi) // prochazeni seznamu
	{
		if (aktAlbum->dalsi->rok == rok) // auto je ke smazani
		{
			struct t_album* newDalsi = aktAlbum->dalsi->dalsi;
			free(aktAlbum->dalsi);  // uvolneni auta z pameti
			aktAlbum->dalsi = newDalsi;
		}
		aktAlbum = aktAlbum->dalsi; // posun na dalsi auto
	}
}