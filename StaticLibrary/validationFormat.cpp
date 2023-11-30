/**
 * \file validationFormat.cpp
 * \brief Fichier contenant les implémentations des fonctions de validation de différents formats.
 * \author Fares Majdoub
 * \date 2023-11-28
 */

#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include "validationFormat.h"
using namespace std;

namespace util{
  

/**
 * \brief Valide le format d'un numéro de téléphone.
 * \param[in] p_telephone Le numéro de téléphone à valider.
 * \return bool Vrai si le format est correct Faux si le format est incorrect
 */
  
bool validerFormatTelephone(const string& p_telephone) {
    
    if (p_telephone.length() != LONGUEUR_NUM_TELEPHONE) {
        return false;
    }


    if (p_telephone[3] != '-' || p_telephone[7] != '-') {
        return false;
    }

    for (int i = 0; i < LONGUEUR_NUM_TELEPHONE; ++i) {
        if (i != 3 and i != 7 and !isdigit(p_telephone[i])) {
            return false;
        }
    }


   string codeRegional = p_telephone.substr(0, 3);


    if (codeRegional[0] == '9') {
        return true;
    }



    array<string, NOMBRE_CODES_REGIONAUX> codesRegionaux = {
        "403", "780", "604", "236", "250", "778", "902", "204", "431", "506",
        "905", "519", "289", "705", "613", "807", "416", "647", "438", "514",
        "450", "579", "418", "581", "819", "873", "306", "709", "867", "800",
          "866" , "877" , "888", "855", "900", "976" ,"966" };

   bool codeValide = false;
    for (const string& code : codesRegionaux) {
        if (codeRegional == code) {
            codeValide = true;
            break;
        }
    }

    return codeValide;
}

/**
 * \brief Convertit tous les caractères d'une chaîne en majuscules.
 * \param[in,out] p_chaine La chaîne de caractères à convertir en majuscules.
 */

void convertirMaj(string& p_chaine)
{
	for (unsigned i = 0; i < p_chaine.size(); ++i)
	{
		p_chaine[i] = toupper(p_chaine[i]);
	}
}

/**
 * \brief Valide le format d'un numéro de RAMQ.
 * \param[in] p_numero Le numéro de RAMQ à valider.
 * \param[in] p_nom Le nom de famille associé au numéro de RAMQ.
 * \param[in] p_prenom Le prénom associé au numéro de RAMQ.
 * \param[in] p_jourNaissance Le jour de naissance.
 * \param[in] p_moisNaissance Le mois de naissance.
 * \param[in] p_anneeNaissance L'année de naissance.
 * \param[in] p_sex Le sexe de la personne 
 * \return bool Vrai si le format est correct Faux si le format est incorrect
 */

bool validerFormatNumRAMQ(const string& p_numero, const string& p_nom, const string& p_prenom, int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex) {


    string numero;
    for(char c : p_numero) {
        if(!isspace(c)) numero += c;
    }


    if (!(p_sex == 'M' || p_sex == 'm' || p_sex == 'F' || p_sex == 'f')) {
 
        return false;
    }

    if (numero.length() != 12) {
        return false;
    }
  
    string expectedStart = "";
    expectedStart += toupper(p_nom[0]);  
    expectedStart += toupper(p_nom[1]);
    expectedStart += toupper(p_nom[2]);
    expectedStart += toupper(p_prenom[0]);
  
    if (numero.substr(0, 4) != expectedStart) {  
        return false;
    }
    

    if (p_sex == 'F' || p_sex == 'f') {
        p_moisNaissance += 50;
    }

    char buffer[7];
    
    sprintf(buffer, "%02d%02d%02d", p_anneeNaissance % 100, p_moisNaissance, p_jourNaissance);
    string dateNaissance(buffer);
    if (numero.substr(4, 6) != dateNaissance) {
        return false;
    }
   
     for (int i = 10; i < 12; ++i) {
        if (!isdigit(numero[i])) {
            return false;
        }
    }

    return true;}

/**
 * \brief Valide le format d'un nom.
 * \param[in] p_nom Le nom à valider.
 * \return bool Vrai si le format est correct ou Faux si le format est incorrect
 */

bool validerFormatNom(const string& p_nom) {
    if (p_nom.empty()) {
        return false;
    }

    for (char c : p_nom) {
        if (!isalpha(c) && c != ' ') {  // Accepter les lettres et les espaces
            return false;
        }
    }

    return true;
}


}/* namespace util */


