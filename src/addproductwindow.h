/**
 *@file
 *@brief Header file for the AddProductWindow class
 */

#ifndef ADDPRODUCTWINDOW_H
#define ADDPRODUCTWINDOW_H
#include <QDialog>

/**
 *@brief Include the function.h file
 */
#include "function.h"

/**
 *@brief Namespace for the Ui namespace
 */
namespace Ui
{
    /**
     *@brief Class for the AddProductWindow
     */
    class AddProductWindow;
}

/**
 *@class AddProductWindow
 *@brief Class for the AddProductWindow
 */
class AddProductWindow: public QDialog
{
    Q_OBJECT

    public:
        /**
         *@brief Constructor for the AddProductWindow class
         *@param parent The parent widget
         */
        explicit AddProductWindow(QWidget *parent = nullptr);

        /**
         *@brief Destructor for the AddProductWindow class
         */
        ~AddProductWindow();

    private slots:
        /**
         *@brief Slot function to handle the go back button clicked
         */
        void on_goBackButton_clicked();

        /**
         *@brief Slot function to handle the add ram button clicked
         */
        void on_addRamButton_clicked();

        /**
         *@brief Slot function to handle the add cpu button clicked
         */
        void on_addCpuButton_clicked();

        /**
         *@brief Slot function to handle the add motherboard button clicked
         */
        void on_addMotherboardButton_clicked();

    private:
        /**
         *@brief Pointer to the UI for the AddProductWindow class
         */
        Ui::AddProductWindow * ui;

        /**
         *@brief Function to handle close event
         *@param event The close event
         */
        void closeEvent(QCloseEvent *event);
};


#endif	// ADDPRODUCTWINDOW_H
