#include "mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <qlabel.h>
MainWindow::MainWindow(INotesController& notesController, QWidget *parent)
: QMainWindow(parent)
{

setWindowTitle("My diary");
setGeometry(100, 100, 400, 500);
setMinimumSize(200, 200);

this->notesController = &notesController;
notes = new QListWidget(this);
notes->addItem(QString("Here will be shown list of writings"));
notes->resize( 400, 100 );


outputField = new QTextEdit("Some text here (detailed writings).\nIt is readonly.", this);
outputField->setGeometry(10, 110, 190, 100);
outputField->setReadOnly(true);

inputField = new QLineEdit(this);
inputField->setGeometry(10, 220, 50, 20);

inputField = new QLineEdit(this);
inputField->setGeometry(10, 250, 240, 20);

QPushButton *okButton = new QPushButton("Add", this);
okButton->setGeometry(260, 250, 35, 20);
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
