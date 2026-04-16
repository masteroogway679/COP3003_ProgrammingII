#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->spinButton, &QPushButton::clicked, this, &MainWindow::on_spinButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // Slots
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked() // SicBo
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_3_clicked() // Roulette
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_4_clicked() // Blackjack
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_backButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_backButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_backButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_backButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
 




void MainWindow::on_spinButton_clicked()
{
     int result = rand() % 3;

    if (result == 0)
        ui->slotResult->setText("Cherry 🍒");
    else if (result == 1)
        ui->slotResult_2->setText("Seven 7️⃣");
    else
        ui->slotResult_3->setText("Bar 🔲");

}





void MainWindow::on_diceButton_clicked()
{

    std::vector <int> diceCount(3);

    for (int i = 0; i < 3; i++) {
        diceCount.push_back((rand() % 6) + 1);
    }

    for (int i = 0; i < 3; i++) {
        ui->diceResult->setNum(diceCount[i]);
    }

}
