#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Slots.h"
#include <vector>
#include "Player.h"
#include "sicBo.h"
#include "Roulette.h"
#include <QPropertyAnimation>
#include <QTimer>
#include <ctime>
#include <cstdlib>





Player* player;
Slots* slot;
SicBo* sicbo;
Roulette* roulette;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::srand(std::time(nullptr));
    connect(ui->spinButton, &QPushButton::clicked, this, &MainWindow::on_spinButton_clicked);

    connect(ui->rouletteSpin, &QPushButton::clicked,
            this, &MainWindow::on_rouletteSpin_clicked);

    player = new Player("Hi", 1000);
    roulette = new Roulette(player);
    sicbo = new SicBo(player);
    slot = new Slots(player);

     ui -> initialBalanceLabel -> setText("$" + QString::number(player -> getBalance()));


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkGameOver()
{
    if (player->getBalance() <= 0) {
        ui->stackedWidget->setCurrentWidget(ui->gameOverPage);
    }
}

void MainWindow::on_pushButton_clicked() // Slots
{
    ui->stackedWidget->setCurrentIndex(1);
    ui -> playerLabel_2 -> setText("$" + QString::number(player -> getBalance()));
}

void MainWindow::on_pushButton_2_clicked() // SicBo
{
    ui->stackedWidget->setCurrentIndex(2);
    ui -> playerLabel_3-> setText("$" + QString::number(player -> getBalance()));
}

void MainWindow::on_pushButton_3_clicked() // Roulette
{
    ui->stackedWidget->setCurrentIndex(3);
    ui -> playerLabel_4 -> setText("$" + QString::number(player -> getBalance()));
}

void MainWindow::on_pushButton_4_clicked() // Blackjack
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_backButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
    ui -> initialBalanceLabel -> setText("$" + QString::number(player -> getBalance()));
}


void MainWindow::on_backButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui -> initialBalanceLabel -> setText("$" + QString::number(player -> getBalance()));
}


void MainWindow::on_backButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui -> initialBalanceLabel -> setText("$" + QString::number(player -> getBalance()));
}


void MainWindow::on_backButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui -> initialBalanceLabel -> setText("$" + QString::number(player -> getBalance()));
}






void MainWindow::on_spinButton_clicked()
{  ui -> playerLabel_2 -> setText("$" + QString::number(player -> getBalance()));

    /* QPropertyAnimation *animation = new QPropertyAnimation(ui->spinButton, "geometry");

    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->setDuration(100); // 1 second

    animation->setStartValue(QRect(50, 50, 120, 40));   // starting position
    animation->setEndValue(QRect(250, 50, 120, 40));    // ending position

    QPropertyAnimation *anim = new QPropertyAnimation(ui->resultLabel, "pos");

    anim->setDuration(800);
    anim->setStartValue(QPoint(100, 0));
    anim->setEndValue(QPoint(100, 100));
    anim->setEasingCurve(QEasingCurve::OutBounce);

    anim->start();



    animation->start();*/

    double bet = ui->betInput->text().toDouble();

// withdraw bet first
    player->withdraw(bet);
    QString text = ui->betInput->text();

    if (text.isEmpty()) {
        ui->statusLabel->setText("Enter a bet!");
        return;
    }

    if (bet <= 0) {
        ui->statusLabel->setText("Invalid bet!");
        return;
    }

    // spin
    std::vector<int> result = slot->spin();

    std::vector<QString> symbols = { "Cherry 🍒", "Lemon 🍋", "Bell 🔔", "Seven 7️⃣" };

    if (result.size() < 3) {
        ui->statusLabel->setText("Error: spin failed");
        return;
    }

    // display results
    QString display1 = symbols[result[0]] + " | ";
    QString display2 = symbols[result[1]] + " | ";
    QString display3 = symbols[result[2]];



    ui->resultLabel->setText("Spinning slot wheel...");


    QTimer::singleShot(500, this, [=]() {
        ui-> resultLabel -> setText(display1);


        QTimer::singleShot(1000, this, [=]() {
            ui-> resultLabel -> setText(display1 + display2);

            QTimer::singleShot(1500, this, [=]() {
                ui-> resultLabel -> setText(display1 + display2 + display3);

            int winCount = slot->evaluate(result);

            // apply result
            std::string slotOutcome = slot->applyResult(bet, winCount);

            ui->statusLabel->setText(QString::fromStdString(slotOutcome));

            // update balance
            ui->balanceLabel->setText("Balance: $" + QString::number(player->getBalance()));

            });

    });

});

ui -> playerLabel_2 -> setText("$" + QString::number(player -> getBalance()));

checkGameOver();

}


