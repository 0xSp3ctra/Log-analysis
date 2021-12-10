#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctiontexte.h"
#include "fonctiongraphique.h"

void lecture_style()
{
  /* On aurait pu utiliser un fichier css mais il est     */
  /* parfois plus pratique de définir le style dans le    */
  /* code HTML généré par ce CGI-BIN.                     */
  /* On le lit ce style depuis fichier "aecrire.html"     */
  /* puis on l'affiche.                                   */
  /* L'étudiant attentif pourra s'apercevoir aisément que */
  /* cette fonction n'est pas inutile pour ses propres    */
  /* besoins...                                           */

  FILE *fd;
  char str[1024];
  if ((fd = fopen("aecrire.html","r")) == NULL)
    fprintf(stderr,"ERREUR DE CHARGEMENT DE FICHIER\n");
  else {
    while (!feof(fd)){
      fgets(str,1024,fd);
      printf("%s",str);

    }
    fclose(fd);
  }
}

int main(int argc, char* argv[])
{
    if (argc > 1) {
      if (strcmp(argv[1],"-txt")==0) {
        fonctiontexte();
      }
      if (strcmp(argv[1],"-gr")==0) {
        fonctiongraphique();
      }           
    } 

    return EXIT_SUCCESS;
}
