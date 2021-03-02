#include "mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <qlabel.h>
MainWindow::MainWindow(INotesController& notesController, QWidget *parent)
: QMainWindow(parent)
{

setWindowTitle("App 1");
setGeometry(100, 100, 500, 500);
setMinimumSize(200, 200);

this->notesController = &notesController;
notes = new QListWidget(this);
notes->addItem(QString("Text"));
//notes->resize( 300, 300 );


//outputField = new QTextEdit("Some text here.\nIt is readonly.", this);
//outputField->setGeometry(10, 10, 180, 150);
//outputField->setReadOnly(true);

//inputField = new QLineEdit(this);
//inputField->setGeometry(10, 170, 140, 20);

QPushButton *okButton = new QPushButton("OK", this);
okButton->setGeometry(155, 170, 35, 20);
connect(okButton, SIGNAL(released()), this, SLOT(handleButton()));

calendar = new QCalendarWidget(this);
calendar->setGeometry(0, 300, 400, 200);
calendar->setMinimumDate(QDate(1900, 1, 1));
calendar->setMaximumDate(QDate(3000, 1, 1));
calendar->setGridVisible(true);



}
void MainWindow::handleButton() {
    outputField->setText(inputField->text());
    inputField->clear();
}
MainWindow::~MainWindow()
{
}
