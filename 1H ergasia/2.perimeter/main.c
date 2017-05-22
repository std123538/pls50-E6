#include <stdio.h>
#include <math.h>//eisagogi vivliothikis mathimatikon sunartiseon

//dilosi metavliton kai sunartiseon
char epilogi;
int plevra_tetragonou,mikos,platos;
int Perimetros_tetragonou(int plevra_tetragonou);
int Perimetros_orthogoniou(int mikos,int platos);
float vasi,upsos,upoteinousa,aktina;
float upol_upoteinousas(float vasi,float upsos);
float Perimetros_orth_trigonou(float vasi,float upsos,float upoteinousa);
float Perimetros_kuklou(float aktina);

float main(){//eisagogi sunartisis main me tautohroni ektiposi grafikon gia aisthitikous logous
    printf("\t _______________________________\n");
    printf("\t|     YPOLOGISMOS PERIMETROY\t|\n\t|_______________________________|\n\t|\t\t\t\t|\n");
    printf("\t|      Gia na upologisete       |\n\t|   tin perimetro-perifereia    |\n\t| epilegete ena apo ta parakato:|\n\t|\t\t\t\t|\n\t| 1 ) Tetragono\t\t\t|\n\t| 2 ) Parallilogrammo\t\t|\n");
    printf("\t| 3 ) Orthogonio trigono\t|\n\t| 4 ) Kuklos\t\t\t|\n\t| 0 ) Exodos apo to programma\t|\n\t|_______________________________|\n\n Epilogi :");
    scanf(" %c",&epilogi);//anamoni apo xristi tis epilogis geometrikou shimatos

    if(epilogi=='1'){//proti epilogi: tetragono me xrisi tis if
            printf("\n\tEpilexate tetragono.\n\n\tDoste tin plevra :");//ektuposi apotelesmatos epilogis tou hristi kai entoli na dothei to mikos tis plevras tou tetragonou
            scanf(" %d", &plevra_tetragonou);//anamoni apo hristi mikous plevras tetragonou-afinoume ithelimena ena keno prin ti scanf vasei upodeiksis tou erotimatos
            Perimetros_tetragonou(plevra_tetragonou);//klisi sunartisis upologismou perimetrou tetragonou
    }
        else if(epilogi=='2'){//deuteri epilogi: orthogonio me hrisi tis else if gia dimiourgia upoperiptoseon
            printf("\n\tEpilexate orthogonio.\n\n\tDoste to mikos :");//ziteitai to mikos
            scanf(" %d", &mikos);//anamoni apo to hristi- panta me ithelimeno keno
            printf("\tDoste to platos :");//ziteitai to platos;
            scanf(" %d", &platos);//anamoni apo to hristi- panta me ithelimeno keno
            Perimetros_orthogoniou(mikos,platos);//klisi sunartisis upologismou perimetrou orthogoniou
        }
        else if(epilogi=='3'){//triti epilogi orthogonio: trigono
            printf("\n\tEpilexate orthogonio trigono.\n\n\tHreiazontai oi kathetes plevres\n\n\tDoste ti vasi :");//ziteitai i vasi tou orth.trigonou
            scanf(" %f", &vasi);//anamoni apo to hristi- panta me ithelimeno keno
            printf("\tDoste to upsos :");//ziteitai to upsos tou orth.trigonou
            scanf(" %f", &upsos);//anamoni apo to hristi- panta me ithelimeno keno
            upol_upoteinousas(vasi,upsos);//klisi sunartisis upologismou upoteinousas
            Perimetros_orth_trigonou(vasi,upsos,upoteinousa);//klisi sunartisis upologismou perimetrou orth.trigonou
        }
        else if(epilogi=='4'){//tetarti epilogi: kuklos
            printf("\n\tEpilexate kuklo.\n\n\tDoste tin aktina :");//ziteitai i aktina tou kuklou
            scanf(" %f", &aktina);//anamoni apo to hristi- panta me ithelimeno keno
            Perimetros_kuklou(aktina);//klisi sunartisis upologismou perifereias kuklou
        }
        else if(epilogi=='0'){//pempti epilogi: exodos apo to programma
            printf("\n\t Epilexate exodo.\n\n\t Sas euxaristoume!\n");//ektuposi shetikou minumatos
            return 0;//kleisimo programmatos
        }
    else{//ekti epilogi: allos haraktiras ektos ton proanaferthenton
        printf("\n Lanthasmeni epilogi.\n\n Dokimaste xana.\n");//ektuposi shetikou minumatos kai ziteitai apo to hristi na dokimasei pali
    }

return main();//epistrofi sti main gia epanalipsi epilogis apo to hristi upologismou apo tin arhi
}
    //akolouthoun ta somata ton sunartiseon pou hrisimopoiithikan
    int Perimetros_tetragonou(int plevra_tetragonou){//soma sunartisis tetragonou
        int Perimetros_tetragonou;//dilosi topikis metavlitis
        Perimetros_tetragonou=plevra_tetragonou*4;//entoli upologismou
        printf("\n\tH perimetros tou tetragonou einai %d\n\n\n Neos upologismos:\n", Perimetros_tetragonou);//ektuposi apotelesmatos kai protropi gia neo upologismo
    }
    int Perimetros_orthogoniou(int mikos,int platos){//soma sunartisis orthogoniou
        int Perimetros_orthogoniou;//dilosi topikis metavlitis
        Perimetros_orthogoniou=2*(mikos+platos);//entoli upologismou
        printf("\n\tH perimetros tou orthogoniou einai %d\n\n\n Neos upologismos:\n", Perimetros_orthogoniou);//ektuposi apotelesmatos kai protropi gia neo upologismo
    }
    float upol_upoteinousas(float vasi, float upsos){//soma sunartisis upoteinousas
        float upol_upoteinousas;//dilosi topikis metavlitis
        upoteinousa=sqrt(vasi*vasi+upsos*upsos);//entoli upologismou
    }
    float Perimetros_orth_trigonou(float vasi,float upsos,float upoteinousa){//soma sunartisis ortho.trigonou
        float Perimetros_orth_trigonou;//dilosi topikis metavlitis
        Perimetros_orth_trigonou=vasi+upsos+upoteinousa;//entoli upologismou
        printf("\n\tH perimetros tou orthogoniou trigonou einai %.2f\n\n\n Neos upologismos:\n", Perimetros_orth_trigonou);//ektuposi apotelesmatos kai protropi gia neo upologismo
    }
    float Perimetros_kuklou(float aktina){//soma sunartisis kuklou
        float Perimetros_kuklou;//dilosi topikis metavlitis
        Perimetros_kuklou=2*3.1415*aktina;//entoli upologismou
        printf("\n\tH perifereia tou kuklou einai %.2f\n\n\n Neos upologismos:\n", Perimetros_kuklou);//ektuposi apotelesmatos kai protropi gia neo upologismo
    }
