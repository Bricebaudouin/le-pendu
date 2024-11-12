#include <iostream>

int main() {
    const char* mot = "PROGRAMMATION";
    char lettresTrouvees[30] = {};
    char motAffiche[30] = {}; // Pour afficher le mot avec les lettres trouvées
    int tentativesMax = 6;
    int tentatives = tentativesMax;
    int lettresTrouveesCount = 0;

    // Calculer la longueur du mot
    int longueurMot = 0;
    while (mot[longueurMot] != '\0') {
        longueurMot++;
    }

    // Initialiser le mot affiché avec des underscores
    for (int i = 0; i < longueurMot; i++) {
        motAffiche[i] = '_';
    }
    motAffiche[longueurMot] = '\0'; // Terminateur de chaîne

    while (tentatives > 0) {
        std::cout << "\nMot a deviner: ";
        for (int i = 0; i < longueurMot; i++) {
            std::cout << motAffiche[i] << ' ';
        }
        std::cout << "\nLettres deja proposées: ";
        for (int k = 0; k < lettresTrouveesCount; k++) {
            std::cout << lettresTrouvees[k] << ' ';
        }
        std::cout << "\n";

        char proposition;
        std::cout << "Proposez une lettre: ";
        std::cin >> proposition;
        proposition = toupper(proposition); // Convertir en majuscule

        // Vérifier si la lettre a déjà été proposée
        bool dejaProposee = false;
        for (int k = 0; k < lettresTrouveesCount; k++) {
            if (lettresTrouvees[k] == proposition) {
                dejaProposee = true;
                break;
            }
        }

        if (dejaProposee) {
            std::cout << "Vous avez deja propose cette lettre.\n";
            continue;
        }

        lettresTrouvees[lettresTrouveesCount++] = proposition;

        // Vérifier si la lettre proposée est dans le mot
        bool lettreTrouvee = false;
        for (int i = 0; i < longueurMot; i++) {
            if (mot[i] == proposition) {
                motAffiche[i] = mot[i]; // Remplir toutes les occurrences
                lettreTrouvee = true;
            }
        }

        if (!lettreTrouvee) {
            tentatives--;
            std::cout << "Incorrect! Tentatives restantes: " << tentatives << "\n";
        }

        // Vérifier si le joueur a gagné
        bool gagne = true;
        for (int i = 0; i < longueurMot; i++) {
            if (motAffiche[i] == '_') {
                gagne = false;
                break;
            }
        }

        if (gagne) {
            std::cout << "Felicitations! Vous avez devine le mot: " << mot << "\n";
            return 0;
        }
    }

    std::cout << "Desole! Vous avez perdu. Le mot etait: " << mot << "\n";
    return 0;
}