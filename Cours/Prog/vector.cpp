#include <iostream>
#include <vector>

/*
Cette fonction affiche le contenu d'un vector. Comme vous le constatez, on passe en paramètre non le vector, mais un pointeur sur le vector : ainsi on évite de recopier le contenu du vector dans la mémoire. Le gain peut être conséquent.
*/
void affiche (std::vector<int>* t) {
	if (t->size() == 0) {
		std::cout << "[ ]" << std::endl;
	}
	else {
		std::cout << "[ ";
		for (unsigned int i = 0; i < t->size()-1; ++i) {
			std::cout << t->at(i) << " , ";
		}
		std::cout << t->back() << " ]" << std::endl;
	}
}

int main (void) {

	std::vector<int> t1(3,0);
	affiche(&t1);
	
	std::vector<int> t2 {1,2,3,4,4};  // Pour utiliser cette façon d'initialiser, il faut activer le C++11. Sur CodeBlocks : Settings -> Compiler -> Cocher la case « -std=c++11 »
	affiche(&t2);
	
	/*
	L'accès à un élément d'un vector peut s'effectuer soit comme pour un tableau, soit par la fonction at.
	*/
	t2[1]=1;
	t2.at(1)=2;
	
	/*
	On peut créer un vector en copiant un vector préexistant.
	*/
	std::vector<int> t3(t2);
	affiche(&t3);
	
	/*
	Déclarer simplement un vector crée un tableau vide.
	*/
	std::vector<int> t4;
	if (t4.empty()) {
		std::cout << "Le tableau est vide !" << std::endl;
	}
	else {
		affiche(&t4);
	}
	
	/*
	On peut ajouter des éléments à la fin d'un vector, mais aussi en retirer.
	*/
	t4.push_back(2);
	if (t4.empty()) {
		std::cout << "Le tableau est vide !" << std::endl;
	}
	else {
		affiche(&t4);
	}
	t4.pop_back();
	if (t4.empty()) {
		std::cout << "Le tableau est vide !" << std::endl;
	}
	else {
		affiche(&t4);
	}
	
	/*
	L'opérateur d'égalité est implémenté pour les vector !
	*/
	if (t2 == t3) {
		std::cout << "Les deux tableaux sont égaux !" << std::endl;
	}
	else {
		std::cout << "Les deux tableaux sont différents !" << std::endl;
	}
	
	/*
	Il existe de nombreuses autres méthodes, décrites sur cette page : http://www.cplusplus.com/reference/vector/vector/
	*/

	return 0;
}
