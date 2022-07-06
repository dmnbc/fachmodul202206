#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>
#include "database.h"

QSqlDatabase Database::db;
QStandardItemModel* model = new QStandardItemModel() ;

#define debug qDebug()<<__FILE__<<":"<<__LINE__

bool Database::connected= false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{  debug<<"ui setup";
    ui->setupUi(this);

    ui->resultView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // Versuch die Datenbank anzusprechen
    debug<<"Try to connect";

    // Datenbank objekt erstellen und verbinden
    Database db("QMYSQL");debug<<"db Instanz ";


    if(!Database::connected)
    // nicht verbunden -> Fehlermeldung
    {   debug<<"Database::connected is "<<Database::connected;

        ui->radioButton->setStyleSheet("color:red");
        ui->radioButton->setText("not connected");
        ui->radioButton->setChecked(false);
    }
    else
    // Verbindungsanzeige aktuallisieren
    {   debug<<"Database::connected is "<<Database::connected;
        ui->radioButton->setStyleSheet("color:green");
        ui->radioButton->setText("connected");
        ui->radioButton->setChecked(true);
    }

}


void MainWindow::on_executeSQL_clicked()
{
    model->clear();
    debug<<"SQL -> "<<ui->sqlCommand->toPlainText();
    int row = 0;
    int col = 0;
    for(auto line : Database::results(ui->sqlCommand->toPlainText()))
    {debug<<line;
    // update model -> new view
      for(auto colValue : line)
       { QStandardItem* item = new QStandardItem(colValue);
            model->setItem(row,col++,item);}
      col=0;
      row++;
      debug<<"Das Modell hat "<<row<<" Zeilen ";
    }

}

