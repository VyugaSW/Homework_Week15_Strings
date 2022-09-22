

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

void DeleteSymbol();
void DeleteAllSymbol();
void SymbolInString();
void SymbolPointreplacement();
void Symbolreplacement();
void CheckSymbols();
int main()
{
    //DeleteSymbol();        //Task 1
    //DeleteAllSymbol();     //Task 2
    //SymbolInString();        //Task 3
    //SymbolPointreplacement();    //Task 4
    //Symbolreplacement();        //Task 5
    //CheckSymbols();      //Task 6
}

//Task 1  Написать функцию, которая удаляет из строки
//символ с заданным номером.
void DeleteSymbol() {
    char* strin = new char[256]{ "Hello my lovest world of the worlds" };
    int delIndex = 3;
    for (int i = 0; i < strlen(strin); i++) {
        if (i == delIndex)
            strin[i] = ' ';
    }
    cout << strin;
}

//Task 2 Написать функцию, которая удаляет из строки
//все вхождения в нее заданного символа
void DeleteAllSymbol() {
    char* strin = new char[256]{ "Hello my lovest world of the worlds" };
    
    char element = 'l';
    int count = 0;
    for (int i = 0, j = 0; i < strlen(strin); i++) {
        if (strin[i] != element) { 
            count++;
        }
    }
    char* strin2 = new char[strlen(strin)-count];
    for (int i = 0, j = 0; i < strlen(strin); i++) {
        if (strin[i] != element) {
                strin2[j] = strin[i];
                j++;
        }
    }
    cout << strin2;
    delete[] strin2;
 }

//Task 3 Написать функцию, которая вставляет в строку
//в указанную позицию заданный символ.
void SymbolInString() {
    char* strin = new char[256]{ "Hello my lovest world of the worlds" };
    int index = 5;
    char litera = 'A';
    for (int i = 0; i < strlen(strin); i++) {
        if (i == index) 
            strin[i] = litera;
    }
    cout << strin;
}

//Task 4 Написать программу, которая заменяет все
//символы точки «.» в строке, введенной пользователем,
//на символы восклицательного знака «!».
void SymbolPointreplacement() {
    char* strin = new char[256];
    gets_s(strin,256);
    for (int i = 0; i < strlen(strin); i++) {
        if (strin[i] == '.')
            strin[i] = '!';
    }
    cout << strin;
}

//Task 5 Пользователь вводит строку символов и ис-
//комый символ, посчитать сколько раз он встречается
//в строке.
void Symbolreplacement() {
    char* strin = new char[256];
    gets_s(strin, 256);
    char us;
    cin >> us;
    int count = 0;
    for (int i = 0; i < strlen(strin); i++) {
        if (strin[i] == us)
            count++;
    }
    cout << count;
}
//Task 6 Пользователь вводит строку. Определить ко-
//личество букв, количество цифр и количество остальных
//символов, присутствующих в строке.
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
    cout << "Digit:" << digit << endl <<
        "Letters: " << alpha << endl <<
        "Other symbols: " << other;
}