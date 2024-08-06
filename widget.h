#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

class QButtonGroup;
class QCheckBox;
class QLabel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QButtonGroup* ButtonGroup;
    QVector<QCheckBox*> Buttons;
    QLabel* Label;


public slots:
    void editLabel(int);

};
#endif // WIDGET_H
