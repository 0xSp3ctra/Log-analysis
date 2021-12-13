#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "../lib/libgraphique.h"

void fonctiongraphique(){

		FILE * fic;
		short TAILLE_LIGNE = 30000;
		short NB_MOIS = 12;
		short nb_lignes_lues;
						
		char ligne[TAILLE_LIGNE];
		char *mois[] =  {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  	char str[1024];  			
		char pourcent_affiche[1024][NB_MOIS];
									
		int cpt_mois[NB_MOIS];
		int mois_courant[NB_MOIS];
		int i = 0;
		int HAUTEUR_FENETRE = 350;
		int MARGE_TEXTE = 50;
		int MARGE_BATON = 38;		 
  	int ajustement1 = HAUTEUR_FENETRE - MARGE_TEXTE;
  	int ajustement2 = HAUTEUR_FENETRE - MARGE_BATON;
  	int largeur_colonne = 30;
  	int ecart = 31;
  	int largeur_texte = 40;
  	int ecart2 = 30;
  	
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
		
		//calcul de la taille des bâtons du graph
		for (i = 0; i < NB_MOIS; i++)
		{
		    pourcent[i] = (float) mois_courant[i] / nb_lignes_lues * 1000;
		}  
		
		//calcul des pourcentages à afficher sur le graph
		for (i = 0; i < NB_MOIS; i++)
		{
		    aff_pourcent[i] = pourcent[i] / 10;
		}  
		
		//ouverture de la fenêtre graphique
		Point p = {30,50};
  	ouvrir_fenetre(430,HAUTEUR_FENETRE);
  	dessiner_rectangle((Point){0,0},430,HAUTEUR_FENETRE,blanc);
  
  	sprintf(str, "Depuis le 21/Feb/2018 on a enregistre %4hd connexions.", nb_lignes_lues);
  	afficher_texte(str,12,p,noir);  
  	
  	//compression d'une ligne en chaîne de caractère
		for (i = 0; i < NB_MOIS; i++)
		{
	  		sprintf(pourcent_affiche[i], "%0.0f", aff_pourcent[i]);
		} 
    
  	p.y=300;
  	afficher_texte(" Jan  Fev  Mar  Avr  Mai  Juin  Juil  Aou  Sep  Oct  Nov  Dec",14,p,purple);  
  
  	//dessin des bâtons
		for (i = 0; i < NB_MOIS; i++)
		{
				dessiner_rectangle((Point){largeur_colonne + i*ecart,ajustement1 - pourcent[i]},30,pourcent[i],rouge);	
		}  
	
		//affichage des pourcentages
		for (i = 0; i < NB_MOIS; i++)
		{
	  		afficher_texte(pourcent_affiche[i],14,(Point){largeur_texte + i*ecart2,ajustement2 - pourcent[i]},blanc);  
		}
	       
  	afficher_texte("(c) C. Ledru, 2021",12,(Point){30,325},noir); 
   	
		actualiser();
  	attendre_clic();

}
