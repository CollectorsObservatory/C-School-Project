/**
 * \file validationFormat.h
 * \brief Fichier contenant les implémentations des fonctions de validation de différents formats.
 * \author Fares Majdoub
 * \date 2023-11-28
 */
#ifndef VALIDATION_H_
#define VALIDATION_H_

#include <string>
#include <array>

namespace util{
    
static const int LONGUEUR_NUM_TELEPHONE = 12;
static const int NOMBRE_CODES_REGIONAUX = 40;
static const int LONGUEUR_NUM_RAMQ = 12;

bool validerFormatTelephone(const std::string& p_telephone);

bool validerFormatNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex);

bool validerFormatNom(const std:: string& p_nom);

void convertirMaj(std::string& p_chaine);



}/* namespace util */

#endif /* VALIDATION_H_ */