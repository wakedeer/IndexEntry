#ifndef str_H
#define str_H

#include <iostream>
#include <cstring>
#include <string>

class Say {
public:
    char word[31];
    int k;
    int page[10];
};

class sentence {
public:
    Say say;
    sentence *next;
    sentence *prev;
};

sentence *find(sentence *const pbeg, char *word) {
    sentence *pv = pbeg;
    while (pv != NULL) {
        if (strcmp(pv->say.word, word) == 0)
            break;
        pv = pv->next;
    }
    return pv;
}

bool check(sentence *const pbeg, char *word) {
    sentence *pv = pbeg;
    while (pv != nullptr) {
        if (strcmp(pv->say.word, word) == 0)
            return true;
        pv = pv->next;
    }
    return false;
}

sentence *first() {
    Say say;
    cout << "Write first word:" << endl;
    cin.ignore();
    cin.getline(say.word, 31);
    for (int i = 0; i < strlen(say.word); i++) {
        if (isalpha(say.word[i]) == 0) {
            cout << "Error word" << endl;
            return 0;
        }
    }
    cout << "Write quantity pages: " << endl;
    cin >> say.k;
    if (say.k > 0 && say.k < 10) {
        for (int i = 0; i < say.k; i++) {
            cout << "page" << i + 1 << " ";
            cin >> say.page[i];
            if (say.page[i] < 0 || isalpha(say.page[i]) != 0) {
                cout << "Error page" << endl;
                system("pause");
                return 0;
            }
        }
    } else {
        cout << "Error quantity pages" << endl;
        system("pause");
        return 0;
    }
    sentence *pv = new sentence;
    pv->say = say;
    pv->next = pv->prev = nullptr;
    return pv;
}

sentence *add(sentence **pbeg, sentence **pend) {
    Say say;
    cout << "Write word:" << endl;
    cin.ignore();
    cin.getline(say.word, 31);
    for (int i = 0; i < strlen(say.word); i++) {
        if (isalpha(say.word[i]) == 0) {
            cout << "Error word";
            return 0;
        }
    }
    if (check(*pbeg, say.word))
        cout << "This word has addoded yet";
    else {
        cout << "Write quantity pages: " << endl;
        cin >> say.k;
        if (say.k > 0 && say.k < 10) {
            for (int i = 0; i < say.k; i++) {
                cout << "page" << i + 1 << " ";
                cin >> say.page[i];
                if (say.page[i] <= 0) {
                    cout << "Error page" << endl;
                    return 0;
                }
            }
        } else {
            cout << "Error quantity pages" << endl;
            return 0;
        }
        sentence *pv = new sentence;
        pv->say = say;
        pv->next = nullptr;
        pv->prev = *pend;
        (*pend)->next = pv;
        *pend = pv;
        return pv;
    }
}

bool Delete(sentence **pbeg, sentence **pend, char key[31]) {
    if (sentence *pkey = find(*pbeg, key)) {
        if (pkey == *pbeg) {
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = nullptr;
        } else if (pkey == *pend) {
            *pend = (*pend)->prev;
            (*pend)->next = nullptr;
        } else {
            (pkey->prev)->next = pkey->next;
            (pkey->next)->prev = pkey->prev;
        }
        delete pkey;
        return true;
    }
    return false;
}

#endif