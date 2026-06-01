#ifndef MODOSGAMEWIDGET_H
#define MODOSGAMEWIDGET_H

#include <QWidget>

namespace Ui {
class ModosGameWidget;
}

class ModosGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModosGameWidget(QWidget *parent = nullptr);
    ~ModosGameWidget();

private:
    Ui::ModosGameWidget *ui;
};

#endif // MODOSGAMEWIDGET_H
