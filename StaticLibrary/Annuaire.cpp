/**
 * \file Annuaire.cpp
 * \brief Fichier contenant la déclaration de la classe annuaire
 * \author Fares Majdoub
 * \date 2023-11-28
 */
#include "Annuaire.h"
#include "ContratException.h"
#include <sstream>
#include <memory>

using namespace std;
using namespace util;

namespace hockey {
  
    /**
      * \brief Constructeur par défaut de la classe Annuaire.
      *        Initialise un annuaire avec le nom du club spécifié.
      * \param[in] p_nomClub le nom du club.
      * \pre p_nomClub doit être composé uniquement de lettres et non vide.
      * \post le nom du club est correctement assigné
      */

    Annuaire::Annuaire(const string& p_nomClub) {
        PRECONDITION(validerFormatNom(p_nomClub));
        m_nomClub = p_nomClub;
        POSTCONDITION(reqNom() == m_nomClub);
        INVARIANTS();
    }
     /**
      * \brief Accesseur pour le nom du club.
      * \return Le nom du club de l'annuaire.
      */

    string Annuaire::reqNom() const {
        return m_nomClub;
    }
    
    /**
      * \brief Formate les informations de l'annuaire 
      * \return les informations de l'annuaire formatées en chaîne de caractères.
      */

    string Annuaire::reqAnnuaireFormate() const {
        ostringstream os;
        os << "Club : " << reqNom() << endl;
        os << "---------------------" << endl;
        for (const auto& membre : m_membres) {
            os << membre->reqPersonneFormate() << endl;
        }
        return os.str();
    }
    /**
      * \brief Ajoute une personne à l'annuaire.
      * \param[in] p_personne la personne à ajouter.
      * \pre La personne ne doit pas déjà exister dans l'annuaire.
      */

    void Annuaire::ajouterPersonne(const Personne& p_personne) {
        m_membres.push_back(unique_ptr<Personne>(p_personne.clone()));
        INVARIANTS();
    }
    /**
      * \brief Constructeur de copie de la classe Annuaire.
      *        Crée une copie profonde de l'annuaire spécifié
      * \param[in] autre annuaire à copier.
      */
    
    Annuaire::Annuaire(const Annuaire& autre)
        : m_nomClub(autre.m_nomClub) {
        for (const auto& membre : autre.m_membres) {
            m_membres.push_back(unique_ptr<Personne>(membre->clone()));
        }
    }
    
    /**
      * \brief Surcharge de l'opérateur d'affectation.
      *        Remplace l'annuaire actuel par une copie de l'annuaire spécifié.
      * \param[in] autre annuaire à copier.
      * \return Une référence vers l'annuaire actuel.
      */
    
    Annuaire& Annuaire::operator=(const Annuaire& autre) {
        if (this != &autre) {
            m_nomClub = autre.m_nomClub;
            m_membres.clear();
            for (const auto& membre : autre.m_membres) {
                m_membres.push_back(unique_ptr<Personne>(membre->clone()));
            }
        }
        return *this;
    }
   /**
     * \brief Retourne le nombre de personnes enregistrées dans l'annuaire.
     * \return Le nombre de personnes enregistrées.
     */
    size_t Annuaire::reqNombrePersonnes() const {
        return m_membres.size();
    }

    /**
      * \brief Vérifie les invariants de la classe Annuaire.
      */

    void Annuaire::verifieInvariant() const {
        INVARIANT(!(m_nomClub.empty()));
    }

} /* namespace hockey */
