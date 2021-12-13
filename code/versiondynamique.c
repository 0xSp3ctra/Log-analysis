#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctiontexte.h"
#include "fonctiongraphique.h"
#include "fonctionweb.h"

int main(int argc, char* argv[])
{
    if (argc > 1) {
      if (strcmp(argv[1],"-txt")==0) {
        fonctiontexte();							// appel de la fonction texte
      }
      if (strcmp(argv[1],"-gr")==0) {
        fonctiongraphique();					// appel de la fonction graphique
      }
                 
    }else fonctionweb(); 							//appel de la fonction web

    return EXIT_SUCCESS;
}
