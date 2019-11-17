#include <iostream>

#include <string>

using namespace std;

#include "3.h"

//Предметный указатель организован в виде линейного списка.
//Каждый компонент указателя содержит слово и номера страниц, на которых это слово встречается.
//Количество номеров страниц, относящихся к одному слову, — от одного до десяти.
//Написать программу, которая обеспечивает:
//начальное формирование предметного указателя;
//вывод предметного указателя;
//вывод номеров страниц для заданного слова.
//Программа должна обеспечивать диалог с помощью меню и контроль ошибок ввода.
int main() {
    struct sentence *pv;
    struct Say say;
    sentence *pbeg = nullptr;
    sentence *pend = nullptr;
    char word[31];
    int k;
    int page[10];
    string function;
    while (1) {
        cout << "Choose function: add, delete, show_all, show_pages or exit" << endl;
        cin >> function;

        if (function == "add" || function == "a") {
            if (pbeg == nullptr)
                pbeg = pend = first();
            else
                add(&pbeg, &pend);
        }

        if (function == "delete" || function == "d") {
            cout << "Write word for delete:" << endl;
            cin.ignore();
            cin.getline(word, 31);
            if (Delete(&pbeg, &pend, word) == 0)
                cout << "Not found or Error word" << endl;
            else
                cout << "OK" << endl;
        }

        if (function == "show_all" || function == "sa") {
            sentence *pv = pbeg;
            while (pv) {
                cout << pv->say.word << " ";
                for (int i = 0; i < pv->say.k; i++)
                    cout << pv->say.page[i] << " ";
                pv = pv->next;
            }
            cout << endl << "It's all" << endl;
        }

        if (function == "show_pages" || function == "sp") {
            cout << "Write word for show" << endl;
            cin.ignore();
            cin.getline(word, 31);
            if (check(pbeg, word) == 1) {
                if (sentence *pkey = find(pbeg, word)) {
                    for (int i = 0; i < pkey->say.k; i++)
                        cout << pkey->say.page[i] << " " << endl;
                }
            } else
                cout << "Not found or Error word" << endl;
        }
        if (function == "exit" || function == "q")
            return 0;
    }
}