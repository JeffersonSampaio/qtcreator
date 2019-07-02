
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "viewdefinicaorecuperanotafiscal.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ViewDefinicaoRecuperaNotaFiscal *Form = new ViewDefinicaoRecuperaNotaFiscal();
    Form->show();
}
