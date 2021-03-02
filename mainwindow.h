#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QCalendarWidget>
#include <QListWidget>
#include "INotesController.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(INotesController& notesController, QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void handleButton();
private:
    QLineEdit *inputField;
    QTextEdit *outputField;
    QCalendarWidget *calendar;
    QListWidget *notes;
    INotesController *notesController;
};
#endif // MAINWINDOW_H
