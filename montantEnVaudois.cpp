//
// Created by maany on 29.10.2020.
//
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//fct qui check le chiffre rentré par l'utilisateur
void obtenirunbonNombre(long double &montant) {
    bool premier_saisie = true;
    do {
        cin.clear();
        if (!premier_saisie) {
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> montant; // finir par EOF (Ctrl-D) ou autre chose qu'un nombre
            cout << fixed << setprecision(2) << montant << endl; // arrondi different de celui de la fonction demandee
        }
        if (montant < 0) {
            cout << "erreur : montant negatif" << endl;
        } if (montant >= 1000000000000000) {
            cout << "erreur : montant trop grand" << endl;
        }
        premier_saisie = false;
    } while (!(montant >= 0 && montant <= 999999999999999.99));
}

//fct 1
/* nom: separateurParTriplets
 * but: Reçoit un nombre entre 0 et 999999999999999.99 et le décompose par triplets de 10 puissance 3.
 *      Renvoie chaque triplet dans des variables déclarées dans la fonction montantEnVaudois.
 * paramètres: long double montant, int& nb1, int& nb2, int& nb3, int& nb4, int& nb5, int& nb6
 */
void separateurParTriplets(long double montant, int &nb1, int &nb2, int &nb3, int &nb4, int &nb5, int &nb6) {
    long long montantEnLong = floor(montant);
    nb6 = (montant - floor(montant)) * 100; //modifier l'arrondi pour les centimes

    nb5 = montantEnLong % 1000;    //centaine
    nb4 = montantEnLong / 1000 % 1000;    //millier
    nb3 = montantEnLong / 1000000 % 1000;    //etc...
    nb2 = montantEnLong / 1000000000 % 1000;
    nb1 = montantEnLong / 1000000000000 % 1000;    //Il pourrait être intéressant de trouver une manière plus élégante de faire ça.

}

//fct 3
/* nom: convertisseurChiffreEnLettre
 * but: Prend chaque chiffre reçu et retourne sa version écrite en tenant compte de s'il sagit d'une
 *      unité, dizaine, etc.. grâce à un flag.
 * paramètre: int chiffre, flag
 */
string convertisseurChiffreEnLettres(int triplet, bool flagcentaine) {
    string resultat;
    int centaine, dizaine, unite;

    centaine = triplet / 100;
    dizaine = triplet / 10 % 10;
    unite = triplet % 10;

    switch (centaine) //Ecriture des centaines
    {
        case 1:
            resultat = "";
            break;
        case 2:
            resultat = "deux-";
            break;
        case 3:
            resultat = "trois-";
            break;
        case 4:
            resultat = "quatre-";
            break;
        case 5:
            resultat = "cinq-";
            break;
        case 6:
            resultat = "six-";
            break;
        case 7:
            resultat = "sept-";
            break;
        case 8:
            resultat = "huit-";
            break;
        case 9:
            resultat = "neuf-";
            break;
        case 0:
            resultat = "";
            break;
        default:
            resultat += "";
    }
    if(centaine && flagcentaine && !dizaine && !unite){
    	resultat += "cents";
    } else if(centaine){
    	resultat += "cent";
    }
    if((dizaine || unite) && centaine){
		 resultat += "-";
    }

    switch (dizaine) //Ecriture des dizaines
    {
        case 1:
           if (unite >= 1 && unite <= 6)
           {
              switch (unite)
              {
                 case 1:
                    resultat += "onze";
                    break;
                 case 2:
                    resultat += "douze";
                    break;
                 case 3:
                    resultat += "treize";
                    break;
                 case 4:
                    resultat += "quatorze";
                    break;
                 case 5:
                    resultat += "quinze";
                    break;
                 case 6:
                    resultat += "seize";
                    break;
                 default:
                    resultat += "";
              }
           } else{
              resultat += "dix";
           }
          break;
        case 2:
            resultat += "vingt";
            break;
        case 3:
            resultat += "trente";
            break;
        case 4:
            resultat += "quarante";
            break;
        case 5:
            resultat += "cinquante";
            break;
        case 6:
            resultat += "soixante";
            break;
        case 7:
            resultat += "septante";
            break;
        case 8:
            resultat += "huitante";
            break;
        case 9:
            resultat += "nonante";
            break;
        case 0:
            resultat += "";
            break;
        default:
            resultat += "";
    }

    if (dizaine != 1 || unite > 6) {
    	if((dizaine || centaine) && unite){
    		resultat += "-";
    	}
       switch (unite) //Ecriture des unitees
       {
          case 1:
             resultat += "un";
             break;
          case 2:
             resultat += "deux";
             break;
          case 3:
             resultat += "trois";
             break;
          case 4:
             resultat += "quatre";
             break;
          case 5:
             resultat += "cinq";
             break;
          case 6:
             resultat += "six";
             break;
          case 7:
             resultat += "sept";
             break;
          case 8:
             resultat += "huit";
             break;
          case 9:
             resultat += "neuf";
             break;
          case 0:
             resultat += "";
             break;
          default:
             resultat += "";
       }
    }
    return resultat;
}

string montantEnVaudois(long double montant) {
    string resultat;
    int nb1 = 0, nb2 = 0, nb3 = 0, nb4 = 0, nb5 = 0, nb6 = 0;
    bool flagcentaine = true;
    //Appel de la fct
    obtenirunbonNombre(montant);
    //Appel de La fct SeparateurParTriplet
    separateurParTriplets(montant, nb1, nb2, nb3, nb4, nb5, nb6);
    // etc...
    //rajouter une boucle qui permette de répéter la fonction pour chaque triplet
    //rajouter un if qui gère le cas ou un triplet vaut 0


    //transformer ca en fonction pour éviter la répetitions !!!
    const string unite = " francs"; // Pour changer en euros facilement  PS : laisser un espace avant l'unité merci ^^
    resultat += convertisseurChiffreEnLettres(nb1, flagcentaine);
    if (nb1 == 0) {
        resultat += "";
    } else {
        resultat += "-billions";
        if(nb2 || nb3 || nb4 || nb5){
        	resultat += "-";
        }
    }
    resultat += convertisseurChiffreEnLettres(nb2, flagcentaine);
    if (nb2 == 0) {
        resultat += "";
    } else {
        resultat += "-milliards";
		 if(nb3 || nb4 || nb5){
			 resultat += "-";
		 }
    }
    resultat += convertisseurChiffreEnLettres(nb3, flagcentaine);
    if (nb3 == 0) {
        resultat += "";
    } else {
        resultat += "-millions";
		 if(nb4 || nb5){
			 resultat += "-";
		 }
    }
    flagcentaine = false;
    resultat += convertisseurChiffreEnLettres(nb4, flagcentaine);
    if (nb4 == 0) {
        resultat += "";
    } else {
        resultat += "-mille";
		 if(nb5){
			 resultat += "-";
		 }
    }
	flagcentaine = true;
    resultat += convertisseurChiffreEnLettres(nb5, flagcentaine);
    resultat += unite;
    if (nb6 == 0) {
        resultat += "";
    } else {
        resultat += " et ";
    }
    resultat += convertisseurChiffreEnLettres(nb6, flagcentaine);
    if (nb6 == 0) {
        resultat += "";
    } else {
        resultat += " centimes";
    }

    return resultat;
}

