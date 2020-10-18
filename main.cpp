#include "TXLib.h"

struct Head
{
    int x;
    int y;
    HDC picture;
    int width;
    int height;
    string category;
    bool visible;
};

struct Button
{
    int x;
    int y;
    const char* text;
    string category;
};

void drawButton(Button button)
{
    txRectangle(button.x, button.y, button.x+160, button.y+40);
    txDrawText (button.x, button.y, button.x+160, button.y+40, button.text);
}

bool clickButton(int x, int y)
{
    if (txMouseX()>= x && txMouseX()<= x + 160&&
        txMouseY()>= y && txMouseY()<= y + 40&&    txMouseButtons()==1)
    return true;
}

int main()
{
    txCreateWindow (900, 600);



    string vybrannaya_category = "";
    const int N_HEAD=12;
    Head head[N_HEAD];
    head[0] =  {760,  30,txLoadImage("pictures/��������/������/1.bmp"),92,84, "������"};
    head[1] =  {760, 100,txLoadImage("pictures/��������/������/2.bmp"),92,84, "������"};
    head[2] =  {760, 170,txLoadImage("pictures/��������/������/3.bmp"),92,84, "������"};
    head[3] =  {760,  30,txLoadImage("pictures/��������/f.bmp"),195,246, "������"};
    head[4] =  {760, 100,txLoadImage("pictures/��������/g.bmp"),195,246, "������"};
    head[5] =  {760, 200,txLoadImage("pictures/��������/w.bmp"),195,246, "������"};
    head[6] =  {760,  30,txLoadImage("pictures/�����/�����.bmp"),107,292, "���"};
    head[7] =  {760,  30,txLoadImage("pictures/��������/������.bmp"),251,261, "����"};
    head[8] =  {760, 250,txLoadImage("pictures/�����/�����1.bmp"),107,292, "���"};
    head[9] =  {760,  30,txLoadImage("pictures/n/n.bmp"),120,598, "����"};
    head[10] = {760,  30,txLoadImage("pictures/n/����.bmp"),120,598, "����"};
    head[11] = {760,  30,txLoadImage("pictures/n/����1.bmp"),120,598, "����"};

    Head head1[N_HEAD];
    head1[0] = {111, 100};
    head1[1] = {111, 100};
    head1[2] = {111, 100};
    head1[3] = {111, 100};
    head1[4] = {111, 100};
    head1[5] = {111, 100};
    head1[6] = {111, 100};
    head1[7] = {111, 100};
    head1[8] = {111, 100};
    head1[9] = {111, 100};
    head1[10] = {111,100};
    head1[11] = {111,100};
    int n_active = -1;

    for (int i = 0; i < N_HEAD; i++)
    {
        head1[i].category=head[i].category;
        head1[i].height=head[i].height;
        head1[i].picture=head[i].picture;
        head1[i].width=head[i].width;
    }

    const int N_BUTTON=8;
    Button button[N_BUTTON];
    button[0] = { 10, 20,"������", "������"};
    button[1] = {180, 20,"����", "����"};
    button[2] = {350, 20,"����", ""};
    button[3] = {530, 20,"����������� ����", ""};
    button[4] = { 10, 80,"����", "����"};
    button[5] = {180, 80,"���", "���"};
    button[6] = {350, 80,"������", "������"};
    button[7] = {530, 80,"���������", "���������"};

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txClear();


        txSetColor(TX_WHITE);
        txSetFillColor(TX_BLACK);
    //���� �������� ���������


    //������ ��� ����������� �������
        txRectangle(730,20,890,590);

        for (int i=0;i<N_BUTTON;i= i+1)
            drawButton(button[i]);


    //������� ������ (���� �� �� ������ ��������)
        for (int i=0;i<N_BUTTON;i= i+1)
        if (clickButton(button[i].x, button[i].y))
        {
             vybrannaya_category=button[i].category;
        }

    for (int i = 0; i < N_HEAD; i++)
        if(head[i].category == vybrannaya_category)
        {
             Win32::TransparentBlt  (txDC(), head[i].x, head[i].y, 100, 100, head[i].picture, 0, 0, head[i].width,head[i].height,  TX_WHITE);
        }

//�������� ��������
    for(int i=0; i < N_HEAD; i++)
    {
        if(
            txMouseX()>= head1[i].x && txMouseX()<= head1[i].x + head1[i].width &&
            txMouseY()>= head1[i].y && txMouseY()<= head1[i].y + head1[i].height  &&    txMouseButtons()==1 && n_active < 0
          )

          {
             n_active = i;
          }
    }

    if(n_active >=0 )
    {
        head1[n_active].x = txMouseX() - 10;
        head1[n_active].y = txMouseY() - 10;
    }

    if(txMouseButtons()==0)
        n_active = -100;


    //���� �� �������
    for (int i = 0; i < N_HEAD; i++)
        if(head[i].category == vybrannaya_category &&
           txMouseX()>= head[i].x && txMouseX()<= head[i].x + head[i].height &&
           txMouseY()>= head[i].y && txMouseY()<= head[i].y + head[i].width  &&    txMouseButtons()==1)
        {
            head1[i].visible = true;
        }


    for (int i = 0; i < N_HEAD; i++)
        if (head1[i].visible)
             Win32::TransparentBlt  (txDC(), head1[i].x, head1[i].y, head1[i].width, head1[i].height, head1[i].picture, 0, 0, head1[i].width, head1[i].height, TX_WHITE);



    txSleep(10);
    txEnd();
}
txDeleteDC(head[0].picture);
return 0;
}
