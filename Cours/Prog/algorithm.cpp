#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int>::iterator iter;

/*
Fonction d'affichage utilisant des itérateurs.
*/
void affiche (std::vector<int>* t) {
	std::cout << "[ ";
	for (iter it = t->begin(); it != t->end(); ++it) {
		if (it+1 != t->end()) {
			std::cout << *it << " , ";
		}
		else {
			std::cout << *it;
		}
	}
	std::cout << " ]" << std::endl;
}

int main (void) {

	std::vector<int> t {5,3,1,9,0,19,1,18192,-1,81,-621,1};
	affiche(&t);
	
	std::sort(t.begin(),t.end());
	affiche(&t);
	
	std::reverse(t.begin(),t.end());
	affiche(&t);
	
	std::random_shuffle(t.begin(),t.end());
	affiche(&t);
	
	std::cout << "La valeur 1 apparaît " << std::count(t.begin(),t.end(),1) << " fois dans le tableau." << std::endl;
	
	std::cout << "Le min du tableau est : " << *std::min_element(t.begin(),t.end()) << std::endl;
	std::cout << "Le max du tableau est : " << *std::max_element(t.begin(),t.end()) << std::endl;
	
	std::vector<int> tab1 {121,1243,982,189128};
	std::vector<int> tab2 {78278,-126281,8918,-19};
	std::sort(tab1.begin(),tab1.end());
	std::sort(tab2.begin(),tab2.end());
	std::vector<int> tab3 (tab1.size()+tab2.size());
	std::merge(tab1.begin(),tab1.end(),tab2.begin(),tab2.end(),tab3.begin());
	affiche(&tab3);
	
	/*
	Notez qu'on peut appeler ces fonctions sur des sous-parties de nos structures : t.begin()+5 pointe sur le cinquième élément de notre structure par exemple.
	Ainsi, si l'on souhaite trier la moitié de notre tableau, on peut effectuer : std::sort(t.begin(),t.begin()+(int)(t.size()/2));
	*/

	return 0;
}
