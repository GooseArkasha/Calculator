#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui-> pushButton_1, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_2, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_3, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_4, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_5, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_6, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_7, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_8, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_9, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_0, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_div, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_mul, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_plus, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui-> pushButton_minus, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui->pushButton_fbracket, SIGNAL(clicked()), this, SLOT(addSymbol()));
    connect(ui->pushButton_bbracket, SIGNAL(clicked()), this, SLOT(addSymbol()));

    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(clearLine()));

    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(on_pushButton_equal_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSymbol()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;

    if(ui->result_show->text() ==  "Error")
    {
        ui->result_show->setText("");
    }

    new_label = ui->result_show->text() + button->text();
    ui->result_show->setText(new_label);
}

void MainWindow::clearLine()
{
    ui->result_show->setText("");
}

void MainWindow::on_pushButton_equal_clicked()
{
    QString expression;
    expression = ui->result_show->text();
    if(!check(expression))
        ui->result_show->setText("Error");
    expression = QString::number(get_result(expression), 'g', 20);
    ui->result_show->setText(expression);
}

