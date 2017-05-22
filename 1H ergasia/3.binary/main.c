#include <stdio.h>

int arithmos,piliko,upoloipo;
const int vasi=2; //dilosi statheras vasis aritmos 2

int main(){
    printf("\tAntistrofi duadiki anaparastasi arithmou\n\n");
    printf("\tDoste enan thetiko akeraio arithmo: \n ");
    scanf("%d",&arithmos);
    if (arithmos<0){//proto endehomeno arnitiki epilogi akeraiou apo hristi
        printf("\tDosate arnitiko arithmo.\n\tDokimaste xana.\n\n ");//lamvanei aporriptiko minuma kai zita neo arithmo
        return main();//to programma epistrefei stin arxi
    }
    else//deutero endehomeno thetikos akeraios

    do {//epilogi sinartisis do while gia epanalipsi tis gia oso tha ishuoun oi proupotheseis
    upoloipo=arithmos%vasi;//prota upologizoume to upoloipo
    piliko=arithmos/vasi;//meta upologizoume to piliko
    arithmos=piliko;//anathesi timis arithmou se piliko gia na epalamvanetai diarkos o kuklos
    upoloipo==0?putchar('0'):putchar('1');//me ti xrisi tou telesti ? bazoume antistoixa tous xartaktires 0 i 1 ana periptosi
    }
      while(piliko>0);//proupothesi gia na epenalamvanetai o vrohos
    return 0;
}
