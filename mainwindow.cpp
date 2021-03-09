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
    setWindowTitle("Super-puper schodennyk");
    setGeometry(100, 100, 400, 500);
    setMinimumSize(200, 200);

    int paddingX = 10;
    int paddingY = 10;
    this->notesController = &notesController;
    notes = new QListWidget(this);
    notes->addItem(QString("Here will be shown list of writings"));
    notes->setGeometry(paddingX, paddingY, 380, 100);
    //notes->resize( 400, 100 );
    refreshList();
    connect(notes, SIGNAL(itemSelectionChanged()), this, SLOT(resfrshNoteTextField()));

    outputField = new QTextEdit("Your text here", this);
    outputField->setGeometry(paddingX, paddingY + 110, 190, 100);
    outputField->setReadOnly(true);

    int titleLine = paddingY + 230;
    titleLb = new QLineEdit(this);
    titleLb->setGeometry(paddingX, titleLine, 40, 20);
    titleLb->setReadOnly(true);
    titleLb->setText("Title: ");

    inputFieldNoteTitle = new QLineEdit(this);
    inputFieldNoteTitle->setGeometry(paddingX + 50, titleLine, 100, 20);

    int textLine = paddingY + 260;
    textLb = new QLineEdit(this);
    textLb->setGeometry(paddingX, textLine, 40, 20);
    textLb->setReadOnly(true);
    textLb->setText("Note: ");

    inputFieldNoteText = new QTextEdit(this);
    inputFieldNoteText->setGeometry(paddingX + 50, textLine, 240, 40);

    QPushButton *okButton = new QPushButton("Add", this);
    okButton->setGeometry(paddingX + 300, textLine, 35, 20);
    connect(okButton, SIGNAL(released()), this, SLOT(handleButton()));

}
void MainWindow::handleButton() {
    //outputField->setText(inputField->text());
    notesController->AddNote(
                inputFieldNoteTitle->text().toUtf8().constData(),
                inputFieldNoteText->toPlainText().toUtf8().constData());
                //inputFieldNoteText->text().toUtf8().constData());
    //inputField->clear();
    inputFieldNoteTitle->clear();
    inputFieldNoteText->clear();
    refreshList();
}

void MainWindow::refreshList() {
    notes->clear();
    std::vector<Note> notesList = notesController->GetAllNotes();
    QStringList listItems = QStringList ();
   // std::vector<Note>::iterator iter = notesList.begin();
    for(auto note: notesList) {
        listItems << QString::fromStdString(note.getTitle());
    }
    notes->addItems(listItems);
}

void MainWindow::resfrshNoteTextField() {
    int index = notes->currentRow();
    Note note = notesController->GetNote(index);
    outputField->setText(QString::fromStdString(note.getText()));
}

MainWindow::~MainWindow()
{
}
