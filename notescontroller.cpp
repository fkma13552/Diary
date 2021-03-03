#include "notescontroller.h"

NotesController::NotesController(NoteDAO& noteDAO)
{
    this->noteDAO = &noteDAO;
    this->view = new MainWindow(*this);
}

Note &NotesController::AddNote(const string &title, const string &text)
{
    return  noteDAO->AddNote(title, text);
}

Note NotesController::GetNote(const int &id)
{
    return noteDAO->GetNote(id);
}

vector<Note> NotesController::GetAllNotes()
{
    return noteDAO->GetAllNotes();
}
