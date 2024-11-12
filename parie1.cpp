#include "Exo.h"
#include <iostream>
#include <stdio.h>
int longueur(const char *chaine){
    int i = 0;
    while (chaine[i] != '\0'){
        i++;
    }
    return i;
}


void copie(char *dest, const char *source){
    while (*source != '\0'){
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
}

void concatenate(char *dest, const char *source){
    while (*source != '\0'){
        dest++;
        if (*dest == '\0'){
            *dest = *source;
            source++;
        }

    }
    *dest = '\0';
}

int compare(const char *chaine1, const char *chaine2){
    int i = longueur(chaine1);
    int j = longueur(chaine2);

    while (*chaine1 != '\0' || *chaine2 != '\0' ){
        if(*chaine1 == *chaine2){
            chaine1++;
            chaine2++;
            if (*chaine1 == '\0' || *chaine2 == '\0'){
                if (i < j){
                    return -1;
                } else if (i > j){
                    return 1;
                } else if (i == j){
                    return 0;
                }
            }
        }else if (*chaine1 < *chaine2){
            return -1;
        } else if (*chaine1 > *chaine2){
            return 1;
        }
    }

}
char *cherche_char(const char *chaine, char caractere){
    while (*chaine !='\0')
    {
        if(*chaine == caractere)
        {
            return (char*)caractere;
        }
        chaine++;
    }
    return NULL;
}

void inversion_chaine(char *chaine){
    int Var = longueur(chaine);
    char chaineTampon[longueur(chaine)];
    while (*chaine != '\0'){
        for (int i = Var - 1; i >= 0 ; i--) {
            chaineTampon[i] = *chaine;
            chaine++;
        }
    }
    for (int i = 0; i < Var; ++i) {
        std::cout<<chaineTampon[i];

    }

}



