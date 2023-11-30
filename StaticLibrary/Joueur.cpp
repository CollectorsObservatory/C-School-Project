/**
 * \file Joueur.cpp
 * \brief Implémentation de la classe Joueur dérivée de personne
 * \author Fares Majdoub
 * \date 2023-11-28
 */

#include "Joueur.h"
#include "validationFormat.h"
#include <sstream>
#include <memory>

using namespace std;

namespace hockey {
  
  /**
   * \brief Constructeur Joueur avec paramètres
   *        Crée un objet Joueur à partir de valeurs spécifiées.
   * \param[in] p_nom le nom de la personne
   * \param[in] p_prenom le prénom de la personne
   * \param[in] p_dateNaissance la date de naissance de la personne
   * \param[in] p_telephone le numéro de téléphone de la personne
   * \param[in] p_position la position du joueur dans l'équipe 
   * \pre p_position doit être "CENTRE", "AILIER", "DEFENSEUR" ou "GARDIEN".
   * \pre L'âge du joueur (calculé à partir de p_dateNaissance) doit être entre 15 et 17 ans.
   * \post La position du joueur est correctement assignée.
   */

  
  Joueur::Joueur(const string& p_nom, const string& p_prenom, const util::Date& p_dateNaissance,
                 const string& p_telephone, const string& p_position) 
      : Personne(p_nom, p_prenom, p_dateNaissance, p_telephone) {

      string p_positionUpper(p_position);
      util::convertirMaj(p_positionUpper);
      PRECONDITION(p_positionUpper == "CENTRE" || p_positionUpper == "AILIER" 
                   || p_positionUpper == "DEFENSEUR" || p_positionUpper == "GARDIEN");
  
      m_position = p_position;

      util::Date dateActuelle;
      int age = dateActuelle.reqAnnee() - p_dateNaissance.reqAnnee();
      if (p_dateNaissance.reqMois() > dateActuelle.reqMois() ||
         (p_dateNaissance.reqMois() == dateActuelle.reqMois() && p_dateNaissance.reqJour() > dateActuelle.reqJour())) {
          age--;
      }
      PRECONDITION(age >= 15 && age <= 17);

      POSTCONDITION(m_position == p_position);
      INVARIANTS(); }
  

  /**
   * \brief Accesseur pour la position du joueur
   * \return la position du joueur dans l'équipe
   */

  const string& Joueur::reqPosition() const {
      return m_position;
  }


  /**
   * \brief Mutateur pour la position du joueur 
   * \return la nouvelle position du joueur 
   */

  void Joueur::asgPosition(const string& p_position) {
      string p_positionUpper(p_position);
      util::convertirMaj(p_positionUpper);
      PRECONDITION(p_positionUpper == "CENTRE" || p_positionUpper == "AILIER" 
                 || p_positionUpper == "DEFENSEUR" || p_positionUpper == "GARDIEN");

      m_position = p_positionUpper;

      POSTCONDITION(m_position == p_positionUpper);
      INVARIANTS();
  }
  /**
   * \brief crée une copie de l'objet Joueur courant
   * \return un pointeur unique vers un nouvel objet Joueur copié
   */

  unique_ptr<Personne> Joueur::clone() const {
      return make_unique<Joueur>(*this);
  }
  
  /**
   * \brief Retourne un joueur formaté en chaîne de caractères
   * \return les informations du joueur formatées dans le bon format
   */

  string Joueur::reqPersonneFormate() const {
      ostringstream os;
      os << Personne::reqPersonneFormate();
      os << "Position          : " << reqPosition() << endl;
      os << "---------------------" << endl;
      return os.str();
  }


  /**
   * \brief Vérifie les invariants de la classe joueur
  */

  void Joueur::verifieInvariant() const {
      string m_positionUpper(m_position);
      util::convertirMaj(m_positionUpper);
      INVARIANT(m_positionUpper == "CENTRE" || m_positionUpper == "AILIER" 
              || m_positionUpper == "DEFENSEUR" || m_positionUpper == "GARDIEN");
  }

}  /* namespace hockey */
