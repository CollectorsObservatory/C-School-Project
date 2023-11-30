/**
  * \file Entraineur.h
  * \brief Classe Entraineur, classe fille de Personne
  * \author Fares Majdoub
  * \date 2023-11-28
  */


#ifndef ENTRAINEUR_H_
#define ENTRAINEUR_H_

#include "Personne.h"
#include "Date.h"
#include <string>

namespace hockey {

    class Entraineur : public Personne {
    public:
        Entraineur(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance,
                   const std::string& p_telephone, const std::string& p_numRAMQ, char p_sexe);

    
        const std::string& reqNumRamq() const;
        char reqSexe() const;
        virtual std::string reqPersonneFormate() const override;
        virtual std::unique_ptr<Personne> clone() const override;

        
    private:
        
        std::string m_numRAMQ;
        char m_sexe;
        void verifieInvariant() const;
    };

} /* namespace hockey */

#endif /* ENTRAINEUR_H_ */
