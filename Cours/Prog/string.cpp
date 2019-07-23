#include <iostream>
#include <string>

int main (void) {
	std::string s;
	
	s = "Hello";
	
	/*
	On peut accéder individuellement à chaque caractère d'une string. Notez que le type de s[0] et s.at(0) est char, pas std::string : contrairement à Python, C++ a un type spécifique pour les caractères.
	*/
	std::cout << s << std::endl;
	std::cout << s[0] << std::endl;
	std::cout << s.at(0) << std::endl;
	
	/*
	On peut savoir si une chaine est vide, ou bien avoir accès à sa longueur.
	*/
	if (s.empty()) {
		std::cout << "La chaine est vide." << std::endl;
	}
	else {
		std::cout << "La chaine est de longueur " << s.size() << "." << std::endl;
	}
	
	/*
	Contrairement à Python, les string sont mutables en C++. On peut ajouter des caractères au bout en utilisant la méthode push_back, mais l'opérateur += est également défini !
	*/
	s.push_back(' ');
	s+="W";
	std::cout << s << std::endl;
	
	/*
	On peut extraire une sous-chaine.
	*/
	std::cout << s.substr(3) << std::endl;
	std::cout << s.substr(1,4) << std::endl;
	
	/*
	On peut trouver une chaine spécifique dans la chaine.
	Si cette chaine est absente, la fonction renvoie un nombre spécial, appelé std::string::npos.
	Ainsi, pour tester si une chaine s2 est contenue dans une chaine s1, on peut effectuer : if(s1.find(s2) != std::string::npos)
	*/
	std::cout << s.find("llo") << std::endl;
	std::cout << s.find("lala") << " " << std::string::npos << std::endl;
	/*
	Existent aussi find_first_of, find_last_of
	*/
	
	/*
	Comme l'opérateur +=, l'opérateur + existe pour les string : il sert à concaténer deux chaines.
	*/
	std::string t = "orld !";
	std::cout << s+t << std::endl;
	
	/*
	Il existe de nombreuses autres méthodes, décrites sur cette page : http://www.cplusplus.com/reference/string/basic_string/
	*/

	return 0;
}
