#pragma once
#ifndef INOTESCONTROLLER_H
#define INOTESCONTROLLER_H

#endif // INOTESCONTROLLER_H
#include "note.h"

#include <iterator>
#include <vector>
class INotesController {

public:
    virtual Note& AddNote(const string& title, const string& text, const int& userId) = 0;
    virtual Note GetNote(const int& id) = 0;
    virtual vector<Note> GetAllNotes() = 0;
    virtual vector<Note> GetAllNotesByUserId(const int& id) = 0;
};
