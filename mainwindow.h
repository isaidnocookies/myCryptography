#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_encryptButton_clicked();

    //void on_shiftSlider_sliderReleased();

    void on_shiftSlider_sliderMoved(int position);

    void on_cryptDropDown_currentTextChanged(const QString &arg1);

    void updateMyUI();

    void caesarCipher(int encryptDecrypt);

    void on_decryptButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
