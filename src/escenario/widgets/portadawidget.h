#ifndef PORTADAWIDGET_H
#define PORTADAWIDGET_H

#include <QWidget>

namespace Ui {
class PortadaWidget;
}

class PortadaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PortadaWidget(QWidget *parent = nullptr);
    ~PortadaWidget();

private:
    Ui::PortadaWidget *ui;
};

#endif // PORTADAWIDGET_H
