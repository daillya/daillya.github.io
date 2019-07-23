#include <iostream>

/*
Exercice 1
*/

struct horaire {
	int heure;
	int minute;
	int seconde;
};

horaire creer(void) {
	horaire h1;
	std::cout << "Entrez les heures, minutes et secondes :" << std::endl;
	std::cin >> h1.heure >> h1.minute >> h1.seconde;
	return h1;
}

horaire modifierSecondes (horaire h, int sec) {
	h.seconde = sec;
	return h;
}

int conversionSeconde (horaire h) {
	return 3600*h.heure+60*h.minute+h.seconde;
}

int difference (horaire h1, horaire h2) {
	int s1 = conversionSeconde(h1);
	int s2 = conversionSeconde(h2);
	if (s1>s2) {return s1-s2;}
	else {return s2-s1;}
}

void exo1 (void) {
	horaire h1=creer();
	horaire h2=creer();
	std::cout << "La différence entre les horaires est de " << difference(h1,h2) << " secondes." << std::endl;
}

/*
Exercice 2
*/

struct adressePostale {
	int numero;
	std::string nomDeRue;
	int codePostal;
	std::string commune;
};

adressePostale saisirAdresse (void) {
	adressePostale a;
	std::cout << "Ville :" << std::endl;
	std::cin >> a.commune;
	std::cout << "Code Postal :" << std::endl;
	std::cin >> a.codePostal;
	std::cout << "Nom de rue :" << std::endl;
	std::cin >> a.nomDeRue;
	std::cout << "Numéro :" << std::endl;
	std::cin >> a.numero;
	return a;
}

void afficherAdresse (adressePostale a) {
	std::cout << a.numero << ", rue " << a.nomDeRue << " " << a.codePostal << " " << a.commune << std::endl;
}

struct employe {
	std::string nom;
	std::string prenom;
	adressePostale adresse;
	bool sexe;
	std::string parametreGenre;
};

employe creerEmploye (void) {
	employe e;
	
	std::cout << "Quel est le nom de famille de l'employé.e ?" << std::endl;
	std::cin >> e.nom;
	std::cout << "Quel est le prénom de l'employé.e ?" << std::endl;
	std::cin >> e.prenom;
	
	e.adresse = saisirAdresse();

	int answer = 0;
	while (answer == 0) {
		std::cout << "Est-ce un homme (1) ou une femme (2) ?" << std::endl;
		std::cin >> answer;
		switch (answer) {
			case 1:
				e.sexe = false;
				std::cout << "Quelle est sa situation militaire ?" << std::endl;
				std::cin >> e.parametreGenre;
				break;
			case 2:
				e.sexe = true;
				std::cout << "Quelle est son nom de jeune fille ?" << std::endl;
				std::cin >> e.parametreGenre;
				break;
			default:
				answer=0;
				break;
		}
	}
	
	return e;
}

void afficherEmploye (employe e) {
	if (e.sexe) {
		std::cout << "L'employée " << e.prenom << " " << e.nom << ", de nom de jeune fille " << e.parametreGenre << ", habite :";
	}
	else {
		std::cout << "L'employé " << e.prenom << " " << e.nom << ", ayant pour situation militaire " << e.parametreGenre << ", habite : ";
	}
	afficherAdresse(e.adresse);
}

void exo2(void) {
	employe entreprise[50];
	int nbEmployes;
	std::cout << "Combien l'entreprise compte-t-elle d'employés ? (maximum 50)" << std::endl;
	std::cin >> nbEmployes;
	for (unsigned int i = 0; i < nbEmployes; ++i) {
		entreprise[i] = creerEmploye();
	}
	
	std::string nom;
	std::cout << "Entrez le nom de l'employé dont vous voulez consulter les données :" << std::endl;
	std::cin >> nom;
	unsigned int i = 0;
	while (i<nbEmployes && entreprise[i].nom != nom) {
		++i;
	}
	if (i >= nbEmployes) { std::cout << "L'employé recherché n'existe pas..." << std::endl; }
	else { afficherEmploye(entreprise[i]); }
}

/*
Exercice 3
*/

struct pile {
	int tab[50];
	int sommet;
};

pile initPile (void) {
	pile p;
	p.sommet = -1;
	return p;
}

bool pileVide (pile p) {
	return (p.sommet == -1);
}

bool pilePleine (pile p) {
	return (p.sommet == 49);
}

pile empiler (pile p, int n) {
	if (pilePleine(p)) {
		std::cout << "Erreur : la pile est pleine." << std::endl;
	}
	else {
		++(p.sommet);
		p.tab[p.sommet]=n;
	}
	return p;
}

pile depiler (pile p) {
	if (pileVide(p)) {
		std::cout << "Erreur : la pile est vide." << std::endl;
	}
	else {
		--(p.sommet);
	}
	return p;
}

int consulterSommet (pile p) {
	int res = -1;
	if (pileVide(p)) {
		std::cout << "Erreur : la pile est vide." << std::endl;
	}
	else {
		res = p.tab[p.sommet];
	}
	return res;
}

int taille (pile p) {
	return p.sommet + 1;
}

void exo3(void) {
	int loop = 0;
	pile p = initPile();
	do {
		std::cout << "Quelles actions voulez-vous effectuer ? 0- Quitter. 1- Ajouter un élément à la pile. 2- Retirer un élément de la pile. 3- Regarder l'élément au sommet de la pile. 4- Connaître la taille de la pile." << std::endl;
		std::cin >> loop;
		switch (loop) {
			case 0:
				break;
			case 1:
				std::cout << "Entrez l'élément que vous souhaitez empiler." << std::endl;
				int k;
				std::cin >> k;
				p = empiler(p,k);
				break;
			case 2:
				p = depiler(p);
				break;
			case 3:
				std::cout << "L'élément au sommet de la pile est : " << consulterSommet(p) << std::endl;
				break;
			case 4:
				std::cout << "La pile contient " << taille(p) << " éléments." << std::endl;
				break;
			default:
				loop = 0;
				break;
		}
	}
	while (loop > 0);
}

/*
Le main
*/

int main(void) {
	exo1();
	exo2();
	exo3();
	return 0;
}
