/***********************************************************************
 * 
 * TUTORATO 7: Array bidimensionali
 * ================================
 * 
 *
 * Tik-Tak-Toe-Tomek
 * -----------------------------------------
 *
 * 1) Completa il file inserendo il corpo della funzione
 *    "controlla_orizzontali".
 * 
 * 2) Compila il programma con il comando:
 * 
 *      gcc -Wall -o tictactoe tictactoe.c
 *    
 * 3) Esegui il programma digitando al terminale:
 * 
 *      ./tictactoe
 *
 * 4) Verifica la correttezza del programma con il comando:
 *     
 *      ./pvcheck ./tictactoe
 *
 * 5) Completa il resto del programma e riprova ad eseguire i test
 *    finche' non vengono superati tutti.
 * 
 ***********************************************************************/


#include <stdio.h>		/* printf, scanf */


/* Legge la griglia da terminale assumendo che sia stata inserita
   correttamente.  Una versione piu` completa includerebbe anch una
   verifica della correttezza dell'input. */
void leggi_griglia(char griglia[][4])
{
  /* ATTENZIONE: altre scritture equivalenti sono:
     int leggi_griglia(char (*griglia)[4])
     e 
     int leggi_griglia(char griglia[4][4])   */

  int i, j;
  char carattere;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      /* Il marcatore "%c" effettua la lettura di un 
         carattere. A differenza di quanto avviene 
         nella lettura di altri tipi di dato, i 
         caratteri di spaziatura non vengono saltati. 
         Per ignorarli occorre includere uno spazio 
         prima del marcatore. */
      scanf(" %c", &carattere);

      /* COMPLETA LA FUNZIONE ASSEGNANDO IL CARATTERE LETTO
	 ALL'ARRAY GRIGLIA. */
    }
  }
}


/* Verifica se le quattro celle della di una riga assegnano la
   vittoria ad un giocatore.  In caso positivo restituisce 'X' o 'O'.
   In caso negativo restituisce '.' */
char controlla_orizzontali(char griglia[][4])
{
  /* COMPLETA LA FUNZIONE. */
}


/* COMPLETA IL PROGRAMMA CON LE FUNZIONI 'controlla_verticali',
   'controlla_diagonali' e 'controlla_piena'. */


/* Determina il risultato della partita. */
char risultato_partita(char griglia[][4])
{
  char r;

  r = controlla_orizzontali(griglia);
  if (r != '.')
    return r;

  /* COMPLETA LA FUNZIONE IN MODO CHE TUTTI I CASI VENGANO GESTITI
     CORRETTAMENTE. */

  return '?';
}


int main()
{
  char griglia[4][4];
  char risultato;

  leggi_griglia(griglia);

  /* Determina in quale stato ci si trova. */
  risultato = risultato_partita(griglia);
  
  /* Stampa del risultato. */
  printf("[RISULTATO]\n");
  printf("%c\n", risultato);

  /* Fine (tutto ok). */
  return 0;
}
