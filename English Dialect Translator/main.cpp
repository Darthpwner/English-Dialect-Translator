//
//  main.cpp
//  English Dialect Translator
//
//  Created by Matthew Allen Lin on 9/25/15.
//  Copyright © 2015 MAL Software. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//New Yorker Dialect
string translateTextToNewYorkerDialect(string text);
bool checkPreviousCharacterIsVowel(int i, string text);

//Nor Cal Dialect
string translateTextToNorCalDialect(string text);
void insertHella(int i, string &text);

int main(int argc, const char * argv[]) {
    string text = "", translation = "";
    int dialect = -1;
    
    while(true) {
        //cout << "Select the dialect you want to translate\n1) New Yorker\n2) Nor Cal\n";
        //cin >> dialect;
        
        cout << "Enter the text you want to translate: ";
        getline(cin, text);
        
        //Translate the text
        //if(dialect == 1) {
        translation = translateTextToNewYorkerDialect(text);
        //} else if (dialect == 2) {
        //  translation = translateTextToNorCalDialect(text);
        //}
        cout << "The translated text is: " << translation << endl;
    }
    
    return 0;
}

//store 2
//put a into 2
//increment
//store 3
//put store 2 into 3
//increment

//cal -> cawl
//012 -> 0123

string translateTextToNewYorkerDialect(string text) {
    for(int i = 1; i < text.length(); i++) {
        if(text[i] == 'r' && checkPreviousCharacterIsVowel(i, text)) {
            text[i] = 'h';
        } else if(text[i] == 'o' && text[i + 1] != 'u') {
            text[i] = 'u';
        } else if(text[i] == 't' && text[i - 1] != 'i') {
            text[i] = 'd';
        } /*else if(text[i] == 'a') {
//            text.resize(text.length() + 1);
//            for(int j = i; j < text.length() + 1; j++) {
//                text[j + 1] = text[j];  //Move everything forward one
//            }
//            
//            text[i + 1] = 'w';
//            continue;
//        }*/
    }
    string translation = text;
    return translation;
}

string translateTextToNorCalDialect(string text) {
    int i = 0;
    while(i < text.length()) {
        if (text[i] == 'r' && text[i + 1] == 'e' && text[i + 2] == 'a' && text[i + 3] == 'l' && text[i + 4] == 'l' && text[i + 5] == 'y') {
            for(int j = i; j < text.length(); j++) {
                text[i] = text[i + 1];  //Move everything back one
            }
            insertHella(i, text);
            i += 6;
            
        } else if(text[i] == 'v' && text[i + 1] == 'i' && text[i + 2] == 'e' && text [i + 3] == 'w') {
            for(int j = i; j < text.length() + 1; j++) {
                text[i + 1] = text[i];  //Move everything forward one
            }
            text.resize(text.length() + 1);
            insertHella(i, text);
            i += 6;
        }
    }
    
    string translation = text;
    return translation;
}

void insertHella(int i, string &text) {
    text[i] = 'h';
    text[i + 1] = 'e';
    text[i + 2] = 'l';
    text[i + 3] = 'l';
    text[i + 4] = 'a';
}

bool checkPreviousCharacterIsVowel(int i, string text) {
    if (text[i - 1] == 'a' || text[i - 1] == 'e' || text[i - 1] == 'i' ||
        text[i - 1] == 'o' || text[i - 1] == 'u') {
        return true;
    }
    return false;
}
