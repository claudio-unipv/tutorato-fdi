/***********************************************************************
 * 
 * TUTORATO 9: File
 * ================
 * 
 *
 * Formula 1
 * ---------------------
 *
 * 1) Modifica il file completando le funzioni "punteggio",
 *    "leggi_gara" e "main".
 * 
 * 2) Compila il programma con il comando:
 * 
 *      gcc -Wall -o formula1 formula1.c
 *    
 * 3) Esegui il programma digitando al terminale, per 
 * 
 *      ./formula1 campionato10.txt
 *
 * 4) Completa con l'ordinamento delle classifiche.
 *
 * 5) Verifica la correttezza della soluzione:
 *     
 *      ./pvcheck ./formula1
 *
 * Anche se le due richieste sono molto simili, si puo` iniziare con
 * la gestione della sola classifica dei piloti.  La classifica dei
 * team puo` essere aggiunta in un secondo momento.
 * 
 ***********************************************************************/

#include <stdio.h>
#include <string.h>

/* Alcune costanti utili definite nel testo dell'esercizio. */
#define N_SQUADRE 10
#define N_PILOTI 20
#define MAX_RIGA 50


/* I dati saranno memorizzati in array di strutture.  Piloti e squadre
   richiedono lo stesso tipo di informazioni (nome e punteggio).
   Pertanto conviene utilizzare lo stesso tipo, in questo modo si
   evitera` di replicare le funzioni che effettuano le
   elaborazioni. */
struct classificato {
  char nome[MAX_RIGA + 1];	/* Nome del pilota o della squadra */
  int punti;
};


/* Calcola i punti che spettano per la posizione data. */
int punteggio(int posizione)
{
  /* COMPLETA LA FUNZIONE */
}


/* Legge una gara dal file e aggiorna i punteggi negli array
   contenenti informazioni su piloti e scuderie.  Restituisce 0 se il
   file e` finito, 1 altrimenti. */
int leggi_gara(FILE * file,
	       struct classificato *piloti,
	       struct classificato *scuderie)
{
  char nome_pilota[MAX_RIGA + 1];
  char nome_scuderia[MAX_RIGA + 1];

  /* COMPLETA LA FUNZIONE */
}


/* Ordina la classifica. */
void ordina_classifica(struct classificato *a, int n)
{
  /* COMPLETA LA FUNZIONE IMPLEMENTANDO UN QUALUNQUE ALGORITMO DI
     ORDINAMENTO  (es. selection sort o bubblesort). */
}


/* Funzione principale. */
int main(int argc, char *argv[])
{
  /* Supponiamo noti i nomi di piloti e scuderie (come potremmo
     procedere se cosi` non fosse?). */
  struct classificato piloti[N_PILOTI] = {
    {"Carlos_Sainz", 0},
    {"Daniel_Ricciardo", 0},
    {"Daniil_Kvyat", 0},
    {"Felipe_Massa", 0},
    {"Felipe_Nasr", 0},
    {"Fernando_Alonso", 0},
    {"Jenson_Button", 0},
    {"Kimi_Raikkonen", 0},
    {"Lewis_Hamilton", 0},
    {"Marcus_Ericsson", 0},
    {"Max_Verstappen", 0},
    {"Nico_Hulkenberg", 0},
    {"Nico_Rosberg", 0},
    {"Pastor_Maldonado", 0},
    {"Roberto_Merhi", 0},
    {"Romain_Grosjean", 0},
    {"Sebastian_Vettel", 0},
    {"Sergio_Perez", 0},
    {"Valtteri_Bottas", 0},
    {"Will_Stevens", 0}
  };
  struct classificato scuderie[N_SQUADRE] = {
    {"Ferrari", 0},
    {"Force_India", 0},
    {"Lotus", 0},
    {"Marussia", 0},
    {"McLaren", 0},
    {"Mercedes", 0},
    {"Red_Bull", 0},
    {"Sauber", 0},
    {"Toro_Rosso", 0},
    {"Williams", 0}
  };
  
  FILE *file;
  int i;
  int finito;  
  
  if (argc != 2) {
    printf("Utilizzo: ./formula1 FILE_RISULTATI\n");
    return 1;
  }

  /* Lettura dei dati */
  file = fopen(argv[1], "rt");
  finito = 0;
  while (finito == 0) {
    /* COMPLETA RICHIAMANDO LA FUNZIONE "leggi_gara", FINO A CHE IL
       FILE NON E` STATO LETTO DEL TUTTO. */
  }
  fclose(file);

  /* COMPLETA RICHIAMANDO LA FUNZIONE DI ORDINAMENTO. */
  
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
