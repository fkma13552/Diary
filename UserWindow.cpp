#include "UserWindow.h"
UserWindow::UserWindow(IUsersController& usersController, QWidget *parent)
: QMainWindow(parent)
{
  this->usersController = &usersController;
}

UserWindow::~UserWindow()
{
}
