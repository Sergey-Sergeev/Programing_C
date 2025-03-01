#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// çäåñü âñå ÷òî íåîáõîäèìî ãëîáàëüíîå
char delims[] = ", .()[]\"=\\/?_*~`:;!@#$%^|";
int isflineBufferEmpty = 1;
char* flineBuffer = NULL;
int F_LINE_BUFF_LEN = 1000; //  + 1 äëÿ îêîí÷àíèÿ ñòðîêè

typedef struct word {
    int count;
    char* Word;
} WORD;

int cmpword_alpha(WORD*, WORD*);
int cmpword_quant(WORD*, WORD*);
char* getword(FILE* F);
void getwordflush();
void toLowerCase(char* str);
int iscontain(WORD* words, char* word, int len);
void writeListToFile(WORD* words, int len, FILE* F);
void showList(WORD* words, int len);


WORD words[10000000];
int curEmptyIndex = 0;

int main(int ac, char* av[])
{
    FILE* OUT1, * OUT2, * IN;
    char* pword;

    // çäåñü îòêðûòü ôàéëû äëÿ âûâîäà,
    // ïðîâåðêà íà óñïåõ,  èíèöèàëèçàöèÿ ïåðåìåííûõ è ò.ä.
    if (ac < 2)
    {
        printf("You forgot to add files!\n"); 
        exit(0);
    }
    while (--ac) // èäåì ïî ñïèñêó ôàéëîâ
    //--ac;     // For debug
    {
        IN = fopen(av[ac], "r");
        printf("File in process: %s\n", av[ac]);
        // îòêðûâàåì î÷åðåäíîé ôàéë
        while ((pword = getword(IN)) != NULL)
        {           
            toLowerCase(pword);

            int wordIndex = iscontain(words, pword, curEmptyIndex);
            if (wordIndex != -1)
            {
                words[wordIndex].count++;
            }            
            else
            {
                //  âûäåëÿåì ïàìÿòü äëÿ ñòðîêè
                words[curEmptyIndex].Word = (char*)malloc(sizeof(char) * strlen(pword));
                strcpy(words[curEmptyIndex].Word, pword);
                words[curEmptyIndex].count = 1;
                curEmptyIndex++;
            }
        }
        fclose(IN);
    }

    // Ñîðòèðîâêà ïî àëôàâèòó
    qsort(words, curEmptyIndex, sizeof(WORD), (int (*)(const void*, const void*))cmpword_alpha);
    // çäåñü âûâîä ìàññèâà
    //showList(words, curEmptyIndex);
    OUT1 = fopen("out1.txt", "w");
    writeListToFile(words, curEmptyIndex, OUT1);
    fclose(OUT1);

    // Ñîðòèðîâêà ïî êîëè÷åñòâó èñïîëüçîâàíèé
    qsort(words, curEmptyIndex, sizeof(WORD), (int (*)(const void*, const void*))cmpword_quant);
    // çäåñü âûâîä ìàññèâà
    //showList(words, curEmptyIndex);
    OUT2 = fopen("out2.txt", "w");
    writeListToFile(words, curEmptyIndex, OUT2);

    printf("\nTotal words: [ %d ]", curEmptyIndex);

    
    fclose(OUT2);
    getwordflush();
    return 0;
}
char* getword(FILE* F)
{
    // Ïðîâåðÿåì êîíåö ëè ôàéëà è îñòàëîñü ëè åù¸ ÷òî-òî 
    if (feof(F) && isflineBufferEmpty) return NULL;

    if (flineBuffer == NULL)
    {
        flineBuffer = (char*)malloc(sizeof(char) * (F_LINE_BUFF_LEN + 1));
        flineBuffer[F_LINE_BUFF_LEN] = '\0';
    }    

    int i = 0;
    while (isflineBufferEmpty)
    {
        char ch = fgetc(F);

        if (ch == -1 || ch == '.')
        {
            flineBuffer[i] = '\0';
            break;
        }

        if (isalpha(ch) == 0 && ch != ' ') continue;
        else 
        {
            flineBuffer[i] = ch;
            i++;
            if (i == F_LINE_BUFF_LEN) break;               
        }
    }

    char* s;

    if (isflineBufferEmpty)
    {
        isflineBufferEmpty = 0;
        s = strtok(flineBuffer, delims);
    }
    else
    {
        s = strtok(NULL, delims);
    }


    //  çàêîí÷èëñÿ ëèáî áóôåð, ëèáî ôàéë. Âûçûâàåì ïîâòðîíî ôóíêöèþ.
    if (s == NULL)
    {
        isflineBufferEmpty = 1;
        return getword(F);
    }

    return s;
}

//  Flush resourses that was used in function getword()
void getwordflush()
{
    free(flineBuffer);
}

//  Return 1 if list contains the word, else return 0
int iscontain(WORD* words, char* word, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (strcmp(words[i].Word, word) == 0)
        {
            return i;
        }
    }

    return -1;
}

void toLowerCase(char* str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int cmpword_alpha(WORD* w1, WORD* w2)
{
    return strcmp(w1->Word, w2->Word);
}

int cmpword_quant(WORD* w1, WORD* w2)
{
    if (w1->count > w2->count)
        return -1;
    else if (w1->count < w2->count)
        return 1;
    return 0;
}

//      For Debug
void showList(WORD* words, int len)
{
    printf("\n[ ------------------------------------------------- ]\n");
    int i;
    for (i = 0; i < len; i++)
    {
        printf("[ %s ]\t -- \t[ %d ]\n", words[i].Word, words[i].count);
    }
    printf("[ ------------------------------------------------- ]\n");
}

void writeListToFile(WORD* words, int len, FILE* F)
{
    int i = 0;
    char buff[100];
    for (i = 0; i < len; i++)
    {
        sprintf(buff, "[ %s ]\t -- \t[ %d ]\n", words[i].Word, words[i].count);
        fwrite(buff, sizeof(char), strlen(buff), F);
    }
}
