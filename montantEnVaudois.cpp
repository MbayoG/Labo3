//
// Created by maany on 29.10.2020.
//
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//fct 1
/* nom: separateurParTriplets
 * but: Reçoit un nombre entre 0 et 999999999999999.99 et le décompose par triplets de 10 puissance 3.
 *      Renvoie chaque triplet dans des variables déclarées dans la fonction montantEnVaudois.
 * paramètres: long double montant, int& nb1, int& nb2, int& nb3, int& nb4, int& nb5, int& nb6
 */
void separateurParTriplets(long double montant, int& nb1, int& nb2, int& nb3, int& nb4, int& nb5, int& nb6){
	long long montantEnLong = floor(montant);
	nb6 = (montant - floor(montant))*100; //modifier l'arrondi pour les centimes

	nb5 = montantEnLong % 1000;	//centaine
	nb4 = montantEnLong/1000 %1000;	//millier
	nb3 = montantEnLong/1000000 %1000;	//etc...
	nb2 = montantEnLong/1000000000 %1000;
	nb1 = montantEnLong/1000000000000 %1000;	//Il pourrait être intéressant de trouver une manière plus élégante de faire ça.

}

//fct 3
/* nom: convertisseurChiffreEnLettre
 * but: Prend chaque chiffre reçu et retourne sa version écrite en tenant compte de s'il sagit d'une
 *      unité, dizaine, etc.. grâce à un flag.
 * paramètre: int chiffre, flag
 */
string convertisseurChiffreEnLettres(int chiffre){
	string resultat = "";

	return resultat;
}

//fct 2
/* nom: separateurEnChiffre
 * but: Reçoit un triplet de chiffres et le sépart en chiffre seule.
 * paramètre: int triplet
 */
string separateurEnChiffres(int triplet){
	string resultat = "";

	for(int i = 1; i <= 100; i *= 10){
		resultat += convertisseurChiffreEnLettres(triplet/i%10);
	}
}

string montantEnVaudois(long double montant){
    string resultat = " test ";
    int nb1, nb2, nb3, nb4, nb5, nb6;

    //Appel de La fct SeparateurParTriplet
    separateurParTriplets(montant, nb1,nb2,nb3,nb4,nb5,nb6);
    // etc...


    return resultat;
}

