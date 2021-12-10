#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fonctiontexte.h"
#include "../lib/libgraphique.h"

void fonctiongraphique(){

		FILE * fic;
		short TAILLE_LIGNE = 30000;
		char ligne[TAILLE_LIGNE];
		int cpt_mois[12];
		char *mois[] =  {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};		
		short nb_lignes_lues;
		nb_lignes_lues = 0;
		int mois_courant[12];
		int i = 0;
		int HAUTEUR_FENETRE = 350;
		int MARGE_TEXTE = 50;
		int MARGE_BATON = 38;		 
  	int ajustement1 = HAUTEUR_FENETRE - MARGE_TEXTE;
  	int ajustement2 = HAUTEUR_FENETRE - MARGE_BATON;
  	char str[1024];  	
		char pourcent_affiche[1024][12];
  	float pourcent[12];
  	float aff_pourcent[12];
  	int largeur_colonne = 30;
  	int ecart = 31;
  	int largeur_texte = 40;
  	int ecart2 = 30;  	  	  	  	  	  	
  	  	  	  	  	
		for (i = 0 ; i <= 11 ; i++)
    {
        mois_courant[i] = 0;
    }
    
		fic = fopen("/var/log/apache2/access.log", "r");
			
		if (fic == NULL)
		{
			printf("Erreur d'ouverture du ficher log ");
			exit(0);
		}
		
									
		/* lecture du fichier par fgets et sscanf */
		while (fgets(ligne, TAILLE_LIGNE, fic) !=NULL)
		{			
						nb_lignes_lues++;
						sscanf(ligne, "%*[^/]/%[A-Za-z]%*[^\n]", cpt_mois);
		
						for (i = 0; i <= 11; i++)
						{
								if (strcmp(cpt_mois,mois[i]) == 0)
								{
									mois_courant[i]++;
								}																						
						}
		}
		for (i = 0; i <= 11; i++)
		{
		    pourcent[i] = (float) mois_courant[i] / nb_lignes_lues * 1000;
		}  
		
		for (i = 0; i <= 11; i++)
		{
		    aff_pourcent[i] = pourcent[i] / 10;
		}  


				
		Point p = {30,50};
  	ouvrir_fenetre(430,HAUTEUR_FENETRE);
  	dessiner_rectangle((Point){0,0},430,HAUTEUR_FENETRE,blanc);
  
  	sprintf(str, "Depuis le 21/Feb/2018 on a enregistre %4hd connexions.", nb_lignes_lues);
  	afficher_texte(str,12,p,noir);  
  
		for (i = 0; i <= 11; i++)
		{
	  		sprintf(pourcent_affiche[i], "%0.0f", aff_pourcent[i]);
		} 
    
  	p.y=300;
  	afficher_texte(" Jan  Fev  Mar  Avr  Mai  Juin  Juil  Aou  Sep  Oct  Nov  Dec",14,p,purple);  
  
		for (i = 0; i <= 11; i++)
		{
				dessiner_rectangle((Point){largeur_colonne + i*ecart,ajustement1 - pourcent[i]},30,pourcent[i],rouge);	
		}  
	
		for (i = 0; i <= 11; i++)
		{
	  		afficher_texte(pourcent_affiche[i],14,(Point){largeur_texte + i*ecart2,ajustement2 - pourcent[i]},blanc);  
		}
	       
  	afficher_texte("(c) C. Ledru, 2021",12,(Point){30,325},noir); 
   	
		actualiser();
  	attendre_clic();

}
