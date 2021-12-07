#include<stdio.h>
#include<stdlib.h>
void afficheGrille();
int demandeAction();
void initialiseGrille();
int executerCoup(int coup, int player);
int gagne();
int verifLigne();
int verifColomne();
int verifDiagonaleHautEnBas();
int verifDiagonaleBasEnHaut();


#define WIDTH_GRILLE 7
#define HEIGHT_GRILLE 6
#define P1_VALUE ('O')
#define P2_VALUE ('X')

static char grille[WIDTH_GRILLE][HEIGHT_GRILLE];

void afficheGrille()
{
    
    int i = 0;
    int j = 0;
    int numLigne  = 0;
    for (numLigne = 1; numLigne <= WIDTH_GRILLE; numLigne++)
        printf("  %d ", numLigne);
    for (j = 0; j < HEIGHT_GRILLE; j++)
    {
        printf("\n");
        for (i = 0; i < WIDTH_GRILLE ; i++)
            printf("+---");
        printf("+\n");
        for (i = 0; i < WIDTH_GRILLE+1; i++)
            printf("| %c ",grille[i][j]);
    }
    printf("\n");
        for (i = 0; i < WIDTH_GRILLE ; i++)
            printf("+---");
        printf("+\n");
}

void initialiseGrille()
{
    int ligne = 0;
    int colomne  = 0;
    for (colomne = 0; colomne < HEIGHT_GRILLE; colomne++)
    {
        for (ligne = 0; ligne < WIDTH_GRILLE; ligne++)
        {
            grille[ligne][colomne] = ' ';
        }
    }
}

int demandeAction()
{   
    int coup;
    do
    {
        printf("Veuillez entrer le numero de la ligne de votre coup.\n");
        scanf("%d", &coup);
    } while (coup < 1 || coup > WIDTH_GRILLE);
    return (coup-1);
}

int executerCoup(int coup, int player)
{
    int i = 0;
    int run = 0;
    while ( i <= HEIGHT_GRILLE && run == 0)
    {
        i += 1;

        if (grille[coup][HEIGHT_GRILLE - i] == ' ')
        {
            if (player == 1)
            {
                grille[coup][HEIGHT_GRILLE - i] = P1_VALUE;
            }
            else 
            {
                grille[coup][HEIGHT_GRILLE - i] = P2_VALUE;
            }
            run = 1;
        }
    }

    return 0;
}
/*----------------------------------------------------------------*/
// Vérifier si un des joueurs a gagné

int verifLigne()
{
    int i = 0, j = 0;
    int gagne = 0;

    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < (HEIGHT_GRILLE -1); i++)
        {
            if (grille[i][j] == P1_VALUE || grille[i][j] == P2_VALUE)
            {
                if (grille[i][j] == grille[i][j+1] && grille[i][j] == grille[i][j+2] && grille[i][j]== grille[i][j+3])
                {
                    gagne = 1;
                }
            }
        }
    }
    return gagne;
}

int verifColomne()
{
    int i = 0, j = 0;

    
}

int verifDiagonaleHautEnBas()
{
    int i = 0, j = 0;
    
}

int verifDiagonaleBasEnHaut()
{
    int i = 0, j = 0;
    
}

int gagne()
{
    int gagne = verifLigne();
    if (gagne == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




/*----------------------------------------------------------------*/

int main(void)
{
    int coup = 0;
    int numTour = 0;
    
    initialiseGrille();

    while (gagne() == 0)
    {
        numTour += 1; 

        afficheGrille();
        coup = demandeAction();
        executerCoup(coup,(numTour%2));
    } 

    return 0;
}