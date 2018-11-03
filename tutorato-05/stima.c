/***********************************************************************
 * 
 * TUTORATO 5: Funzioni
 * ====================
 * 
 *
 * Primo esercizio: calcolo della probabilita` di k teste su n monete
 * ------------------------------------------------------------------
 *
 * 1) Completa il file inserendo il corpo delle funzioni.
 * 
 * 2) Compila il programma con il comando:
 * 
 *      gcc -Wall -o stima stima.c
 *    
 * 3) Esegui il programma digitando al terminale:
 * 
 *      ./stima
 *
 * 4) Verifica la correttezza del programma con il comando:
 *     
 *      ./pvcheck -f stima.test ./stima
 *
 *    Se i test hanno rilevato errori cerca di capirne
 *    la causa, correggi il problema e riprova finche' il programma
 *    non passa tutti i test.
 * 
 ***********************************************************************/

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* rand, srand */
#include <time.h>		/* time */


/* Restituisce a caso 1 (testa) o 0 (croce). */
int testa_o_croce()
{
  if (rand() % 2 == 0)	/* Pari testa, dispari croce */
    return 1;
  else
    return 0;
}


/* Simula il lancio di n monete e restituisce il numero di teste
   ottenute */
int lancio_simulato(int n)
{
  int teste = 0;

  /* Completa la funzione */

  return teste;
}


/* Stima la probabilita` che lanciando n monete escano k teste.  Per
   fare cio` vengono efettuate r simulazioni, in ciascuna delle quali
   vengono lanciate n monete.  Viene infine calcolata la frazione
   delle simulazioni in cui sono uscite k teste. */
double stima_probabilita(int n, int k, int r)
{
  /* Il contatore memorizza il numero di lanci in cui sono uscite k
     teste. */
  int contatore = 0;

  /* Completa la funzione. */
  
  /* Il cast e` necessario per evitare il troncamento nella
     divisione. */
  return ((double)c) / r;
}


/* Funzione principale */
int main()
{
  int monete;
  int teste;
  int ripetizioni = 100000;

  /* Per ottenere diverse sequenze pseudocasuali ad ogni esecuzione
     occorre impostare il `seme' in modo che dipenda dal momento in
     cui viene lanciato il programma. */
  srand(time(0));

  /* Lettura dei dati. */
  printf("Inserire il numero delle monete: ");
  scanf("%d", &monete);
  printf("Inserire il numero di teste: ");
  scanf("%d", &teste);

  printf("[STIMA]\n");
  /* Calcola e stampa la stima della probabilita`. */
  
  return 0;
}
