#include "observateur.h"

Etat initial() {
    return Init;
}

Etat transition(Etat e, Alphabet c) {
    switch (e) {
        case Init:
            switch (c) {
                case A:
                    return Erreur;

                case G:
                case D:
                    return Init;

                case M:
                    return Mes;
            }
            break;

        case Mes:
            switch (c) {
                case A:
                    return Init;

                case M:
                case G:
                case D:
                    return Mes;
            }
            break;

        case Erreur:
            return Erreur;
    }
    return Erreur; // Default return to handle unexpected cases
}

int est_final(Etat e) {
    return e != Erreur;
}