/***********************************************************************
 * 
 * TUTORATO 11: Preparazione all'esame
 * ===================================
 * 
 *
 * Prova del 2/7/2018
 * ------------------
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
 *      gcc -Wall -o distributore distributore.c
 *    
 * 3) Esegui il programma digitando al terminale
 * 
 *      ./distributore chiavetta.txt
 *
 * 4) Modifica il programma in modo che risponda alla prima domanda.
 *
 * 5) Verifica la correttezza della soluzione:
 *     
 *      ./pvcheck ./distributore
 *
 * 6) Ripeti i punti 4 e 5 rispondendo man mano alle altre richieste
 *    del testo.
 *
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Valore indicato nel testo. */
#define MAXRIGA 80


/* INSERISCI QUI LA DEFINIZIONE DELLA/E STRUTTURA DATI NECESSARIA/E */


/* Funzione che legge i dati nel file. */
void leggi_storico(char *nomefile /* ... */)
{
  /* MODIFICA LA FUNZIONE DI LETTURA IN MODO CHE CARICHI I DATI LETTI
     IN UNA STRUTTURA DATI.  MODIFICARE OPPORTUNAMENTE ANCHE IL TIPO
     RESTITUITO E L'ELENCO DEI PARAMETRI. */
  char riga[MAXRIGA + 1];
  FILE *f;
  char bevanda[MAXRIGA + 1];
  int importo;
  int orario;
  int campi;

  /* Apertura del file. */
  f = fopen(nomefile, "r");
  if (f == NULL) {
    printf("Errore nell'apertura del file\n");
    exit(1);
  }

  /* Lettura delle righe. */
  while (fgets(riga, MAXRIGA + 1, f) != NULL) {
    campi = sscanf(riga, "%d %s %d", &orario, bevanda, &importo);
    if (campi == 3) {
      /* QUI BISOGNA MEMORIZZARE I DATI LETTI */
    } else if (campi > 0) {
      printf("Numero di campi errato (%d)\n", campi);
      fclose(f);
      exit(1);
    }
  }
  
  fclose(f);

  /* SE NECESSARIO AGGIUNGERE L'ISTRUZIONE RETURN. */
}


/* AGGIUNGERE LE FUNZIONI NECESSARIE PER RISPONDERE ALLE DOMANDE E LE
   EVENTUALI FUNZIONI DI APPOGGIO. */


/* Funzione principale. */
int main(int argc, char *argv[])
{
  /* Verifica della riga di comando. */
  if (argc != 2) {
    printf("UTILIZZO: ./programma FILE_DATI\n");
    return 1;
  }

  /* MODIFICA OPPORTUNAMENTE LA FUNZIONE MAIN */
  
  /* MODIFICA LA CHIAMATA ALLA FUNZIONE DI LETTURA TENENDO CONTO DI
     COME E` STATA MODIFICATA. */

  leggi_storico(argv[1]);
  
  /* Prima domanda. */
  /* printf("[RESIDUO]\n");  */

  /* Seconda domanda. */
  /* printf("[MASSIMO]\n");  */

  /* Terza domanda. */
  /* printf("[RICARICHE]\n"); */

  /* Quarta domanda. */
  /* printf("[CAFFE]\n");  */

  return 0;
}

