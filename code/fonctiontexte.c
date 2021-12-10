#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fonctiontexte(){

		FILE * fic;
		short TAILLE_LIGNE = 30000;
		short NB_MOIS = 12;
		char ligne[TAILLE_LIGNE];
		int cpt_mois[NB_MOIS];
		char *mois[] =  {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
		short nb_lignes_lues;  // %4hd pour afficher
		nb_lignes_lues = 0;
		int mois_courant[NB_MOIS];         // %10s
		int i = 0;
		float pourcent[NB_MOIS];
		
		
		for (i = 0 ; i < NB_MOIS ; i++)
    {
        mois_courant[i] = 0;
    }
    
		fic = fopen("/var/log/apache2/access.log", "r");
			
		if (fic == NULL)
		{
			printf("Erreur d'ouverture du ficher log ");
			exit(0);
		}
		
										
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
		
		printf("Depuis le 21/Feb/2018 on a enregistré %4hd connexions.\n", nb_lignes_lues);
		
		for (i = 0; i <= 11; i++)
		{
		    pourcent[i] = (float) mois_courant[i] / nb_lignes_lues * 100;
		}     
    
    printf("  Janvier : %.1f%% \n", pourcent[0]);
    printf("  Février : %.1f%% \n", pourcent[1]);
    printf("     Mars : %.1f%% \n", pourcent[2]);
    printf("    Avril : %.1f%% \n", pourcent[3]);
    printf("      Mai : %.1f%% \n", pourcent[4]);
    printf("     Juin : %.1f%% \n", pourcent[5]);
    printf("  Juillet : %.1f%% \n", pourcent[6]);
    printf("     Août : %.1f%% \n", pourcent[7]);
    printf("Septembre : %.1f%% \n", pourcent[8]);
    printf("  Octobre : %.1f%% \n", pourcent[9]);
    printf(" Novembre : %.1f%% \n", pourcent[10]);
    printf(" Décembre : %.1f%% \n", pourcent[11]);
    printf("\n");
    printf("(c) C. Ledru, 2021\n");
    
}
