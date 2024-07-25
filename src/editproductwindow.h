/**
 * @file EditProductWindow.h
 * @brief The header file for the EditProductWindow class
 * @author John Doe
 * @date 01/01/2023
 */

#ifndef EDITPRODUCTWINDOW_H
#define EDITPRODUCTWINDOW_H

#include <QDialog>
#include "function.h"
namespace Ui {
class EditProductWindow;
}
/**
 * @class EditProductWindow
 * @brief A QDialog subclass for editing product information
 */
class EditProductWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new EditProductWindow object
     * @param parent The parent widget
     */
    explicit EditProductWindow(QWidget *parent = nullptr);
    /**
     * @brief Destroys the EditProductWindow object
     */
    ~EditProductWindow();

private slots:
    /**
     * @brief Handles the goBack button's clicked signal
     */
    void on_goBack_clicked();
    /**
    * @brief Handles the changeButton1's clicked signal
    */
    void on_changeButton1_clicked();
    /**
     * @brief Handles the changeButton2's clicked signal
     */
    void on_changeButton2_clicked();

    /**
     * @brief Handles the currentTextChanged signal of the categoryProduct object
     * @param arg1 The new text of the categoryProduct object
     */
    void on_categoryProduct_currentTextChanged(const QString &arg1);
    /**
     * @brief set the table widget
     * @param arg  the category of the product
     */
    void set_TableWidget(std::string arg);
private:
    Ui::EditProductWindow *ui;
};

#endif // EDITPRODUCTWINDOW_H
