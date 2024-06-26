#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;
static FILE *pita;
static FILE *command;
static int retval;

void START(char *filename)
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != MARK maka EOP akan padam (false)
    Jika CC = MARK maka EOP akan menyala (true) */
    pita = fopen(filename, "r");
    ADV();
}

void ADV()
{
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela = CC, CC != MARK
    F.S. : CC adalah karakter berikutnya dari CC yang lama,

    CC mungkin = MARK
    Jika CC = MARK maka EOP akan menyala (true) */

    retval = fscanf(pita, "%c", &currentChar);
    if (IsEOP())
    {
        fclose(pita);
    }
}

void COMMAND()
{
    /*  Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
        Karakter pertama yang ada pada pita posisinya adalah pada jendela.
        filename merupakan nama file yang berisi pita karakter
        I.S. : sembarang
        F.S. : CC adalah karakter pertama pada pita
        Jika CC != ENTER maka EOP akan padam (false)
        Jika CC = ENTER maka EOP akan menyala (true) */
    pita = stdin;
    ADVC();
}

void ADVC()
{
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela = CC, CC != ENTER
    F.S. : CC adalah karakter berikutnya dari CC yang lama,*/
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == ENTER);
}

char GetCC()
{
    return (currentChar);
}

boolean IsEOP()
{
    return (currentChar == MARK);
}

int KSTART(char *filename)
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != MARK maka EOP akan padam (false)
    Jika CC = MARK maka EOP akan menyala (true) */

    pita = fopen(filename, "r");
    if (pita == NULL)
    {
        return 0;
    }
    else
    {
        return 1;

    }
}
