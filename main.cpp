#include "TXLib.h"

int main()
{
    txCreateWindow (700, 500);


    bool drawH = false;
    bool drawHr = false;
    bool drawG = false;

    HDC g = txLoadImage("g.bmp");
    HDC g1 = txLoadImage("������ 1.bmp");
    HDC g2 = txLoadImage("����.bmp");
    HDC g3 = txLoadImage("������) 2.bmp");
    HDC g4 = txLoadImage("���� 1.bmp");
    HDC h = txLoadImage("h.bmp");


    HDC hr = txLoadImage("����� �����-��.bmp");

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
    txBegin();
    txClear();


    txSetColor(TX_WHITE);
    txSetFillColor(TX_BLACK);
//���� �������� ���������


//������ ��� ����������� �������
    txRectangle(530,20,690,490);




//������� ������ (���� �� �� ������ ��������)
    txRectangle(10,20,170,60);
    txDrawText (10,20,170,60, "������");
    if (txMouseX()>= 10 && txMouseX()<= 170 &&
        txMouseY()>= 20 && txMouseY()<= 60 &&    txMouseButtons()==1)
    {
         drawG=true;
         drawH=false;
         drawHr=false;
    }




//��� ����� ������ ����� ����� ntkf ������ � �����
    txRectangle(180,20,340,60);
    txDrawText (180,20,340,60, "����");
    if (txMouseX()>= 180 && txMouseX()<= 340 &&
    txMouseY()>= 20 && txMouseY()<= 60 &&    txMouseButtons()==1)
    {
          drawH=true;
         drawG=false;
         drawHr=false;
    }


//���������(��������� ���� ��� ��������)
    txRectangle(350,20,520,60);
    txDrawText (350,20,520,60, "���������");
    if (txMouseX()>= 350 && txMouseX()<= 520 &&
        txMouseY()>= 20 && txMouseY()<= 60 &&    txMouseButtons()==1)
    {
          drawHr=true;
    }
//golovy
   if(drawG)
    {
         Win32::TransparentBlt  (txDC(), 550, 000,134,100,g,0,0,120,150,TX_WHITE);
         Win32::TransparentBlt  (txDC(), 550, 100,134,100,g1,0,0,640,792,TX_WHITE);
         Win32::TransparentBlt  (txDC(), 550, 200,134,100,g2,0,0,900,900,TX_WHITE);
         Win32::TransparentBlt  (txDC(), 550, 300,134,100,g3,0,0,1280,720,TX_WHITE);
         Win32::TransparentBlt  (txDC(), 550, 400,134,100,g4,0,0,215,283,TX_WHITE);
    }
  if(drawH)
    {
         Win32::TransparentBlt  (txDC(), 540, 30,50,187,h,0,0,50,187,TX_WHITE);
    }

  if(drawHr)
    {
         Win32::TransparentBlt  (txDC(), 550, 000,134,100,hr,0,0,1238,583,TX_WHITE);
    }





    txSleep(10);
    txEnd();

    }
txDeleteDC(h);
txDeleteDC(g);
txDeleteDC(hr);
return 0;
}
