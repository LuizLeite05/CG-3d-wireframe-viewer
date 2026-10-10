#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "displayfile.h"

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
    // Nomes ajustados para coincidir com os botões da interface
    void on_btnTranslate_clicked();
    void on_btnAngle_clicked();
    void on_listObejcts_currentRowChanged(int currentRow);
    void on_btnScale_clicked();

private:
    Ui::MainWindow *ui;
    DisplayFile *displayFile;

    // Método auxiliar
    void updateObjectList();
};
#endif // MAINWINDOW_H