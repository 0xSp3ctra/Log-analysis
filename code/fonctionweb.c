#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fonctionweb(){

		void lecture_style()
		{

  	FILE *fd;
  	char str[1024];
  
  	if ((fd = fopen("/usr/lib/cgi-bin/aecrire.html","r")) == NULL)
    fprintf(stderr,"ERREUR DE CHARGEMENT DE FICHIER\n");
    
  	else {
    		while (!feof(fd))
    		{
      		fgets(str,1024,fd);
      		printf("%s",str);
				}
   		fclose(fd);
  		}
		}
			
		FILE * fic;
		short TAILLE_LIGNE = 30000;
		int NB_MOIS = 12;		
		short nb_lignes_lues;  						// %4hd pour afficher		
		
		char ligne[TAILLE_LIGNE];
		char *mois[] =  {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
		
		int cpt_mois[NB_MOIS];
		int mois_courant[NB_MOIS];        // %10s

		int i = 0;		
		
		float pourcent[NB_MOIS];
		float aff_pourcent[NB_MOIS];
		nb_lignes_lues = 0;		
		
		
		//initialisation à 0 du tableau mois_courant		  	  	  	  	  			
		for (i = 0 ; i < NB_MOIS ; i++)
    {
        mois_courant[i] = 0;
    }
    
    
    //ouverture du fichier log        
		fic = fopen("/var/log/apache2/access.log", "r");
			
		if (fic == NULL)
		{
			printf("Erreur d'ouverture du ficher log ");
			exit(0);
		}
		
		//analyse les lignes logs avec fgets + sscanf																		
		while (fgets(ligne, TAILLE_LIGNE, fic) !=NULL)
		{			
			nb_lignes_lues++;
			sscanf(ligne, "%*[^/]/%[A-Za-z]%*[^\n]", cpt_mois);
					
			for (i = 0; i < NB_MOIS; i++)
			{
				if (strcmp(cpt_mois,mois[i]) == 0)
				{
					mois_courant[i]++;
				}
			}																					
		}
		fclose( fic);		
		
		//calculs des pourcentages à afficher et pour la taille des bâtons
		for (i = 0; i <= 11; i++)
		{
		    pourcent[i] = (float) mois_courant[i] / nb_lignes_lues * 100;
		    aff_pourcent[i] = pourcent[i] * 10;
		}  
    
    //affichage du graphique + texte en language HTML que le serveur va exécuter
  	printf("Content-type: text/html\n\n"); 

  	printf("<!doctype html>\n");
  	printf("<html lang=\"fr\">\n"); 
  	printf("<body>\n");
		
		
		//appel de la fonction pour le CSS
  	lecture_style();

  	printf("Depuis le 21/Feb/2018 on a enregistr&eacute; %4hd connexions.\n", nb_lignes_lues);
		printf("</br>");
		printf("</br>");
		printf("</br>");
		printf("</br>");				 
         
    printf("<div id = \"vertgraph\">\n");
  	printf("    <ul>\n");

  	printf("        <li style=\"left: 10px;  height: %.1fpx;\">%.1f</li>\n",aff_pourcent[0],pourcent[0]);
  	printf("        <li style=\"left: 41px;  height: %.1fpx;\">%.1f</li>\n",aff_pourcent[1],pourcent[1]);
  	printf("        <li style=\"left: 72px;  height: %.1fpx;\">%.1f</li>\n",aff_pourcent[2],pourcent[2]);
  	printf("        <li style=\"left: 103px;  height: %.1fpx;\">%.1f</li>\n",aff_pourcent[3],pourcent[3]);
  	printf("        <li style=\"left: 134px;  height: %.1fpx;\">%.1f</li>\n",aff_pourcent[4],pourcent[4]);
  	printf("        <li style=\"left: 165px;  height: %.1fpx;\">%.1f</li>\n",aff_pourcent[5],pourcent[5]);
  	printf("        <li style=\"left: 196px;  height: %.1fpx;\">%.1f</li>\n",aff_pourcent[6],pourcent[6]);
  	printf("        <li style=\"left: 227px;  height: %.1fpx;\">%.1f</li> \n",aff_pourcent[7],pourcent[7]);
  	printf("        <li style=\"left: 258px;  height: %.1fpx;\">%.1f</li> \n",aff_pourcent[8],pourcent[8]);
  	printf("        <li style=\"left: 289px;  height: %.1fpx;\">%.1f</li> \n",aff_pourcent[9],pourcent[9]);
  	printf("        <li style=\"left: 320px;  height: %.1fpx;\">%.1f</li>\n",aff_pourcent[10],pourcent[10]);
  	printf("        <li style=\"left: 351px;  height: %.1fpx;\">%.1f</li> \n",aff_pourcent[11],pourcent[11]);
		printf("</div>\n");
		  	

		printf("</br>");
		printf("</br>");    
    printf("(c) C. Ledru, 2021\n");

  
  	printf("</html>\n");
  	printf("</body>\n\n"); 


}
