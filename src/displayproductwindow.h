/**
 * @file DisplayProductWindow.h
 * @brief The header file for the DisplayProductWindow class
 * @author John Doe
 * @date 01/01/2023
 */

#ifndef DISPLAYPRODUCTWINDOW_H
#define DISPLAYPRODUCTWINDOW_H

#include <QDialog>
#include "function.h"

namespace Ui {
class DisplayProductWindow;
}

/**
 * @class DisplayProductWindow
 * @brief A QDialog subclass for displaying product information
 */
class DisplayProductWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new DisplayProductWindow object
     * @param parent The parent widget
     */
    explicit DisplayProductWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the DisplayProductWindow object
     */
    ~DisplayProductWindow();

private slots:
    /**
     * @brief set the table widget
     */
    void set_TableWidget();

    /**
     * @brief Handles the goBack button's clicked signal
     */
    void on_goBack_clicked();

private:
    Ui::DisplayProductWindow *ui;
};

#endif // DISPLAYPRODUCTWINDOW_H
