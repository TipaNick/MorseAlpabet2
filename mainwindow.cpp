#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cryptedTextEdit_textChanged()
{
    ui->decryptedTextEdit->setPlainText(morsetranslator->autoTranslate(ui->cryptedTextEdit->toPlainText()));
}


void MainWindow::on_save_triggered()
{
    QString path = QFileDialog::getSaveFileName(0,"Сохранить файл", "", "*.txt");
    if(!path.isEmpty()){
        QFile file(path);
        if(file.isOpen()){
            return;
        }
        file.open(QIODevice::WriteOnly);
        file.write("Crypted text: ");
        file.write(ui->cryptedTextEdit->toPlainText().toUtf8());
        file.write("\nDecrypted text: ");
        file.write(ui->decryptedTextEdit->toPlainText().toUtf8());
        file.close();

    }
}


void MainWindow::on_load_triggered()
{
    QString path = QFileDialog::getOpenFileName(0, "Открыть файл","", "*.txt");
    if(!path.isEmpty()){
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray text = file.readAll();
        file.close();
        ui->cryptedTextEdit->setPlainText(text);
    }
}

