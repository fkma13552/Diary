#include "mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <qlabel.h>
#include <QList>
#include <QVector>
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
refreshList();
connect(notes, SIGNAL(itemSelectionChanged()), this, SLOT(resfrshNoteTextField()));

outputField = new QTextEdit("Some text here (detailed writings).\nIt is readonly.", this);
outputField->setGeometry(10, 110, 190, 100);
outputField->setReadOnly(true);

inputFieldNoteName = new QLineEdit(this);
inputFieldNoteName->setGeometry(10, 220, 50, 20);

inputFieldNoteText = new QLineEdit(this);
inputFieldNoteText->setGeometry(10, 250, 240, 20);

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
    //outputField->setText(inputField->text());
    notesController->AddNote(
                inputFieldNoteName->text().toUtf8().constData(),
                inputFieldNoteText->text().toUtf8().constData());
    //inputField->clear();
    inputFieldNoteName->clear();
    inputFieldNoteText->clear();
    refreshList();
}

void MainWindow::refreshList() {
    notes->clear();
    std::vector<Note> notesList = notesController->GetAllNotes();
    QStringList listItems = QStringList ();
    for(auto note: notesList) {
        listItems << QString::fromStdString(note.getTitle());
    }
    notes->addItems(listItems);
}

void MainWindow::resfrshNoteTextField() {
    int index = notes->currentRow();
    Note& note = notesController->GetNote(index);
    outputField->setText(QString::fromStdString(note.getText()));
}

MainWindow::~MainWindow()
{
}
