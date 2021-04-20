#include "IUsersController.h"

#include <qmainwindow.h>

#ifndef USERWINDOW_H
#define USERWINDOW_H


class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    UserWindow(IUsersController& usersController, QWidget *parent = nullptr);
    ~UserWindow();
private slots:
private:
    IUsersController *usersController;
};
#endif // USERWINDOW_H
