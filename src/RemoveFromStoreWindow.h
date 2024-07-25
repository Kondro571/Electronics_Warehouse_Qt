/**
 * @file RemoveFromStoreWindow.h
 * @brief The header file for the RemoveFromStoreWindow class
 * @author John Doe
 * @date 01/01/2023
 */

#ifndef REMOVEFROMSTOREWINDOW_H
#define REMOVEFROMSTOREWINDOW_H

#include <QDialog>
#include"function.h"

namespace Ui {
class RemoveFromStoreWindow;
}

/**
 * @class RemoveFromStoreWindow
 * @brief A QDialog subclass for removing items from the store
 */
class RemoveFromStoreWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new RemoveFromStoreWindow object
     * @param parent The parent widget
     */
    explicit RemoveFromStoreWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the RemoveFromStoreWindow object
     */
    ~RemoveFromStoreWindow();

private slots:
    /**
     * @brief Handles the goBack button's clicked signal
     */
    void on_goBack_clicked();

    /**
     * @brief Handles the removeButton's clicked signal
     */
    void on_removeButton_clicked();
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
    Ui::RemoveFromStoreWindow *ui;
};

#endif // REMOVEFROMSTOREWINDOW_H
