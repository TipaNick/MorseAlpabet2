#include "morsealphabetlogic.h"

MorseAlphabetLogic::MorseAlphabetLogic()
{
    //Init toMorseMap
    toMorseMap['A'] = ".-";
    toMorseMap['B'] = "-...";
    toMorseMap['C'] = "-.-.";
    toMorseMap['D'] = "-..";
    toMorseMap['E'] = ".";
    toMorseMap['F'] = "..-.";
    toMorseMap['G'] = "--.";
    toMorseMap['H'] = "....";
    toMorseMap['I'] = "..";
    toMorseMap['J'] = ".---";
    toMorseMap['K'] = "-.-";
    toMorseMap['L'] = ".-..";
    toMorseMap['M'] = "--";
    toMorseMap['N'] = "-.";
    toMorseMap['O'] = "---";
    toMorseMap['P'] = ".--.";
    toMorseMap['Q'] = "--.-";
    toMorseMap['R'] = ".-.";
    toMorseMap['S'] = "...";
    toMorseMap['T'] = "-";
    toMorseMap['U'] = "..-";
    toMorseMap['V'] = "...-";
    toMorseMap['W'] = ".--";
    toMorseMap['X'] = "-..-";
    toMorseMap['Y'] = "-.--";
    toMorseMap['Z'] = "--..";
    toMorseMap['.'] = ".-.-.-";
    toMorseMap[','] = "--..--";
    toMorseMap['?'] = "..--..";
    toMorseMap['`'] = ".----.";
    toMorseMap['!'] = "-.-.--";
    toMorseMap['/'] = "-..-.";
    toMorseMap['('] = "-.--.";
    toMorseMap[')'] = "-.--.-";
    toMorseMap['&'] = ".-...";
    toMorseMap[':'] = "---...";
    toMorseMap[';'] = "-.-.-.";
    toMorseMap['='] = "-...-";
    toMorseMap['+'] = ".-.-.";
    toMorseMap['-'] = "-....-";
    toMorseMap['_'] = "..--.-";
    toMorseMap['"'] = ".-..-.";
    toMorseMap['$'] = "...-..-";
    toMorseMap['@'] = ".--.-.";

    //Init fromMorseMap
    fromMorseMap[".-"] = 'A';
    fromMorseMap["-..."] = 'B';
    fromMorseMap["-.-."] = 'C';
    fromMorseMap["-.."] = 'D';
    fromMorseMap["."] = 'E';
    fromMorseMap["..-."] = 'F';
    fromMorseMap["--."] = 'G';
    fromMorseMap["...."] = 'H';
    fromMorseMap[".."] = 'I';
    fromMorseMap[".---"] = 'J';
    fromMorseMap["-.-"] = 'K';
    fromMorseMap[".-.."] = 'L';
    fromMorseMap["--"] = 'M';
    fromMorseMap["-."] = 'N';
    fromMorseMap["---"] = 'O';
    fromMorseMap[".--."] = 'P';
    fromMorseMap["--.-"] = 'Q';
    fromMorseMap[".-."] = 'R';
    fromMorseMap["..."] = 'S';
    fromMorseMap["-"] = 'T';
    fromMorseMap["..-"] = 'U';
    fromMorseMap["...-"] = 'V';
    fromMorseMap[".--"] = 'W';
    fromMorseMap["-..-"] = 'X';
    fromMorseMap["-.--"] = 'Y';
    fromMorseMap["--.."] = 'Z';
    fromMorseMap[".-.-.-"] = '.';
    fromMorseMap["--..--"] = ',';
    fromMorseMap["..--.."] = '?';
    fromMorseMap[".----."] = '`';
    fromMorseMap["-.-.--"] = '!';
    fromMorseMap["-..-."] = '/';
    fromMorseMap["-.--."] = '(';
    fromMorseMap["-.--.-"] = ')';
    fromMorseMap[".-..."] = '&';
    fromMorseMap["---..."] = ':';
    fromMorseMap["-.-.-."] = ';';
    fromMorseMap["-...-"] = '=';
    fromMorseMap[".-.-."] = '+';
    fromMorseMap["-....-"] = '-';
    fromMorseMap["..--.-"] = '_';
    fromMorseMap[".-..-."] = '"';
    fromMorseMap["...-..-"] = '$';
    fromMorseMap[".--.-."] = '@';
}

bool MorseAlphabetLogic::isMorseMessage(QString message){
    for(int i = 0; i < message.size(); i++){
        if (message.at(i) != '.' && message.at(i) != '-' && message.at(i) != ' ') {
            return false;
        }
    }
    return true;
}

QString MorseAlphabetLogic::autoTranslate(QString message){
    if (isMorseMessage(message)) {
        return fromMorse(message);
    }
    return toMorse(message);
}

//    Проверяем все символы строки
//    Если не пробел, то записываем в символ
//    Если пробел, преобразуем символ в букву и записываем в результат
//    Если за пробелом следует пробел, записываем пробел в результат
QString MorseAlphabetLogic::fromMorse(QString message){
    QString result;
    QString symbol;
    for(int i = 0; i < message.size(); i++){
        if(message.at(i) == ' '){
            result += fromMorseMap[symbol];
            symbol = "";
            if(i!=message.size()-1){
                if(message.at(i+1) == ' '){
                    i+=1;
                    result += ' ';
                }
            }
        } else {
            symbol += message.at(i);
        }
    }
    if(symbol != "")
        result += fromMorseMap[symbol];
    return result;
}

QString MorseAlphabetLogic::toMorse(QString message) {
    QString result;
    for (int i = 0; i < message.size(); i++){
        if(message.toUpper().at(i) != ' '){
            result += toMorseMap[message.toUpper().at(i)] + " ";
        } else {
            result += "  ";
        }
    }
    return result;
}
