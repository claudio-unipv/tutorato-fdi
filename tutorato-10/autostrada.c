/***********************************************************************
 * 
 * TUTORATO 10: Strutture Dati
 * ===========================
 * 
 *
 * Autostrada
 * ---------------------
 *
 * 1) Modifica il file completando la definizione della lista e delle
 * operazioni che la manipolano.  Modifica in modo opportuno anche la
 * funzione "main", e aggiungi altre funzioni se necessario.
 * 
 * 2) Compila il programma con il comando:
 * 
 *      gcc -Wall -o autostrada autostrada.c
 *    
 * 3) Esegui il programma digitando al terminale, per 
 * 
 *      ./autostrada autostrada10.txt
 *
 * 5) Verifica la correttezza della soluzione:
 *     
 *      ./pvcheck ./autostrada
 *
 * 6) Integra la funzione main per rispondere alla seconda domanda.
 * 
 * 5) Verifica la correttezza della soluzione:
 *     
 *      ./pvcheck ./autostrada
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Costanti specificate nel testo del problema. */
#define MAX_TARGA 7
#define MAX_RIGA 40
#define LIMITE 130

/* SCHEMA DELLA SOLUZIONE
 * 
 * Viene definita una lista concatenata per memorizzare i passaggi
 * delle automobili.
 *
 * Ad ogni passaggio, si verifica se la lista contiene gia` un dato
 * relativo alla stessa automobile.
 *
 * - in caso negativo si aggiunge un nuovo elemento in testa;
 *
 * - in caso positivo si calcola la velocita` e si rimuove il primo
 *   passaggio dalla lista.
 *
 * L'uso di una lista concatenata e` giustificata dal fatto che il
 * numero di elementi memorizzati varia nel corso dell'esecuzione del
 * programma, e non e` neppure immediatamente determinabile un limite
 * superiore (altrimenti si sarebbe potuto utilizzare piu`
 * semplicemente un array).
 */


/* DEFINISCI 'struct passaggio' IN MODO CHE POSSA MEMORIZZARE LE
   INFORMAZIONI IN UNA RIGA DEL FILE. */


/* Ciascun nodo della lista contiene le informazioni su un
   passaggio. */
struct nodo_passaggio {
  struct passaggio value;
  struct nodo_passaggio *next;
};

/* Il puntatore e` un sinonimo per il tipo della lista. */
typedef struct nodo_passaggio *lista_passaggi;


/* Funzione che inserisce un nuovo passaggio in testa alla lista l.
   Restituisce un puntatore alla nuova testa della lista. */
lista_passaggi inserisci_passaggio(lista_passaggi l, struct passaggio p)
{
  /* COMPLETA LA FUNZIONE */
}


/* Cerca nella lista l un passaggio corrispondente alla targa data.
   In caso positivo restituisce un puntatore al nodo, in caso negativo
   restituisce un puntatore nullo. */
lista_passaggi trova_passaggio(lista_passaggi l, const char *targa)
{
  /* COMPLETA LA FUNZIONE */
}


/* Cancella il nodo puntato da pos in l. Restituisce un puntatore al
   primo nodo della lista risultante. */
lista_passaggi cancella_passaggio(lista_passaggi l, lista_passaggi pos)
{
  /* COMPLETA LA FUNZIONE */
}


/* Cancella tutti i nodi di l. */
void cancella_passaggi(lista_passaggi l)
{
  /* COMPLETA LA FUNZIONE */
}


/* Legge una riga da f e memorizza il passaggio corrispondente in
   *p. Restituisce 1 in caso di lettura correttamente eseguita e 0 in
   caso di errore o di sopraggiunta fine del file. */
int leggi_passaggio(FILE * f, struct passaggio *p)
{
  char targa[MAX_RIGA + 1];
  int hh, mm, ss;
  int campi;

  campi = fscanf(f, "%s %d:%d:%d", targa, &hh, &mm, &ss);
  if (campi < 4)
    return 0;

  /* COMPLETA ASSEGNANDO I VALORI LETTI AI CAMPI IN *p */

  return 1;
}


int main(int argc, char *argv[])
{
  
  lista_passaggi passaggi = NULL;
  lista_passaggi r;
  struct passaggio p;
  FILE *f;
  double distanza;
  
  /* apertura del file e lettura della distanza tra i rilevamenti. */
  if (argc != 2) {
    printf("Utilizzo: ./multe FILE_PASSAGGI\n");
    return 1;
  }

  f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("main");
    return 1;
  }
  fscanf(f, "%lf", &distanza);

  printf("[VELOCITA]\n");

  /* Ciclo principale, eseguito per ogni riga del file. */
  while (leggi_passaggio(f, &p) == 1) {
    /* COMPLETA AGGIUNGENGO O RIMUOVENDO p DALLA LISTA, A SECONDA CHE
       SI TRATTI DEL PRIMO O DEL SECONDO PASSAGGIO. */
  }
  fclose(f);

  // printf("[MULTE]\n");

  /* Libera le risorse acquisite (memoria allocata). */
  cancella_passaggi(passaggi);
  return 0;
}
