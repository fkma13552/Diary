#include "notedao.h"

#include <stdexcept>

NoteDAO::NoteDAO()
{
    AddNote("First Note", "Some text 1");
    AddNote("Second Note", "Some text 2");
    AddNote("Third Note", "Some text 3");
    AddNote("Fourth Note", "Some text 4");
}
NoteDAO::~NoteDAO() {

}

Note& NoteDAO::AddNote(const string& title, const  string& text) {
    Note* note = new Note();
    note->setText(text);
    note->setTitle(title);
    note->setId(nextNoteId++);
    notes.push_back(*note);
    return *note;
}

vector<Note> NoteDAO::GetAllNotes() {
    return notes;
}

Note NoteDAO::GetNote(const int& id) {
    std:vector<Note> allNotes = notes;

    int j = 0;
    for(auto note: notes) {
        if(note.getId() == id)
            return note;
    }
    throw logic_error("No note found!");
}
void NoteDAO::DisplayAll() const {
    for(auto note: notes) {
        note.Display();
    }
}
