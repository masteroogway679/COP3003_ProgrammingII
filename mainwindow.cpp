#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Slots.h"
#include <vector>
#include "Player.h"
#include "sicBo.h"
#include "Roulette.h"
#include "Blackjack.h"

Player* player;
Slots* slot;
SicBo* sicbo;
Roulette* roulette;
MiniBlackjack blackjack;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->spinButton, &QPushButton::clicked, this, &MainWindow::on_spinButton_clicked);

    player = new Player("Max", 1000);
    slot = new Slots(player);
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
    QString display = symbols[result[0]] + " | " +
                      symbols[result[1]] + " | " +
                      symbols[result[2]];

    ui->resultLabel->setText(display);

    // evaluate result
    int winCount = slot->evaluate(result);

    // apply result
    std::string slotOutcome = slot->applyResult(bet, winCount);

    ui->statusLabel->setText(QString::fromStdString(slotOutcome));

    // update balance
    ui->balanceLabel->setText("Balance: $" + QString::number(player->getBalance()));}






void MainWindow::on_diceButton_clicked()
{
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
    if (result.size() < 3) return;

    int diceNumber = sicbo -> getNumber();
    int winCount = sicbo -> evaulate(result, diceNumber);
    QString displayDice = QString::number(result[0]) + " " + QString::number(result[1]) + " " + QString::number(result[2]);
    ui -> diceLabel -> setText("Dices rolled: " + displayDice);

    ui -> getDiceLabel -> setText("Your number: " + QString::number(diceNumber));

    ui -> diceMatchLabel -> setText("Matches: " + QString::number(winCount));

    std::string diceOutcome = sicbo -> applyResult(bet, winCount);

    ui -> diceVerdict -> setText(QString::fromStdString(diceOutcome));

    ui -> diceResult -> setText("Balance: " + QString::number(player -> getBalance()));

}

void MainWindow::on_rouletteSpin_clicked()
{
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

    // ✅ NOW withdraw
    player->withdraw(bet);

    int winningNum = roulette->spinWheel();

    ui->rouletteResults->setText(
        "Your number: " + numText +
        "\nWinning number: " + QString::number(winningNum)
        );

    std::string outcome = roulette->applyResult(bet, chosenNumber);

    ui->rouletteVerdict->setText(
        QString::fromStdString(outcome) +
        "\nBalance: $" + QString::number(player->getBalance())
        );
}

void MainWindow::on_dealButton_clicked()
{
    double bet = ui->bjBetInput->text().toDouble();

    if (bet <= 0) {
        ui->bjResultLabel->setText("Enter valid bet");
        return;
    }

    blackjack.startGame(bet);

    ui->bjPlayerLabel->setText("Player: " + QString::number(blackjack.getPlayerScore()));
    ui->bjDealerLabel->setText("Dealer: ?");
    ui->bjResultLabel->setText("Game started");
}

void MainWindow::on_hitButton_clicked()
{
    blackjack.hit();

    ui->bjPlayerLabel->setText("Player: " + QString::number(blackjack.getPlayerScore()));

    if (blackjack.isGameOver()) {
        ui->bjResultLabel->setText(QString::fromStdString(blackjack.getResult()));
    }
}

void MainWindow::on_standButton_clicked()
{
    blackjack.stand();

    ui->bjDealerLabel->setText("Dealer: " + QString::number(blackjack.getDealerScore()));
    ui->bjResultLabel->setText(QString::fromStdString(blackjack.getResult()));
}

