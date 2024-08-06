#include "widget.h"

#include <QCheckBox>
#include <QButtonGroup>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(140,300);

    //라벨을 하나 추가..
    Label = new QLabel("what", this);


    //버튼그룹은 소속만 주어지는 것이 보이죠. 문자는 없습니다.
    ButtonGroup  = new QButtonGroup(this);
    ButtonGroup->setExclusive(true);


    //라디오버튼 벡터에 버튼들을 넣어 줍시다.
    for(int i = 0;i<4;i++){

        //문자열에 argument 포함시켜서 생성하기..
        QString str = QString("%1CheckBoxButton").arg(i+1);
        Buttons.append(new QCheckBox(str, this));
        Buttons[i]->move(10,40+20*i);
        ButtonGroup->addButton(Buttons[i], i);


    }

    //레이블에 커넥트..
    //버튼그룹에 속한 SIGNAL 은 저렇게 매개변수를 줄 수 있다. 특이한건 함수
    connect(ButtonGroup,SIGNAL(idClicked(int)),this,SLOT(editLabel(int)));


}

void Widget::editLabel(int id){

    QButtonGroup* BG = static_cast<QButtonGroup*>(sender());

    QCheckBox *button = static_cast<QCheckBox*>(BG->button(id));

    Label->setText(button->text().at(0));
}



Widget::~Widget()
{
}
