#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_spinButton_clicked();

    void on_backButton_clicked();

    void on_backButton_4_clicked();

    void on_backButton_3_clicked();

    void on_backButton_2_clicked();

    void on_diceButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