void MainWindow::on_diceButton_clicked()
{

    ui -> playerLabel_3 -> setText("$" + QString::number(player -> getBalance()));



    double bet = ui->getDiceInput->text().toDouble();
    std::vector <int> result;
    // withdraw bet first
    player->withdraw(bet);


    QString text = ui->getDiceInput->text();

    if (text.isEmpty()) {
        ui->diceStatusLabel->setText("Enter a bet!");
        return;
    }

    if (bet <= 0) {
        ui->diceStatusLabel->setText("Invalid bet!");
        return;
    }

    result = sicbo -> getDice();
    if (result.size() < 3 || result.size() > 3) {
        ui->diceStatusLabel->setText("Dice roll failed!");
        return;
    }

    int diceNumber = sicbo -> getNumber();
    int winCount = sicbo -> evaulate(result, diceNumber);

    ui->diceVerdict->setText("Rolling the dice...");
    QTimer::singleShot(500, this, [=]() {
     ui -> diceLabel -> setText(QString::number(result[0]));

        QTimer::singleShot(1000, this, [=]() {
          ui -> diceLabel -> setText(QString::number(result[0]) + " | " + QString::number(result[1]));




            QTimer::singleShot(1500, this, [=]() {
              ui -> diceLabel -> setText(QString::number(result[0]) + " | " + QString::number(result[1]) + " | " + QString::number(result[2]));

              QPropertyAnimation* anim = new QPropertyAnimation(ui->diceLabel, "geometry");

              anim->setDuration(600);

              // current position
              QRect startRect = ui->diceLabel->geometry();

              // slightly bigger for "pop" effect
              QRect endRect = QRect(
                  startRect.x() - 10,
                  startRect.y() - 10,
                  startRect.width() + 20,
                  startRect.height() + 20
                  );

              anim->setStartValue(startRect);
              anim->setEndValue(endRect);






                // update balance
                ui->balanceLabel->setText("Balance: $" + QString::number(player->getBalance()));


                ui -> getDiceLabel -> setText("Your number: " + QString::number(diceNumber));

                ui -> diceMatchLabel -> setText("Matches: " + QString::number(winCount));

                std::string diceOutcome = sicbo -> applyResult(bet, winCount);

                ui -> diceVerdict -> setText(QString::fromStdString(diceOutcome));

                ui -> diceResult -> setText("Balance: $" + QString::number(player -> getBalance()));

                ui -> playerLabel_3 -> setText("$" + QString::number(player -> getBalance()));

            });

        });

    });

    /*ui->diceLabel -> setText("Rolling dice: ");
    QTimer::singleShot(500, this, [=]() {
        ui -> diceLabel -> setText(QString::number(result[0]));
        QTimer::singleShot(1000, this, [=]() {
            ui -> diceLabel -> setText(QString::number(result[0]) + " | " + QString::number(result[1]));
            QTimer::singleShot(1500, this, [=]() {
        });
            ui -> diceLabel -> setText(QString::number(result[0]) + " | " + QString::number(result[1]) + " | " + QString::number(result[2]));
            });

    });


    // display results
    QString display1 = [result[0]] + " | ";
    QString display2 = [result[1]] + " | ";
    QString display3 = [result[2]];
    QString displayDice = QString::number(result[0]) + " " + QString::number(result[1]) + " " + QString::number(result[2]);
    ui -> diceLabel -> setText("Rolling dice: ");
    ui -> diceLabel -> setText("Dices rolled: " + displayDice);*/

    checkGameOver();

}

void MainWindow::on_rouletteSpin_clicked()
{
    ui -> playerLabel_4 -> setText("$" + QString::number(player -> getBalance()));

    QApplication::processEvents();

    QString betText = ui->rouletteBet->text();

    if (betText.isEmpty()) {
        ui->rouletteStatus->setText("Enter a bet!");
        return;
    }

    double bet = betText.toDouble();

    if (bet <= 0) {
        ui->rouletteStatus->setText("Invalid bet!");
        return;
    }

    QString numText = ui->rouletteNum->text();

    if (numText.isEmpty()) {
        ui->rouletteStatus->setText("Enter a number!");
        return;
    }

    int chosenNumber = numText.toInt();

    if (chosenNumber < 0 || chosenNumber > 36) {
        ui->rouletteStatus->setText("Invalid number!");
        return;
    }

    ui->spinLabel->setText("Spinning roulette wheel...");



    player->withdraw(bet);

    int winningNum = roulette->spinWheel();

    ui->rouletteResults->setText(
        "Your number: " + numText +
        "\nWinning number: " + QString::number(winningNum)
        );


    QPropertyAnimation* anim = new QPropertyAnimation(ui->rouletteResults, "geometry");

    anim->setDuration(600);

    // current position
    QRect startRect = ui->rouletteResults->geometry();

    // slightly bigger for "pop" effect
    QRect endRect = QRect(
        startRect.x() - 10,
        startRect.y() - 10,
        startRect.width() + 20,
        startRect.height() + 20
        );

    anim->setStartValue(startRect);
    anim->setEndValue(endRect);

    // 🔥 THIS is your elastic effect
    anim->setEasingCurve(QEasingCurve::OutElastic);

    anim->start();


    std::string outcome = roulette->applyResult(bet, chosenNumber, winningNum);

    ui->rouletteVerdict->setText(
        QString::fromStdString(outcome) +
        "\nBalance: $" + QString::number(player->getBalance())
        );

    ui -> playerLabel_4 -> setText("$" + QString::number(player -> getBalance()));

    checkGameOver();

}

 



void MainWindow::on_restartButton_clicked()
{
    player -> deposit(1000);
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
