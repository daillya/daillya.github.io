#include <iostream>
#include <map>

/*
Cette fonction affiche le contenu d'une map. Notez l'utilisation d'itérateurs afin de parcourir la map.
*/
void affiche (std::map<std::string,int>* m) {
	std::cout << "La map contient les couples (clef,valeur) suivants :" << std::endl;
	for (std::map<std::string,int>::iterator it = m->begin(); it != m->end(); ++it) {
		std::cout << "(" << it->first << "," << (*it).second << ")" << std::endl;
	}
	std::cout << std::endl;
}

int main (void) {

	std::map<std::string,int> m1;
	m1["The Legend of Zelda"] = 1986;
	m1["Link's Awakening"] = 1993;
	m1["Ocarina of Time"] = 1998;
	m1["The Wind Waker"] = 2002;
	m1["Breath of the Wild"] = 2017;
	affiche(&m1);
	return 0;
	
	std::map<std::string,int> m2(m1);
	affiche(&m2);
	
	m2.insert(std::pair<std::string,int>("Majora's Mask",2000));
	affiche(&m2);
	
	m2.erase("The Legend of Zelda");
	affiche(&m2);
	
	std::map<std::string,int>::iterator it = m2.find("Ocarina of Time");
	auto it = m2.find("Ocarina of Time");
	m2.erase(it);
	affiche(&m2);
	
	it = m2.find("Ocarina of Time");
	if (it != m2.end()) { m2.erase(it); }
	affiche(&m2);

	return 0;
}
