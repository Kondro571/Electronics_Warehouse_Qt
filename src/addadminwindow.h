/**
 *@file
 *@brief Header file for the AddAdminWindow class
 */

#ifndef ADDADMINWINDOW_H
#define ADDADMINWINDOW_H
#include <QDialog>

/**
 *@brief include the function.h file
 */
#include "function.h"

/**
 *@brief Namespace for the Ui namespace
 */
namespace Ui
{
    /**
     *@brief Class for the AddAdminWindow
     */
    class AddAdminWindow;
}

/**
 *@class AddAdminWindow
 *@brief Class for the AddAdminWindow
 */
class AddAdminWindow: public QDialog
{
    Q_OBJECT

    public:
        /**
         *@brief Constructor for the AddAdminWindow class
         *@param parent The parent widget
         */
        explicit AddAdminWindow(QWidget *parent = nullptr);

        /**
         *@brief Destructor for the AddAdminWindow class
         */
        ~AddAdminWindow();

    private slots:
        /**
         *@brief Slot function to handle the add admin button clicked
         */
        void on_addAdminButton_clicked();

        /**
         *@brief Slot function to handle the go back button clicked
         */
        void on_goBack_clicked();

    private:
        /**
         *@brief Pointer to the UI for the AddAdminWindow class
         */
        Ui::AddAdminWindow * ui;
};


#endif	// ADDADMINWINDOW_H
