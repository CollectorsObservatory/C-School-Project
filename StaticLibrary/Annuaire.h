/**
 * \file Annuaire.h
 * \brief Fichier contenant la déclaration de la classe annuaire
 * \author Fares Majdoub
 * \date 2023-11-28
 */
#ifndef ANNUAIRE_H_
#define ANNUAIRE_H_

#include <string>
#include <vector>
#include <memory>
#include "Personne.h"
#include "validationFormat.h" 
#include "ContratException.h"

namespace hockey {
    class Annuaire {
      
    public:
      
        Annuaire(const std::string& p_nomClub);
        std::string reqNom() const;
        std::string reqAnnuaireFormate() const;
        void ajouterPersonne(const Personne& p_personne);
        

        Annuaire(const Annuaire& autre);
        Annuaire& operator=(const Annuaire& autre);
        size_t reqNombrePersonnes() const;
        ~Annuaire() = default;

    private:
       
        std::string m_nomClub;
        std::vector<std::unique_ptr<Personne>> m_membres;
        void verifieInvariant() const;
    };
}

#endif /* ANNUAIRE_H_ */
