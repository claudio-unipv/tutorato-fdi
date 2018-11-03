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
 *      gcc -Wall -o monete monete.c
 *    
 * 3) Esegui il programma digitando al terminale:
 * 
 *      ./monete
 *
 * 4) Verifica la correttezza del programma con il comando:
 *     
 *      ./pvcheck ./moenete
 *
 *    Se i test hanno rilevato errori cerca di capirne
 *    la causa, correggi il problema e riprova finche' il programma
 *    non passa tutti i test.
 * 
 ***********************************************************************/

#include <stdio.h>


/* Calcola a elevato alla b. */
int potenza(int a, int b)
{
  /* Completa la funzione. */
}


/* Calcola n! */
int fattoriale(int n)
{
  /* Completa la funzione. */
}


/* Calcola il coefficiente binomiale `n su k'. */
int coeff_binomiale(int n, int k)
{
  /* Completa la funzione. */
}


/* Calcola la probabilita di ottenere k volte testa lanciando n
   monete. */
double calcola_probabilita(int n, int k)
{
  /* Completa la funzione. */
}


/* Funzione principale */
int main()
{
  int monete;
  int teste;
  
  /* Lettura dei dati. */
  printf("Inserire il numero delle monete: ");
  scanf("%d", &monete);
  printf("Inserire il numero di teste: ");
  scanf("%d", &teste);

  printf("[COEFFICIENTE_BINOMIALE]\n");
  /* 1) Calcola e stampa il coefficiente binomiale */

  printf("[PROBABILITA]\n");
  /* 2) Calcola e stampa la probabilita` richiesta. */

  return 0;
}
