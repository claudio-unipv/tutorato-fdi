/***********************************************************************
 * 
 * TUTORATO 9: File
 * ================
 * 
 *
 * Formula 1
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
 *      ./pvcheck ./formula1
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
 *      ./pvcheck ./formula1
 * 
 ***********************************************************************/

#include <stdio.h>
#include <string.h>

/* Alcune costanti utili definite nel testo dell'esercizio. */
#define N_SQUADRE 10
#define N_PILOTI 20
#define MAX_RIGA 50

#define POS_A_PUNTI 10		/* Posizioni a cui si assegnano punti */


int punteggio(int posizione)
{
}


/* A differenza dei dati da elaborare, non e` una cattiva idea
   memorizzare quelli COSTANTI in variabili globali, in modo che siano
   accessibili in tutto il programma. */
int punti_per_pos[POS_A_PUNTI] = {
  25, 18, 15, 12, 10, 8, 6, 4, 2, 1
};

/* I dati saranno memorizzati in array di strutture.  Piloti e squadre
   richiedono lo stesso tipo di informazioni (nome e punteggio).
   Pertanto conviene utilizzare lo stesso tipo, in questo modo si
   evitera` di replicare le funzioni che effettuano le
   elaborazioni. */
struct classificato {
  char nome[MAX_RIGA + 1];	/* Nome del pilota o della squadra */
  int punti;
};


/* Cerca in un array il record di informazioni corrispondente al nome
   specificato.  Se tale record non esiste, viene inizializzato il
   primo record non ancora utilizzato.  I record non utilizzati si
   riconoscono dal fatto che il nome inizia con il terminatore '\0'
   (cioe` il nome e` una stringa vuota). */
struct classificato *cerca_classificato(struct classificato
					*elenco, int size,
					char *nome)
{
  int i = 0;
  for (i = 0; i < size; i++) {
    if (strcmp(elenco[i].nome, nome) == 0)
      return &elenco[i];	/* Trovato */
    if (elenco[i].nome[0] == '\0') {
      /* Trovato un record vuoto, da inizializzare 
         con il nome prima di restituirlo. */
      strcpy(elenco[i].nome, nome);
      elenco[i].punti = 0;
      return &elenco[i];
    }
  }
  /* Non si dovrebbe mai arrivare qui. */
  return NULL;
}

/* Legge una gara dal file e aggiorna i punteggi negli array
   conententi informazioni su piloti e scuderie.  Restituisce il
   numero di righe elaborate (quindi 0 se e` terminato il file, oppure
   un numero di righe pari al numero dei piloti). */
int leggi_gara(FILE * fin,
	       struct classificato *piloti,
	       struct classificato *scuderie)
{
  char nome_pilota[MAX_RIGA + 1];
  char nome_scuderia[MAX_RIGA + 1];

  pos = 0;
  /* Continua finche' si registra il risultato di tutti i 
     piloti attesi e, contemporaneamente, finche' ci sono 
     righe nel file. */
  while (pos < N_PILOTI
	 && fgets(buffer, MAX_RIGA + 1, fin) != NULL) {

    sscanf(buffer, "%s %s", nome_pilota, nome_scuderia);

    if (pos < POS_A_PUNTI)
      punti = punti_per_pos[pos];
    else
      punti = 0;

    /* Cerca il pilota nell'elenco e gli assegna 
       i punti. */
    struct classificato *pilota =
	cerca_classificato(piloti, N_PILOTI, nome_pilota);
    pilota->punti += punti;

    /* Cerca la squadra nell'elenco e gli assegna 
       i punti. */
    struct classificato *scuderia =
	cerca_classificato(scuderie, N_SQUADRE,
			   nome_scuderia);
    scuderia->punti += punti;

    /* Passaggio alla posizione successiva. */
    pos++;
  }
  return pos;
}

/* Riordina gli elementi per generare la classifica finale. */
void ordina_classifica(struct classificato *elenco,
		       int size)
{
  /* Doppio bubblesort (variante stabile). In alternativa 
     si sarebbe potuto utilizzare una singola passata 
     di ordinamento che tenesse conto di entrambi i 
     criteri. */

  int scambi;
  int i;
  struct classificato temp;

  /* Ordinamento alfabetico per nome. */
  do {
    scambi = 0;
    for (i = 1; i < size; i++) {
      if (strcmp(elenco[i].nome, elenco[i - 1].nome) < 0) {
	temp = elenco[i];
	elenco[i] = elenco[i - 1];
	elenco[i - 1] = temp;
	scambi++;
      }
    }
  } while (scambi > 0);

  /* Ordinamento per punteggio decrescente. */
  do {
    scambi = 0;
    for (i = 1; i < size; i++) {
      if (elenco[i].punti > elenco[i - 1].punti) {
	temp = elenco[i];
	elenco[i] = elenco[i - 1];
	elenco[i - 1] = temp;
	scambi++;
      }
    }
  } while (scambi > 0);
}

/* Inizializza tutti i record in modo che siano riconoscibili come
   vuoti.*/
void inizializza_elenco(struct classificato *elenco,
			int size)
{
  int i;
  for (i = 0; i < size; i++)
    elenco[i].nome[0] = '\0';
}

/* Funzione principale. */
int main(int argc, char *argv[])
{
  struct classificato piloti[N_PILOTI];
  struct classificato scuderie[N_SQUADRE];
  FILE *fin;
  int i;

  if (argc != 2) {
    printf("Utilizzo: ./formula1 FILE_RISULTATI\n");
    return 1;
  }

  /* Inizializzazione */
  inizializza_elenco(piloti, N_PILOTI);
  inizializza_elenco(scuderie, N_SQUADRE);

  /* Lettura dei dati */
  fin = fopen(argv[1], "rt");
  while (leggi_gara(fin, piloti, scuderie) != 0) {
    /* Nulla da fare qui... */
  }
  fclose(fin);

  /* Ordinamento */
  ordina_classifica(piloti, N_PILOTI);
  ordina_classifica(scuderie, N_SQUADRE);

  /* Stampa dei risultati */
  printf("[CLASSIFICA_PILOTI]\n");
  for (i = 0; i < N_PILOTI; i++)
    printf("%s %d\n", piloti[i].nome, piloti[i].punti);
  printf("\n");

  printf("[CLASSIFICA_SQUADRE]\n");
  for (i = 0; i < N_SQUADRE; i++)
    printf("%s %d\n", scuderie[i].nome, scuderie[i].punti);
  printf("\n");

  return 0;
}
