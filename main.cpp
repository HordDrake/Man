

#include "TXLib.h"

int main()

   {
   txCreateWindow (800, 600);
   txClear();
   txSetColour(TX_BLACK);

    txRectangle(0, 0, 200, 100);
    txDrawText(0, 0, 200, 100, "����");
    txRectangle(0, 0, 200, 100);
    txDrawText(0, 0, 400, 100, "������");


    return 0;
    }

