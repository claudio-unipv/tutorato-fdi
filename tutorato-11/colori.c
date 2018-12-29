/***********************************************************************
 * 
 * TUTORATO 11: Preparazione all'esame
 * ===================================
 * 
 *
 * Prova del 28/11/2017
 * --------------------
 *
 * 1) Progetta una struttura dati idonea per memorizzare i dati
 *    necessari per rispondere alle domande.
 *
 * 2) Completa la funzione di lettura dei dati e la funzione main.
 *    Conviene definire una funzione aggiuntiva che stampi a video
 *    quanto letto dal file in ingresso per verificare la correttezza
 *    del programma (in seguito la chiamata a tale funzione potra`
 *    essere eliminata).
 * 
 * 3) Compila il programma con il comando:
 * 
 *      gcc -Wall -o colori colori.c
 *    
 * 3) Esegui il programma digitando al terminale
 * 
 *      ./colori tavolozza.txt
 *
 * 4) Modifica il programma in modo che risponda alla prima domanda.
 *
 * 5) Verifica la correttezza della soluzione:
 *     
 *      ./pvcheck ./colori
 *
 * 6) Ripeti i punti 4 e 5 rispondendo man mano alle altre richieste
 *    del testo.
 *
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Il limite e` definito nel testo. */
#define MAX_RIGA 80


/* INSERISCI QUI LA DEFINIZIONE DELLA/E STRUTTURA DATI NECESSARIA/E */


/* Funzione che legge i dati nel file. */
void leggi_tavolozza(const char *nomefile /* ... */ )
{
  /* MODIFICA LA FUNZIONE DI LETTURA IN MODO CHE CARICHI I DATI LETTI
     IN UNA STRUTTURA DATI.  MODIFICARE OPPORTUNAMENTE ANCHE IL TIPO
     RESTITUITO E L'ELENCO DEI PARAMETRI. */
  char riga[MAX_RIGA + 1];
  char nome_colore[MAX_RIGA + 1];
  int rosso, verde, blu;
  int n;
  FILE *f;
  int i;
  int campi;

  /* Apertura del file. */
  f = fopen(nomefile, "r");
  if (f == NULL) {
    printf("Errore nell'apertura del file\n");
    exit(1);    
  }

  /* Lettura del numero di colori n. */
  fgets(riga, MAX_RIGA + 1, f);
  sscanf(riga, "%d", &n);

  /* Lettura dei colori. */
  i = 0;
  while (fgets(riga, MAX_RIGA + 1, f) != NULL) {
    if (i >= n) {
      printf("Troppi colori!\n");
      fclose(f);
      exit(1);
    }
    campi = sscanf(riga, "%s %d %d %d", nome_colore, &rosso, &verde, &blu);
    if (campi == 4) {
      /* QUI BISOGNA MEMORIZZARE I DATI LETTI */
      i++;
    } else if (campi > 0) {
      printf("Numero di campi errato (%d)\n", campi);
      fclose(f);
      exit(1);
    }
  }

  fclose(f);

  if (i != n) {
    printf("Numero di colori errato\n");
    exit(1);
  }

  /* SE NECESSARIO AGGIUNGERE L'ISTRUZIONE RETURN. */
}


/* AGGIUNGERE LE FUNZIONI NECESSARIE PER RISPONDERE ALLE DOMANDE E LE
   EVENTUALI FUNZIONI DI APPOGGIO. */


/* Funzione principale. */
int main(int argc, char *argv[])
{
  /* Verifica della riga di comando. */
  if (argc != 2) {
    printf("UTILIZZO: ./programma FILE_COLORI\n");
    return 1;
  }

  /* MODIFICA OPPORTUNAMENTE LA FUNZIONE MAIN */
  
  /* MODIFICA LA CHIAMATA ALLA FUNZIONE DI LETTURA TENENDO CONTO DI
     COME E` STATA MODIFICATA. */
  leggi_tavolozza(argv[1]);

  /* Prima domanda. */
  /* printf("[GRIGI]\n"); */

  /* Seconda domanda. */
  /* printf("[CALDO]\n"); */

  /* Terza domanda. */
  /* printf("[SIMILE]\n"); */

  /* Quarta domanda. */
  /* printf("[INTENSITA]\n"); */

  return 0;
}
