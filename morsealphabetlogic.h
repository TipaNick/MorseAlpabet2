#ifndef MORSEALPHABETLOGIC_H
#define MORSEALPHABETLOGIC_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QChar>
#include <QRegExp>

#include <QDebug>

class MorseAlphabetLogic
{

public:
    MorseAlphabetLogic();
private:
    QHash<QChar, QString> toMorseMap;
    QHash<QString, QChar> fromMorseMap;

signals:

public slots:
    QString autoTranslate(QString message);

private slots:
    QString fromMorse(QString message);
    QString toMorse(QString message);
    bool isMorseMessage(QString message);
};

#endif // MORSEALPHABETLOGIC_H
