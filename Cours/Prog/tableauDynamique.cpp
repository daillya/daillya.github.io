/*
Rédigé par Antoine Dailly.
Cours : Pointeurs, allocation dynamique, structures.
Objectif : Réaliser un tableau dynamique.
La correction de l'exercice se trouve sous le gros bloc de commentaires !
Résumé du cours :
- Les pointeurs sont des types de données spéciaux, lesquels servent à contenir l'adresse mémoire d'un élément d'un certain type.
- Syntaxe : typePointé * ptr; déclare un pointeur contenant l'adresse mémoire d'un élément de type typePointé.
- Syntaxe de l'adresse mémoire : typePointé a; typePointé * ptr = &a;
- Le déréférencement est une opération permettant d'accéder au contenu de l'élément dont l'adresse est stockée dans un pointeur.
- Syntaxe du déréférencement : typePointé a; typePointé * ptr = &a; *ptr = valeur;
- Les pointeurs servent à manipuler directement les variables, notamment à travers d'appels de fonctions. Ils servent également à économiser de l'espace en mémoire (en évitant la copie de variables complexes).
- Les tableaux sont en fait des pointeurs ! tab[i] est en fait *(tab+i*TAILLE_MEM) où TAILLE_MEM est la taille mémoire des données stockées dans tab. C'est la raison pour laquelle les indices commencent à 0 !
- On peut allouer explicitement la mémoire, via la fonction malloc. Historiquement, cela servait à définir des tableaux de taille non-constante.
- Syntaxe de malloc : type * tab = (type*)malloc(taille*sizeof(type));
- La fonction sizeof renvoie le nombre d'octets utilisés par le type en mémoire. Elle s'utilise sur n'importe quel type (types usuels comme int, double, char..., types structurés que vous créez, types plus complexes comme std::string).
- Une fois le tableau alloué en mémoire via malloc, on l'utilise comme n'importe quel tableau : tab[i] fonctionne donc encore. L'intérêt est de simplifier la syntaxe des appels de fonctions.
- ATTENTION. Quand vous allouez explicitement de la mémoire via malloc, vous devez la désallouer explicitement via la fonction free. On désalloue la mémoire allouée une fois qu'on n'en a plus besoin.
- Syntaxe de free : free(tab);
- Les structures offrent la possibilité de créer des types composés.
- Syntaxe : struct typeComposé { type1 champ1; ... typek champk; };
- Par la suite, on utilise typeComposé comme n'importe quel type. On peut donc utiliser la fonction sizeof dessus, et créer des pointeurs dessus.
- Pour accéder à un champ particulier, on utilise la syntaxe suivante : typeComposé var; var.champ1 = valeur;
- Si on utilise un pointeur sur le type composé, on utilise en revanche la syntaxe suivante : typeComposé * var; var->champ1 = valeur;
- La syntaxe ci-dessus est exactement équivalente à (*var).champ1 = valeur;
Plus d'informations et d'exemples sur https://perso.liris.cnrs.fr/antoine.dailly/cpp.html
*/

#include <iostream>

struct tableau {
	double * contenu;
	unsigned int taille;
	unsigned int espaceMemoire;
};

tableau creer (void) {
	tableau tab;
	tab.contenu = (double*)malloc(sizeof(double));
	tab.taille = 0;
	tab.espaceMemoire = 1;
	std::cout << "             Tableau créé." << std::endl;
	return tab;
}

void detruire (tableau * tab) {
	free(tab->contenu);
	std::cout << "             Tableau détruit." << std::endl;
}

bool estVide (tableau * tab) {
	return tab->taille == 0;
}

bool estPlein (tableau * tab) {
	return tab->taille == tab->espaceMemoire;
}

bool estCreux (tableau * tab) {
	return tab->taille < tab->espaceMemoire/2;
}

double element (tableau * tab, unsigned int i) {
	if (i >= tab->taille) {
		std::cout << "Erreur, vous essayez d'accéder à un élément hors du tableau." << std::endl;
		return -1;
	}
	else
		return tab->contenu[i];
}

void afficher (tableau * tab) {
	if (estVide(tab))
		std::cout << "Le tableau est vide !" << std::endl;
	else {
		std::cout << "Le tableau occupe " << tab->espaceMemoire << " cases en mémoire, et contient " << tab->taille << " éléments." << std::endl;
		for (unsigned int i = 0; i < tab->taille; ++i) {
			std::cout << element(tab,i) << " ";
		}
		std::cout << std::endl;
	}
}

void append (tableau * tab, double x) {
	if (estPlein(tab)) {
		unsigned int n = tab->espaceMemoire;
		double * temp = (double*)malloc(n*sizeof(double));
		for (unsigned int i = 0; i < tab->taille; ++i) {
			temp[i] = element(tab,i);
		}
		free(tab->contenu);
		tab->contenu = (double*)malloc(2*n*sizeof(double));
		tab->espaceMemoire = 2*n;
		for (unsigned int i = 0; i < tab->taille; ++i) {
			tab->contenu[i] = temp[i];
		}
		free(temp);
	}
	tab->contenu[tab->taille]=x;
	tab->taille = tab->taille+1;
}

double pop (tableau * tab) {
	if (estVide(tab)) {
		std::cout << "Le tableau est vide. Impossible de pop." << std::endl;
		return -1;
	}
	if (estCreux(tab)) {
		unsigned int n = tab->espaceMemoire;
		double * temp = (double*)malloc(n*sizeof(double));
		for (unsigned int i = 0; i < tab->taille; ++i) {
			temp[i] = element(tab,i);
		}
		free(tab->contenu);
		n = n/2;
		tab->contenu = (double*)malloc(n*sizeof(double));
		tab->espaceMemoire = n;
		for (unsigned int i = 0; i < tab->taille; ++i) {
			tab->contenu[i] = temp[i];
		}
		free(temp);
	}
	double x = element(tab,tab->taille-1);
	tab->taille = tab->taille - 1;
	return x;
}

int main (void) {
	tableau tab = creer();
	afficher(&tab);
	for (unsigned int i = 0; i < 10; ++i) {
		append(&tab,i);
	}
	std::cout << "Ajout terminé !" << std::endl;
	afficher(&tab);
	for (unsigned int i = 0; i < 5; ++i) {
		std::cout << pop(&tab) << " est enlevé." << std::endl;
	}
	afficher(&tab);
	for (unsigned int i = 0; i < 5; ++i) {
		std::cout << pop(&tab) << " est enlevé." << std::endl;
	}
	afficher(&tab);
	pop(&tab);
	detruire(&tab);
	return 0;
}
