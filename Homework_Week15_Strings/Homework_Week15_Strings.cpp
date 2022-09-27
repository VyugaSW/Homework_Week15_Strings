

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

char* DeleteSymbol();
char* DeleteAllSymbol();
char* SymbolInString();
char* SymbolPointReplacement();
void Symbolreplacement();
void CheckSymbols();

int main()
{
    //cout << DeleteSymbol();        //Task 1
    //cout << DeleteAllSymbol();     //Task 2
    //cout << SymbolInString();        //Task 3
    //cout << SymbolPointReplacement();    //Task 4
    Symbolreplacement();        //Task 5
    //CheckSymbols();      //Task 6
}

//Task 1  Написать функцию, которая удаляет из строки
//символ с заданным номером.
char* DeleteSymbol() {
    char* strin = new char[256]{ "Hello my lovest world of the worlds" };
    char* new_strin = new char[strlen(strin) - 1];
    int delIndex = 3;
    strncpy_s(new_strin, strlen(strin), strin, delIndex - 1);
    strcat_s(new_strin, strlen(strin),strin+delIndex);
    delete[] strin;
    return new_strin;
}

//Task 2 Написать функцию, которая удаляет из строки
//все вхождения в нее заданного символа
char* DeleteAllSymbol() {
    char* strin = new char[256]{ "Hello my lovest world of the worlds" };
    char* new_strin = new char[256]{""};
    char* str;
    char element = 'l';
    while (str = strchr(strin,element)) {
        strncat_s(new_strin,strlen(strin),strin,strlen(strin)-strlen(str));
        strin = str+1;
    }
    strcat_s(new_strin, strlen(str)+5,str);
    return new_strin;
 }

//Task 3 Написать функцию, которая вставляет в строку
//в указанную позицию заданный символ.
char* SymbolInString() {
    char* strin = new char[256]{ "Hello my lovest world of the worlds" };
    int index = 5;
    char litera = 'A';
    char* new_strin = new char[strlen(strin)+1];
    strncpy_s(new_strin, strlen(strin), strin, index+1);
    *(new_strin+index) = litera;
    strcat_s(new_strin, strlen(strin)+2, strin + index);
    return new_strin;
}

//Task 4 Написать программу, которая заменяет все
//символы точки «.» в строке, введенной пользователем,
//на символы восклицательного знака «!».
char* SymbolPointReplacement() {
    char* strin = new char[256];
    gets_s(strin,256);
    char* str;
    while (str = strchr(strin, '.')) {
        *(str) = '!';
        strcpy_s(strin+strlen(strin)-strlen(str), strlen(strin), str);
    }
    return strin;
}

//Task 5 Пользователь вводит строку символов и ис-
//комый символ, посчитать сколько раз он встречается
//в строке.
void Symbolreplacement() {
    char* strin = new char[256];
    gets_s(strin, 256);
    char us = 'o'; // пользователя символ
    int count = 0; // счестчик
    char* str;
    while (str = strchr(strin, us)) {
        count++;
        strin = str+1;
    }
    cout << count;
}
//Task 6 Пользователь вводит строку. Определить ко-
//личество букв, количество цифр и количество остальных
//символов, присутствующих в строке.
//Вот сие назидание, как понимаю, у мено выполнено верно
void CheckSymbols() {
    char* strin = new char[256];
    gets_s(strin, 256);
    int digit = 0;
    int alpha = 0;
    int other = 0;
    for (int i = 0; i < strlen(strin); i++) {
        if (isdigit(strin[i]))
            digit++;
        else if (isalpha(strin[i]))
            alpha++;
        else
            other++;
    }
    cout << "Digits:" << digit << endl <<
        "Letters: " << alpha << endl <<
        "Other symbols: " << other;
}