#include "Reader.h"

/*
Ne modifiez pas ce fichier. En cas de souci, contactez Antoine Dailly et Yahia Salhi.
*/

Reader::Reader() : filename("") {}

Reader::Reader(const char* f) : filename(f) {}

Reader::~Reader() {}

Graphe* Reader::lireGraphe() {
	std::ifstream fichier(this->filename, std::ios::in);
	if (fichier) {
		std::string s;
		do { getline(fichier,s); } while (s[0]=='c');
		int i=0;
		do { ++i; } while (s[i]!=' ');
		do { ++i; } while (s[i]!=' '); // Haha beurk.
		++i;
		std::string nSomStr = "";
		while (s[i]!=' ') { nSomStr.push_back(s[i]); ++i; }; ++i;
		std::string nAreStr = "";
		while (s[i]!=' ') { nAreStr.push_back(s[i]); ++i; };
		int n = atoi( nSomStr.c_str() ); // Pouah.
		int e = atoi( nAreStr.c_str() ); // Gnrx.
		e=e/2;
		int a,b;
		Graphe* g = new Graphe();
		for (int i = 0; i < n; ++i) {
			Sommet* s = new Sommet();
			g->ajouteSommet(s);
		}
		for (int i = 0; i < e; ++i) {
			fichier >> s;
			fichier >> a;
			fichier >> b;
			(g->getSommet(a-1))->ajouteVoisin(g->getSommet(b-1)); // Merci les sommets numérotés de 1 à n plutôt que de 0 à n-1...
			(g->getSommet(b-1))->ajouteVoisin(g->getSommet(a-1));
		}
		fichier.close();
		std::cout << "Le graphe contenu dans le fichier " << this->filename << " a été correctement chargé." << std::endl;
		return g;
	}
	else {
		Graphe* g = new Graphe();
		std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
		return g;
	}
}
