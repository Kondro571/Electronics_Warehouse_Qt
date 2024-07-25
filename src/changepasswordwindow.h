/**
 * @file ChangePasswordWindow.h
 * @brief The header file for the ChangePasswordWindow class
 * @author John Doe
 * @date 01/01/2023
 */

#ifndef CHANGEPASSWORDWINDOW_H
#define CHANGEPASSWORDWINDOW_H

#include <QDialog>
#include "function.h"

namespace Ui {
class ChangePasswordWindow;
}

/**
 * @class ChangePasswordWindow
 * @brief A QDialog subclass for changing a user's password
 */
class ChangePasswordWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new ChangePasswordWindow object
     * @param parent The parent widget
     */
    explicit ChangePasswordWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the ChangePasswordWindow object
     */
    ~ChangePasswordWindow();

private slots:
    /**
     * @brief Handles the goBack button's clicked signal
     */
    void on_goBack_clicked();

    /**
     * @brief Handles the changePasswordButton's clicked signal
     */
    void on_changePasswordButton_clicked();

private:
    Ui::ChangePasswordWindow *ui;
};

#endif // CHANGEPASSWORDWINDOW_H
