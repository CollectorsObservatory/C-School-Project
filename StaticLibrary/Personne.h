/**
 * \file Personne.h
 * \brief Classe Personne, abstraite conçue pour les membres de l'équipe du hockey
 * \author Fares Majdoub
 * \date 2023-11-28
 */
#include <memory>
#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <string>
#include <memory>
#include "Date.h" 
#include "ContratException.h"



namespace hockey {

    class Personne {
    public:
     
        Personne(const std::string& p_nom, const std::string& p_prenom, 
                 const util::Date& p_dateNaissance, const std::string& p_telephone);

     
        std::string reqNom() const;
        std::string reqPrenom() const;
        util::Date  reqDateNaissance() const;  
        std::string reqTelephone() const;
        void asgTelephone(const std::string& p_telephone);

      
        bool operator==(const Personne& autrePersonne) const;

        virtual std::string reqPersonneFormate() const = 0; 
        virtual std::unique_ptr<Personne> clone() const = 0;  
      
        virtual ~Personne();


    protected:
        // Attributs
        std::string m_nom;
        std::string m_prenom;
        util::Date m_dateNaissance;  
        std::string m_telephone;
    private:
        void verifieInvariant() const;
    };

} /* namespace hockey */

#endif /* PERSONNE_H_ */
