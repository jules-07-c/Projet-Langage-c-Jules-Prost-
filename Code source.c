#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int addition() {
    int addition1;
    int addition2;
    int additionR0;
    int additionR1;
    int essais;
    int points = 0;

    while(1)
    {
        addition1 = rand() % 101;
        addition2 = rand() % 101;
        additionR0 = addition1 + addition2;

        printf("%d + %d = ?\n", addition1, addition2);
        printf("-1 pour retourner au menu\n");
        essais = 0;
        while(essais < 3)
        {
            scanf("%d", &additionR1);
            if(additionR1 == -1)
                return points;
            if(additionR1 == additionR0)
            {
                if(essais == 0)
                    points += 10;
                else if(essais == 1)
                    points += 5;
                else
                    points += 1;
                printf("Bon resultat !\n");
                break;
            }
            essais++;
            if(essais < 3)
                printf("essayez encore\n");
        }
        if(essais == 3)
        {
            printf("mauvais resultat la reponse etait %d\n", additionR0);
        }
    }
    return points;
}

int soustraction()
{
    int addition1;
    int addition2;
    int additionR0;
    int additionR1;
    int essais;
    int points = 0;

    while(1)
    {
        addition1 = rand() % 110;
        addition2 = rand() % 110;
        if (addition1 >= addition2)
        {
            additionR0 = addition1 - addition2;
            printf("%d - %d = ?\n", addition1, addition2);
        }
        else
        {
            additionR0 = addition2 - addition1;
            printf("%d - %d = ?\n", addition2, addition1);
        }
        printf("-1 pour retourner au menu\n");
        essais = 0;
        while(essais < 3)
        {
            scanf("%d", &additionR1);
            if(additionR1 == -1)
                return points;

            if(additionR1 == additionR0)
            {
                if(essais == 0)
                    points += 10;
                else if(essais == 1)
                    points += 5;
                else
                    points += 1;

                printf("Bon resultat !\n");
                break;
            }
            essais++;
            if(essais < 3)
                printf("essayez encore\n");
        }
        if(essais == 3)
            printf("mauvais resultat  la reponse etait %d\n", additionR0);
    }
    return points;
}

int multiplication() {
    int addition1;
    int addition2;
    int additionR0;
    int additionR1;
    int essais;
    int points = 0;

    while(1)
    {
        addition1 = rand() % 9 + 2;
        addition2 = rand() % 9 + 2;
        additionR0 = addition1 * addition2;
        printf("%d * %d = ?\n", addition1, addition2);
        printf("-1 pour retourner au menu\n");
        essais = 0;
        while(essais < 3)
        {
            scanf("%d", &additionR1);
            if(additionR1 == -1)
                return points;
            if(additionR1 == additionR0)
            {
                if(essais == 0)
                    points += 10;
                else if(essais == 1)
                    points += 5;
                else
                    points += 1;
                printf("Bon resultat !\n");
                break;
            }
            essais++;
            if(essais < 3)
                printf("essayez encore\n");
        }
        if(essais == 3)
            printf("mauvais resultat ! la reponse etait %d\n", additionR0);
    }
    return points;
}

void tableMultiplication() {
    int TableM0;
    int TableM1;
    int TableM2;
    int i;

    while (1) {
        printf("quelle table voulez-vous afficher ?\n");
        printf("-1 pour revenir au menu\n");
        scanf("%d", &TableM0);

        if (TableM0 == -1) break;

        while (TableM0 <= 0 || TableM0 > 10) {
            printf("uniquement les tables de 1 à 10 : ");
            scanf("%d", &TableM0);
        }

        for (i = 1; i <= 10; i++) {
            TableM1 = TableM0 * i;
            printf("%d * %d = ?\n", TableM0, i);
            scanf("%d", &TableM2);
            if (TableM2==TableM1)
                printf("Bon résultat !\n");
            else
                printf("mauvais resultat  la reponse etait %d\n", TableM1);
        }

        printf("Table terminee ! \n");
    }
}

int division() {
    int addition1;
    int addition2;
    int additionR0;
    int additionR1;
    int essais;
    int points = 0;

    while(1)
    {
        addition1 = rand() % 51;
        addition2 = rand() % 9 + 2;
        while(addition1 % addition2 != 0)
        {
            addition2 = rand() % 9 + 2;
        }
        additionR0 = addition1 / addition2;
        printf("%d / %d = ?\n", addition1, addition2);
        printf("-1 pour retourner au menu\n");
        essais = 0;
        while(essais < 3)
        {
            scanf("%d", &additionR1);
            if(additionR1 == -1)
                return points;
            if(additionR1 == additionR0)
            {
                if(essais == 0)
                    points += 10;
                else if(essais == 1)
                    points += 5;
                else
                    points += 1;
                printf("Bon resultat !\n");
                break;
            }
            essais++;
            if(essais < 3)
                printf("essayez encore\n");
        }
        if(essais == 3)
            printf("mauvais resultat ! la reponse etait %d\n", additionR0);
    }
    return points;
}


void sauvscore(char nom[], int point)
{
    FILE *fichier = fopen("scores.txt", "a");

    if (fichier == NULL)
    {
        printf("erreur ouverture du fichier\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(fichier, "%s %02d/%02d/%d %02d:%02d %d\n",
            nom,
            tm.tm_mday,
            tm.tm_mon + 1,
            tm.tm_year + 1900,
            tm.tm_hour,
            tm.tm_min,
            point);

    fclose(fichier);
}
int chargescore(char nom[])
{
    FILE *fichier = fopen("scores.txt", "r");

    if (fichier == NULL)
        return 0;

    char nomFichier[50];
    char date[20];
    char heure[10];
    int score;
    int dernierScore = 0;

    while (fscanf(fichier, "%s %s %s %d",
                  nomFichier, date, heure, &score) == 4)
    {
        if (strcmp(nom, nomFichier) == 0)
        {
            dernierScore = score;
        }
    }

    fclose(fichier);

    return dernierScore;
}



int main() {
    srand(time(NULL));
    int choix;
    char nom[50];


    printf("entrez votre nom : \n");
    scanf("%s",nom);

    int point = chargescore(nom);


    printf("bienvenue %s \n", nom);
    printf("vous avez actuellement %d points\n", point);

    do {
            printf("+-----------------------------------+\n");
            printf("| 1 : Addition\n| 2 : Soustraction\n| 3 : Multiplication\n| 4 : Tables de multiplication\n| 5 : Division\n| 6 : Points \n| 0 : Sortir du jeu\n");
            printf("+-----------------------------------+\n");
            printf("Quel est votre choix ? ");
            scanf("%d", &choix);

            switch (choix)
            {
                    case 1: point += addition(); sauvscore(nom,point); break;
                    case 2: point += soustraction(); sauvscore(nom,point); break;
                    case 3: point += multiplication(); sauvscore(nom,point); break;
                    case 4: tableMultiplication(); point=point+1;sauvscore(nom,point);break;
                    case 5: point += division(); sauvscore(nom,point); break;
                    case 6: printf("vous avez : %d points.",point); break;
                    case 0: printf("Merci de votre visite !\n"); break;
                    default: printf("Choix invalide !\n");
            }

            printf("\n");

        }

    while(choix != 0);


    return 0;}


