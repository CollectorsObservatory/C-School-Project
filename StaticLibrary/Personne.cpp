/**
  * \file Personne.cpp
  * \brief Implémentation de la classe abstraite Personne.
  * \author Fares Majdoub
  * \date 2023-11-28
  */
#include <iostream>
#include<sstream>
#include "Personne.h"
#include "validationFormat.h"
#include "Date.h"




using namespace std;
using namespace util;

namespace hockey {
  
  

  /**
    * \brief Constructeur Personne avec paramètres.
    *        Crée un objet Personne à partir de valeurs spécifiées.
    * \param[in] p_nom le nom de la personne.
    * \param[in] p_prenom le prénom de la personne.
    * \param[in] p_dateNaissance la date de naissance de la personne.
    * \param[in] p_telephone le numéro de téléphone de la personne.
    * 
    * \pre p_nom, p_prenom doivent être dans le bon format.
    * \pre p_dateNaissance doit représenter une date valide.
    * \pre p_telephone doit être dans le bon format.
    * 
    * \post Le nom, prénom, date de naissance, et téléphone de l'objet créé 
    *       doivent correspondre aux paramètres fournis.
    */
  
  Personne::Personne(const string& p_nom, const string& p_prenom, 
                     const Date& p_dateNaissance, const string& p_telephone)
    : m_nom(p_nom), m_prenom(p_prenom), 
      m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
  {
      PRECONDITION(validerFormatNom(p_nom));
      PRECONDITION(validerFormatNom(p_prenom));
      PRECONDITION(Date::validerDate(p_dateNaissance.reqJour(), p_dateNaissance.reqMois(), p_dateNaissance.reqAnnee()));
      PRECONDITION(validerFormatTelephone(p_telephone));

    
      POSTCONDITION(reqNom() == p_nom);
      POSTCONDITION(reqPrenom() == p_prenom);
      POSTCONDITION(reqDateNaissance() == p_dateNaissance);
      POSTCONDITION(reqTelephone() == p_telephone);
      INVARIANTS();

  

  }

  /**
    * \brief Accesseur pour le nom
    * \return le nom de la personne
    */

  string Personne::reqNom() const {
      return m_nom;
  }

  /**
    * \brief Accesseur pour le prénom
    * \return le prénom de la personne
    */

  string Personne::reqPrenom() const {
      return m_prenom;
  }

  /**
    * \brief Accesseur pour le numéro de téléphone
    * \return le numéro de téléphone de la personne
    */

  string Personne::reqTelephone() const {
      return m_telephone;
  }

  /**
    * \brief Accesseur pour la date de naissance
    * \return la date de naissance de la personne
    */

  Date Personne::reqDateNaissance() const {
      return m_dateNaissance;
  }
  
  /**
    * \brief Mutateur pour le numéro de téléphone
    * \param[in] p_telephone est le nouveau numero de telephone qui doit respecter le bon format 
    * \pre p_telephone doit correspondre à un numero de telephone valide
    * \post m_telephone prend la bonne valeur de p_telephone
    */
  
  void Personne::asgTelephone(const string& p_telephone)
  {
	PRECONDITION(validerFormatTelephone(p_telephone));
	m_telephone = p_telephone;
	POSTCONDITION(m_telephone == p_telephone);
	INVARIANTS();
   }
  
  /**
    * \brief Opérateur de comparaison d'égalité
    * \param[in] autrePersonne une autre instance de Personne à comparer
    * \return true si les deux personnes ont les meme valeurs d'attributs, false sinon
    */

  bool Personne::operator==(const Personne& autrePersonne) const {
      return m_nom == autrePersonne.m_nom &&
             m_prenom == autrePersonne.m_prenom &&
             m_dateNaissance == autrePersonne.m_dateNaissance;
  }

  /**
   * \brief Retourne une personne formatée en chaîne de caractères
   * \return les information de la personne formatée dans le bon format
   */

  string Personne::reqPersonneFormate() const {
      ostringstream sortie;
      sortie << "Nom               : " << reqNom() << endl;
      sortie << "Prenom            : " << reqPrenom() << endl;
      sortie << "Date de naissance : " << m_dateNaissance.reqDateFormatee() << endl;
      sortie << "Telephone         : " << reqTelephone() << endl;
      return sortie.str();
  }

  /**
   * \brief Vérifie les invariants de la classe personne
  */

  void Personne::verifieInvariant() const
  
  {
	INVARIANT(validerFormatNom(m_nom));
	INVARIANT(validerFormatNom(m_prenom));
	INVARIANT(
			Date::validerDate(m_dateNaissance.reqJour(), m_dateNaissance.reqMois(), m_dateNaissance.reqAnnee()));
	INVARIANT(validerFormatTelephone(m_telephone));
}

  Personne::~Personne() {}

}  /* namespace hockey */