/**
* @file
* @brief Header file for the AdminOptionWindow class
*/

#ifndef ADMINOPTIONWINDOW_H
#define ADMINOPTIONWINDOW_H

#include <QDialog>

/**
* @brief Include the addproductwindow.h file
*/
#include "addproductwindow.h"

/**
* @brief Include the RemoveFromStoreWindow.h file
*/
#include "RemoveFromStoreWindow.h"

/**
* @brief Include the editproductwindow.h file
*/
#include "editproductwindow.h"

/**
* @brief Include the addadminwindow.h file
*/
#include "addadminwindow.h"

/**
* @brief Include the changepasswordwindow.h file
*/
#include "changepasswordwindow.h"

/**
* @brief Include the displayproductwindow.h file
*/
#include "displayproductwindow.h"

/**
* @brief Include the vector library
*/
#include <vector>

/**
* @brief Namespace for the Ui namespace
*/
namespace Ui {
    /**
    * @brief Class for the AdminOptionWindow
    */
    class AdminOptionWindow;
}

/**
* @class AdminOptionWindow
* @brief Class for the AdminOptionWindow
*/
class AdminOptionWindow : public QDialog
{
    Q_OBJECT

public:
    /**
    * @brief Constructor for the AdminOptionWindow class
    * @param parent The parent widget
    * @param type The type of window
    */
    explicit AdminOptionWindow(QWidget *parent = nullptr,Qt::WindowType type=Qt::Dialog);

    /**
    * @brief Destructor for the AdminOptionWindow class
    */
    ~AdminOptionWindow();

private slots:
    /**
    * @brief Slot function to handle the add to store button clicked
    */
    void on_AddToStoreButton_clicked();

    /**
    * @brief Slot function to handle the remove from store button clicked
    */
    void on_RemoveFromStoreButton_clicked();

    /**
    * @brief Slot function to handle the show magazine button clicked
    */
    void on_ShowMagazineButton_clicked();

    /**
    * @brief Slot function to handle the add admin button clicked
    */
    void on_AddAdminButton_clicked();

    /**
    * @brief Slot function to handle the change password button clicked
    */
    void on_ChangePasswordButton_clicked();

    /**
    * @brief Slot function to handle the edit button clicked
    */
    void on_editButton_clicked();
    /**
    * @brief Slot function to handle the exit button clicked
    */
    void on_exitButton_clicked();

private:
    /**
    * @brief Pointer to the UI for the AdminOptionWindow class
    */
    Ui::AdminOptionWindow *ui;

    /**
    * @brief Vector of pointers to AddProductWindow objects
    */
    vector<AddProductWindow*> addProductWindows;

    /**
    * @brief Vector of pointers to RemoveFromStoreWindow objects
    */
    vector<RemoveFromStoreWindow*> removeProductWindows;

    /**
    * @brief Vector of pointers to EditProductWindow objects
    */
    vector<EditProductWindow*> editProductWindows;

    /**
    * @brief Vector of pointers to AddAdminWindow objects
    */
    vector<AddAdminWindow*> addAdminWindows;

    /**
    * @brief Vector of pointers to ChangePasswordWindow objects
    */
    vector<ChangePasswordWindow*> changePasswordWindows;

    /**
    * @brief Vector of pointers to DisplayProductWindow objects
    */
    vector<DisplayProductWindow*> displayProductWindows;

    /**
    * @brief Function to handle close event
    * @param event The close event
    */
    void closeEvent(QCloseEvent *event);
};

#endif // ADMINOPTIONWINDOW_H
