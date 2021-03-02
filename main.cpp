#include "mainwindow.h"
#include "notescontroller.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NoteDAO noteDAO;
    INotesController* notesController = new NotesController(noteDAO);
    MainWindow* mw = new MainWindow(*notesController);
    mw->show();
//    QLabel *label = new QLabel("Diary");
//    label->resize(400, 400);
//    label->show();
    return a.exec();
}
