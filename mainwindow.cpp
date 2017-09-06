#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "caesarcipher.h"
#include <QString>
#include <iostream>

int currentCipher;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->cryptDropDown->setCurrentIndex(0);
    currentCipher = ui->cryptDropDown->currentIndex();

    MainWindow::updateMyUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateMyUI() {
    switch(currentCipher) {
    case 0:
        //get ui set for Caesar Cipher (hide the key input)
        ui->keyInputField->setEnabled(false);
        ui->shiftSlider->setEnabled(true);
        break;
    case 1:
        ui->keyInputField->setEnabled(true);
        ui->shiftSlider->setEnabled(false);
        break;
    }
}

void MainWindow::on_encryptButton_clicked()
{
    switch(currentCipher) {
    case 0:
        MainWindow::caesarCipher(0);
        break;
    default:
        break;
    }
}

void MainWindow::on_decryptButton_clicked()
{
    switch(currentCipher) {
    case 0:
        MainWindow::caesarCipher(1);
        break;
    default:
        break;
    }
}

//void MainWindow::on_shiftSlider_sliderReleased()
//{
//    int newValue = ui->shiftSlider->value();
//    ui->sliderValueLabel->setText(QString::number(newValue));
//}

void MainWindow::on_shiftSlider_sliderMoved(int position)
{
    int newValue = position; //ui->shiftSlider->value();
    ui->sliderValueLabel->setText(QString::number(newValue));
}

void MainWindow::on_cryptDropDown_currentTextChanged(const QString &arg1)
{

    ui->label_cryptType->setText(arg1.toUtf8().constData());
    currentCipher = ui->cryptDropDown->currentIndex();
    MainWindow::updateMyUI();

}

void MainWindow::caesarCipher(int encryptDecrpyt) {
    int shiftAmount = ui->shiftSlider->value();
    if (encryptDecrpyt == 0) {
        // encrypt the text in the input field
        std::string stringToBeEncrypted = ui->inputField->toPlainText().toStdString();
        CaesarCipher myCipher(stringToBeEncrypted, shiftAmount);
        ui->outputField->setText(QString::fromStdString(myCipher.getEncryptedString()));
    } else {
        // encrypt the text in the input field
        std::string stringToBeDecrypted = ui->inputField->toPlainText().toStdString();
        CaesarCipher myCipher(stringToBeDecrypted, shiftAmount);
        ui->outputField->setText(QString::fromStdString(myCipher.getDecryptedString()));
    }

}
