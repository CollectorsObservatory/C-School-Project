/**
 * \file Joueur.h
 * \brief Classe Joueur, dérivée de la classe Personne.
 * \author Fares Majdoub
 * \date 2023-11-28
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include "Personne.h"
#include <memory>

namespace hockey {
  
    class Joueur : public Personne {
      
    public:
      
        Joueur(const std::string& p_nom, const std::string& p_prenom,
               const util::Date& p_dateNaissance, const std::string& p_telephone,
               const std::string& p_position);
        
        const std::string& reqPosition() const;
        void asgPosition(const std::string& p_position);

        virtual std::string reqPersonneFormate() const override;
        virtual std::unique_ptr<Personne> clone() const override;

        

    private:
      
        std::string m_position; 
        void verifieInvariant() const;
    };
} /* namespace hockey */

#endif /* JOUEUR_H_ */

