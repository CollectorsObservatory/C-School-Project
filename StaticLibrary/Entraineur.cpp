/**
  * \file Entraineur.cpp
  * \brief Classe Entraineur, classe fille de Personne
  * \author Fares Majdoub
  * \date 2023-11-28
  */
#include "Entraineur.h"
#include "validationFormat.h"
#include <sstream>

using namespace std;


namespace hockey {
   /**
     * \brief Constructeur d'un nouvel objet de la classe Entraineur
     * \param[in] p_nom le nom de l'entraineur
     * \param[in] p_prenom le prenom de l'entraineur
     * \param[in] p_dateNaissance la date de naissance de l'entraineur
     * \param[in] p_telephone le numéro de téléphone de l'entraineur
     * \param[in] p_numRAMQ le numéro RAMQ de l'entraineur
     * \param[in] p_sexe le sexe de l'entraineur ('M' ou 'F')
     * 
     * \pre Le sexe doit être 'M' ou 'F'.
     * \pre Le numéro RAMQ doit être valide selon les normes établies.
     * \pre L'entraineur doit avoir plus de 18 ans.
     * 
     * \post Le numéro RAMQ et le sexe de l'entraineur doivent correspondre aux paramètres fournis.
     */
    
    Entraineur::Entraineur(
        const string& p_nom,
        const string& p_prenom,
        const util::Date& p_dateNaissance,
        const string& p_telephone,
        const string& p_numRAMQ,
        char p_sexe) :
        Personne(p_nom, p_prenom, p_dateNaissance, p_telephone), m_numRAMQ(p_numRAMQ), m_sexe(p_sexe)
    {
        PRECONDITION(p_sexe == 'M' || p_sexe == 'F');
        PRECONDITION(util::validerFormatNumRAMQ(p_numRAMQ, p_nom, p_prenom, 
            p_dateNaissance.reqJour(), p_dateNaissance.reqMois(), 
            p_dateNaissance.reqAnnee(), p_sexe));

        // Utiliser la classe Date pour obtenir la date actuelle
        util::Date dateAujourdhui;

        // Calculer l'âge
        int age = dateAujourdhui.reqAnnee() - p_dateNaissance.reqAnnee();
        if (p_dateNaissance.reqMois() > dateAujourdhui.reqMois() ||
            (p_dateNaissance.reqMois() == dateAujourdhui.reqMois() && 
             p_dateNaissance.reqJour() > dateAujourdhui.reqJour())) {
            age--;
        }

        // Vérifier que l'entraîneur a plus de 18 ans
        PRECONDITION(age >= 18);

        POSTCONDITION(m_numRAMQ == p_numRAMQ);
        POSTCONDITION(m_sexe == p_sexe);
        INVARIANTS();
    }
    
    /**
      * \brief Accesseur pour le numéro RAMQ de l'entraineur
      * \return numéro RAMQ de l'entraineur
      */

    const string& Entraineur::reqNumRamq() const {
        return m_numRAMQ;
    }
    
    /**
      * \brief un accesseur pour le sexe de l'entraineur
      * \return le sexe de l'entraineur
      */
    
    char Entraineur::reqSexe() const {
        return m_sexe;
    }
    
    /**
      * \brief crée une copie de l'objet entraineur courant
      * \return un pointeur unique vers un nouvel objet entraineur copié
      */
    
    unique_ptr<Personne> Entraineur::clone() const {
        return make_unique<Entraineur>(*this);
    }
    /**
      * \brief retourne un entraineur formaté en chaîne de caractères
      * \return les informations d'un entraineur formatées dans le bon format
      */
    string Entraineur::reqPersonneFormate() const {
        ostringstream os;
        os << Personne::reqPersonneFormate();
        os << "Numero de RAMQ    : " << Entraineur::reqNumRamq() << endl;
        os << "---------------------" << endl;
        return os.str();
    }
    
    /**
      * \brief Vérifier les invariants de la classe entraineur
      */

    void Entraineur::verifieInvariant() const {
        INVARIANT(m_sexe == 'M' || m_sexe == 'F');
        INVARIANT(util::validerFormatNumRAMQ(m_numRAMQ, m_nom, m_prenom, 
                 m_dateNaissance.reqJour(), m_dateNaissance.reqMois(), 
                 m_dateNaissance.reqAnnee(), m_sexe));
    }
}
/* namespace hockey */
