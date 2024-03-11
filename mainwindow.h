#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "morsealphabetlogic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_cryptedTextEdit_textChanged();
    void on_save_triggered();
    void on_load_triggered();

private:
    Ui::MainWindow *ui;
    MorseAlphabetLogic *morsetranslator = new MorseAlphabetLogic();
};
#endif // MAINWINDOW_H
