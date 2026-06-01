#ifndef JUEGOMODUNOWIDGET_H
#define JUEGOMODUNOWIDGET_H

#include <QWidget>

namespace Ui {
class JuegoModUnoWidget;
}

class JuegoModUnoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit JuegoModUnoWidget(QWidget *parent = nullptr);
    ~JuegoModUnoWidget();

private:
    Ui::JuegoModUnoWidget *ui;
};

#endif // JUEGOMODUNOWIDGET_H
