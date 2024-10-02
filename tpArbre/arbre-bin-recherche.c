#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a;
	a = malloc(sizeof(Noeud));
	a->val = e;
	a->filsDroit = NULL;
	a->filsGauche = NULL;
	//initialiser(&(a->filsDroit));
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas inséré afin d'éviter les doublons
// version itérative

ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	if (estVide(a)){
		return creer(e);
	}
	
	ArbreBinaire noeudp = a;
	while ( (noeudp!=NULL && noeudp->val>e) || ( noeudp!=NULL && noeudp->val<e) ) {

		if (noeudp->val>e){
			noeudp = noeudp->filsGauche;
		}
		else{
			noeudp = noeudp->filsDroit;
		}
	}

	if (noeudp->val == e){
		return a;
	}
	if (noeudp->val>e){
		noeudp->filsGauche = creer(e);
	}
	else {
		noeudp->filsDroit = creer(e);
	}
	
	return a;
}	
/*
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire pere_p = NULL, p=a;
	if(p->val>=e){
		p = p->filsGauche;
	}
	else{
		p = p->filsGauche;
	}
}

*/


// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	
	return NULL;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){

		return 0;
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){

		return 0;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	

	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
	


	

}
void afficheElement(Element e){
	printf("%d",e);
}

void afficheGRD_r(ArbreBinaire a){
	if (!estVide(a)){
		printf("%s","(");
		afficheGDR_r(a->filsGauche);
		afficheElement(a->val);
		afficheGRD_r(a->filsDroit);
		printf("%s",")");
		
	}

}

void afficheGDR_r(ArbreBinaire a){
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

