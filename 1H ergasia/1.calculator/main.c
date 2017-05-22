#include <stdio.h>//eisagogi vivliothikis eisodou-exodou

char praxi;//dilosi tou sumvolou mathimatikis praxis
float protos_arithmos,defteros_arithmos,apotelesma;//dilosi 3 metavliton aplis akribeias

void main(){//eisagogi sunartisis main me void, kathos den anameno na mou dosei timi exodou
    printf("\n\tDose arithmo praxi arithmo kai ase\n\n\tENA KENO DIASTIMA metaksi tous:\n\n\t\t");//kalesma sto xristi na eisagei ta 3 stoixeia pou xreiazontai me protromi na afisei keno metaksi ton 3 stoixeion
    scanf(" %f %c %f",&protos_arithmos ,&praxi, &defteros_arithmos);//anamoni tis c gia kataxorisi ton zitithenton
    if(praxi=='+'){//proto endexomeno-prosthesi
    apotelesma=protos_arithmos+defteros_arithmos;//entoli prosthesis
    printf("\n\tApotelesma = %.2f\n", apotelesma);//ektuposi stin othoni apotelesmatos prosthesis me periorismo se 2 dekadika
    }
        else if(praxi=='-'){//deftero endexomeno-afairesi
        apotelesma=protos_arithmos-defteros_arithmos;//entoli afairesis
        printf("\n\tApotelesma = %.2f\n", apotelesma);//ektuposi stin othoni apotelesmatos afairesis me periorismo se 2 dekadika
        }
            else if(praxi=='*'){//trito endexomeno-pollaplasiasmos
                    apotelesma=protos_arithmos*defteros_arithmos;//entoli pollaplasiasmou
            printf("\n\tApotelesma = %.2f\n", apotelesma);//ektuposi stin othoni apotelesmatos pollaplasiasmou me periorismo se 2 dekadika
            }
                else if(praxi=='/'){//tetarto endexomeno-diairesi
                    if(defteros_arithmos==0){//upoperiptosi adunatis diairesis me to miden
                    printf("\n\tAdunati i diairesi me to miden(O)\n");//ektuposi sxetikis proeidopoiisis
                    }
                    else{//upoperiptosi o arithmos n2 na min einai miden
                    apotelesma=protos_arithmos/defteros_arithmos;//entoli diairesis
                    printf("\n\tApotelesma = %.2f\n", apotelesma);//ektuposi stin othoni apotelesmatos diairesis me periorismo se 2 dekadika
                    }
                }
    else{//pempto endehomeno diaforetikos haraktira anti ton +,-,*,/
    printf("Lathos eidos praxis\n");//ektuposi stin othoni minimatos lathous kai telos programmatos
    }
    return;//exodos apo to programma horis epistrofi kapoias timis
}
