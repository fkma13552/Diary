#pragma once
#ifndef NOTEDAO_H
#define NOTEDAO_H
#include<string>
#include <vector>
#include "note.h"
using namespace std;

class NoteDAO
{
public:
    NoteDAO();
    ~NoteDAO();
    Note& AddNote(const string& title, const  string& text);
    Note& GetNote(const int& id) ;
    vector<Note>::iterator GetAllNotes();
    void DisplayAll() const;

private:
    int nextNoteId = 666;
    vector<Note> notes;
};

#endif // NOTEDAO_H
