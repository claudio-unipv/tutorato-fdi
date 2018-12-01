/***********************************************************************
 * 
 * TUTORATO 8: Strutture
 * =====================
 * 
 *
 * Battaglia navale
 * ---------------------
 *
 * 1) Modifica il file definendo la struttura "rettangolo" e
 *    completando le funzioni "leggi_flotta" e "main".
 * 
 * 2) Compila il programma con il comando:
 * 
 *      gcc -Wall -o battaglia battaglia.c
 *    
 * 3) Esegui il programma digitando al terminale:
 * 
 *      ./battaglia
 *
 * 4) Verifica la correttezza della soluzione al primo esercizio:
 *     
 *      ./pvcheck ./battaglia
 *
 * 5) Completa il resto del programma e riprova ad eseguire i test
 *    finche' non vengono superati tutti.
 *
 * 6) Modifica il programma per risolvere il secondo esercizio,
 *    aggiungendo le funzioni opportune e richiamandole nella
 *    funzione "main".
 *
 * 7) Verifica la correttezza della soluzione al primo esercizio:
 *     
 *      ./pvcheck ./battaglia
 * 
 ***********************************************************************/

#include <stdio.h>

#define N_NAVI 3   /* Numero di navi che compongono la flotta. */
#define N_COLPI 5  /* Tentati concessi al giocatore. */


/* Coordinate di un punto nel piano cartesiano. */
struct punto {
  double x;
  double y;
};


/* INSERISCI LA DEFINIZIONE DI UNA STRUTTURA "rettangolo"
   COMPOSTA DA DUE PUNTI */


/* Legge da terminale le coordinate in cui si trovano le navi. */
void leggi_flotta(struct rettangolo *navi, int nnavi)
{
  int i;
  double x1, y1, x2, y2;
  for (i = 0; i < nnavi; i++) {
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    /* INSERISCI IN navi[i] LE COORDINATE x1, y1, x2, y2.
       SE NECESSARIO CAMBIA L'ORDINE DI x1, x2 E y1, y2
       IN MODO CHE VALGA x1 <= x2 E y1 <= Y2. 
     */
  }
}

/* Legge da terminale le coordinate da colpire. */
void leggi_colpi(struct punto *colpi, int n)
{
  int i;
  double x, y;
  for (i = 0; i < n; i++) {
    scanf("%lf %lf", &x, &y);
    colpi[i].x = x;
    colpi[i].y = y;
  }
}

/* Funzione principale. */
int main()
{
  /* Dati relativi a navi e proiettili. */
  struct rettangolo flotta[N_NAVI];
  struct punto colpi[N_COLPI];
 
  /* Prima fase: lettura delle posizioni delle navi. */
  leggi_flotta(flotta, N_NAVI);
  printf("[FLOTTA]\n");
  /* COMPLETA STAMPANDO LE COORDINATE DELLE NAVI. */

  /* Seconda fase: esecuzione dei colpi. */
  leggi_colpi(colpi, N_COLPI);
  /* RISOLVI IL SECONDO ESERCIZIO */

  return 0;
}
