#include "TXLib.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct variants
{
    const char* address;
    string category;
    HDC picture;
    int width;
    int height;
    bool visible;
    int x;
    int y;
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
     //txRectangle           (x, y, x + 200, y + 80);
        Win32::RoundRect(txDC(), button.x, button.y, button.x + 160, button.y + 40, 10, 10);
        txDrawText (button.x, button.y, button.x+160, button.y+40, button.text);
}

bool clickButton(int x, int y)
{
    if (txMouseX()>= x && txMouseX()<= x + 160&&
        txMouseY()>= y && txMouseY()<= y + 40&&    txMouseButtons()==1)
    return true;
}


//���� ������ � ������ �������
int getWidth(const char* address)
{
    char header[54];
    ifstream bmp;
    bmp.open(address, ios::in | ios::binary);
    bmp.read(header, 54);
    int width;
    memcpy(&width, &header[18], sizeof(width));
    return width;
}

int getHeight(const char* address)
{
    char header[54];
    ifstream bmp;
    bmp.open(address, ios::in | ios::binary);
    bmp.read(header, 54);
    int height;
    memcpy(&height, &header[22], sizeof(height));
    return height;
}



int main()
{
    txCreateWindow (900, 780);

    string vybrannaya_category = "";

    const int N_variants = 25;
    variants variants[N_variants], center[N_variants];
    variants[0] = {"pictures/���/���1.bmp"};
    variants[1] = {"pictures/���/���2.bmp"};
    variants[2] = {"pictures/���/���3.bmp"};
    variants[3] = {"pictures/���/���4.bmp"};

    variants[4] = {"pictures/����/����.bmp"};
    variants[5] = {"pictures/����/����1.bmp"};
    variants[6] = {"pictures/����/����2.bmp"};

    variants[7] = {"pictures/���/�����.bmp"};
    variants[8] = {"pictures/���/�����1.bmp"};

    variants[9] = {"pictures/����/1.bmp"};
    variants[10] = {"pictures/����/2.bmp"};
    variants[11] = {"pictures/����/�������.bmp"};

    variants[12] = {"pictures/��������/1.bmp"};
    variants[13] = {"pictures/��������/2.bmp"};
    variants[14] = {"pictures/��������/3.bmp"};
    variants[15] = {"pictures/��������/4.bmp"};
    variants[16] = {"pictures/��������/5.bmp"};

    variants[17] = {"pictures/����/f.bmp"};
    variants[18] = {"pictures/����/g.bmp"};
    variants[19] = {"pictures/����/w.bmp"};
    variants[20] = {"pictures/����/green.bmp"};
    variants[21] = {"pictures/����/������.bmp"};

    variants[22] = {"pictures/���������/�����1.bmp"};
    variants[23] = {"pictures/���������/�����2.bmp"};
    variants[24] = {"pictures/���������/�����3.bmp"};

    //������� ���������, ������, ������
    for (int i = 0; i < N_variants; i = i + 1)
    {
        string address = variants[i].address;
        int pos1 = address.find("/",1);
        int pos2 = address.find("/",pos1 + 1);
        int pos3 = address.find(".",pos2 + 1);

        variants[i].category = address.substr(pos1 + 1, pos2-pos1-1);
        variants[i].visible = false;

        variants[i].x = 760;
        variants[i].picture = txLoadImage(variants[i].address);
        variants[i].height = getHeight(variants[i].address);
        variants[i].width = getWidth(variants[i].address);
    }

    //����, � ������� ��������� ����������, ������, ������
    int Y_Fone = 50;
    int y_Yubki = 50;
    int y_Niza = 50;
    int y_Golova = 50;
    int y_Volosi = 50;
    int y_Telo = 50;
    int y_Verxa = 50;
    int Y_Ykrashenia = 50;


    for (int i = 0; i < N_variants; i++)
    {
        if (variants[i].category == "���")
        {
            variants[i].y = Y_Fone;
            Y_Fone = Y_Fone + 100;
        }
        if (variants[i].category == "����")
        {
            variants[i].y = y_Yubki;
            y_Yubki = y_Yubki + 100;
        }
        if (variants[i].category == "���")
        {
            variants[i].y = y_Niza;
            y_Niza = y_Niza + 100;
        }

        if (variants[i].category == "��������")
        {
            variants[i].y = y_Golova;
            y_Golova = y_Golova + 100;
        }

        if (variants[i].category == "������")
        {
            variants[i].y = y_Volosi;
            y_Volosi = y_Volosi + 100;
        }

        if (variants[i].category == "����")
        {
            variants[i].y = y_Telo;
            y_Telo = y_Telo + 100;
        }

         if (variants[i].category == "����")
        {
            variants[i].y = y_Verxa;
            y_Verxa = y_Verxa + 100;
        }
        if (variants[i].category == "���������")
        {
            variants[i].y = Y_Ykrashenia;
            Y_Ykrashenia = Y_Ykrashenia + 100;
        }

    }



    int n_active = -1;


    for (int i = 0; i < N_variants; i++)
    {
        center[i].category=variants[i].category;
        center[i].height=variants[i].height;
        center[i].picture=variants[i].picture;
        center[i].width=variants[i].width;
        center[i].visible = false;

        if (center[i].category == "���")
        {
            center[i].x = 0;
            center[i].y = 125;
        }

        if (center[i].category == "����")
        {
            center[i].x = 111;
            center[i].y = 120;
        }

        if (center[i].category == "����")
        {
            center[i].x = 85;
            center[i].y = 290;
        }

        if (center[i].category == "���")
        {
            center[i].x = 111;
            center[i].y = 300;
        }

        if (center[i].category == "��������")
        {
            center[i].x = 111;
            center[i].y = 125;
        }

        if (center[i].category == "����")
        {
            center[i].x = 140;
            center[i].y = 300;
        }

     if (center[i].category == "���������")
        {
            center[i].x = 150;
            center[i].y = 320;
        }
    }


//�������� �� �����
        ifstream file1("1.txt");
        while(file1.good())
        {
            string s;
            getline(file1, s);
            //variants[0].x = atoi (s.c_str());
            //variants[0].y = atoi (s.c_str());
        }
        file1.close();

    const int N_BUTTON=8;
    Button button[N_BUTTON];
    button[0] = { 10, 20,"������", "��������"};
    button[1] = {180, 20,"����", "����"};
    button[2] = {350, 20,"����", ""};
    button[3] = {530, 20,"���� ", "����"};
    button[4] = { 10, 80,"����", "����"};
    button[5] = {180, 80,"���", "���"};
    button[6] = {350, 80,"���", "���"};
    button[7] = {530, 80,"���������", "���������"};




    //���� ��������������
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txClear();




        txSetColor(TX_WHITE);
        txSetFillColor(TX_BLACK);
//���� �������� ���������


 //������ ��� ����������� �������
        txRectangle(730,20,890,770);

        for (int i=0;i<N_BUTTON;i= i+1)
        {
            txSetColor(TX_WHITE);
            if (vybrannaya_category==button[i].category)
            {
                txSetColor(TX_WHITE, 8);
            }

            drawButton(button[i]);
        }

   //�������� �� ������
        for (int i=0;i<N_BUTTON;i= i+1)
            if (clickButton(button[i].x, button[i].y))
            {
                 vybrannaya_category=button[i].category;
            }



        for (int i = 0; i < N_variants; i++)
            if (variants[i].category == vybrannaya_category)
            {
                if(variants[i].width > variants[i].height)
                Win32::TransparentBlt  (txDC(), variants[i].x, variants[i].y, 100 , 100*variants[i].height/variants[i].width, variants[i].picture, 0, 0, variants[i].width,variants[i].height,  TX_WHITE);
                else
                Win32::TransparentBlt  (txDC(), variants[i].x, variants[i].y, 100 * variants[i].width/variants[i].height, 100, variants[i].picture, 0, 0, variants[i].width,variants[i].height,  TX_WHITE);
            }



 //�������� ��������
        for (int i = N_variants - 1; i >= 0; i--)
        {
            if( //�������� �����
                txMouseX()>= center[i].x && txMouseX()<= center[i].x + center[i].width &&
                txMouseY()>= center[i].y && txMouseY()<= center[i].y + center[i].height  &&
                txMouseButtons()==1 && n_active < 0 &&

                center[i].visible)
            {
                n_active = i;
            }
        }

        if (n_active >= 0)
        {
            center[n_active].x = txMouseX() - 10;
            center[n_active].y = txMouseY() - 10;
        }


        if (n_active >= 0 && txMouseX() < 10)
        {
            center[n_active].visible = false; //(���������)
        }

        if(txMouseButtons()==0)
            n_active = -100;

    //���� �� �������
        for (int i = 0; i < N_variants; i++)
            if(variants[i].category == vybrannaya_category &&
               txMouseX()>= variants[i].x && txMouseX()<= variants[i].x + 100 &&
               txMouseY()>= variants[i].y && txMouseY()<= variants[i].y + 100  &&    txMouseButtons()==1)
            {
                //��� ���1 � ����� �� ���������� ������
                for (int k = 0; k < N_variants; k++)
                    if (center[i].category == center[k].category)
                        center[k].visible = false;

                center[i].visible = true;
            }


        for (int i = 0; i < N_variants; i++)
            if (center[i].visible)
                 Win32::TransparentBlt  (txDC(), center[i].x, center[i].y, center[i].width, center[i].height, center[i].picture, 0, 0, center[i].width, center[i].height, TX_WHITE);



        txSleep(10);
        txEnd();
    }
    //�� �������� �����:)    ������� �������� ����!!!
    txDeleteDC(variants[0].picture);


//���������� � ����
    ofstream file("1.txt");
    for (int i = 0; i < N_variants; i++)
    {
        if (variants[i].visible == true)
        {
            file << variants[i].x << endl;
            file << variants[i].y << endl;
            file << variants[i].address << endl;
        }
    }
    file.close();

    return 0;
}
