#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*Meta tin eisagogi ton aparaititon vivliothikon ekana hrisi tis define gia merikous "hrusous arithmous",
kathos se periptosi allagon sto plithos paikton 'H sto plithos karton na einai eukolo na ginei kai programmatistika*/
#define PLITHOS_PAIKTON 3
#define GRAMMES 3
#define STILES 4
#define PLITHOS_KARTON (GRAMMES * STILES)
//Me hrisi tis typedef orisa 2 metavlites tupou struct gia paikti kai karta
typedef struct {
    char name[17];
    unsigned char score;
    char id;
}paiktis_t;

typedef struct {
    char colour;
    char shape;
    unsigned char number;
    char texture;
}karta_t;
//Dilosi ton sunartiseon pou kalo sti main(alles os void alles os int-analoga ti me eksipiretei)
void eisagogi_paikton(paiktis_t *p);
void ektuposi_karton(karta_t *k);
void getNextCard(karta_t *k);
void tuhaies_kartes(karta_t *k);
int idies_kartes(karta_t a,karta_t b);
int set_kartes(karta_t a,karta_t b,karta_t c);
int suntetagmenes_kartas(int g,int s);
void ektuposi_skor(paiktis_t p[]);

int main(){
    //Dilosi metavliton
    int p,g1,s1,g2,s2,g3,s3,gs1=0,gs2=0,gs3=0;
    int energos;
    char id='1';

    /*Dilosi domon paiktes kai kartes os monodiastatoi pinakes analoga me to plithos(paikton kai karton).
    Simeiosi: De theorisa aparaitito na hrisimopoiiso disdiastato pinaka gia ti domi ton karton, efoson
    me ton tropo pou epeleksa douleuei apsoga o kodikas. Stin periptosi hrisis enos disdiastatou pinaka gia tis kartes
    tha itan pio periplokos o kodikas, idietaira kata ton elegho ton tuhaion karton, gia ton an autes einai kai monadikes*/
    paiktis_t paiktes[PLITHOS_PAIKTON];
    karta_t kartes[PLITHOS_KARTON];

    eisagogi_paikton(paiktes);//Klisi sunartisis gia tin eisagogi ton paikton

    srand(time(NULL));//Hrisi srand gia orthi arhikopoiisi tis rand
    tuhaies_kartes(kartes);//Klisi sunartisis gia epilogi tuhaion karton
    ektuposi_karton(kartes);//Klisi sunartisis gia ektuposi ton karton
    //Akolouthei to loop pou epanalamvanetai eos na patithei to miden pou simainei kai tin eksodo apo to paixnidi.
    while(1){
    //Lista epilogon gia tous paiktes
    printf("\n An kapoios paiktis exei vrei SET na piesei to id tou\n");
    printf("\n Gia exodo apo to paixnidi pieste to 0\n");
    printf("\n An de briskei kaneis SET\n gia ektuposi neon karton pieste kapoio allo pliktro: ");
    scanf(" %c",&id);
        if(id=='0'){
            ektuposi_skor(paiktes);//An epileksoun to miden to programma kalei ti sinartisi ektuposis listas me ta skor
            return 1;//Kai kleinei to paihnidi
        }
        else{
            energos=-999;
            /*Arhikopoiisa ti metavlitis energos(paiktis) stin timi -999, giati to plithos paikton mporei na allaksei sto mellon
            kai den ksero posoi tha einai, oute ti id tha tous antistoihei.
            Etsi evala ena noumero pou logika apokleietai na antistoihei se kapoion paikti (-999 id !!!)*/
            for(p=0;p<PLITHOS_PAIKTON;p++){
                if(paiktes[p].id==id){
                /*Diatreho to plithos paikton me mia for sto pedio paiktes.id
                gia na diapistoso an to id pou evale kapoios kai diavastike me ti scanf uparhei mesa sto pedio tou struct paiktes*/
                   energos=p;/*katahorisi tis thesis pou vrethike i isotita sti metavliti energos
                            (stin periptosi mas o energos tha lavei mia apo tis times 0 'H 1 'H 2 ,
                             pou einai oi treis theseis tou pediou paiktes.id sto struct paiktes)*/
               }
            }
            if(energos!=-999){//H meavliti energos allakse timi se shesi me tin arhikopoiisi pou progithike, ara vrethike kapoio uparkto id
                //Pleon zitame apo ton energo paikti tis 3 kartes
                printf(" \nDose 3 kartes (me suntetagmenes ar.grammis (keno) ar.stilis)");//Theoroume oti o paiktis kanei orthi eisagogi,vazontas arithmous me keno anamesa tous
                printf(" \nProti karta: ");
                scanf(" %d %d",&g1,&s1);
                gs1=suntetagmenes_kartas(g1,s1);//Klisi sunartisis antistoihisis ton suntetagmenon pou dinei o paiktis kai katahorisi sti metavliti gs1

                printf(" \nDeuteri karta: ");
                scanf(" %d %d",&g2,&s2);
                gs2=suntetagmenes_kartas(g2,s2);//Antistoiha gia tin gs2

                printf(" \nTriti karta: ");
                scanf(" %d %d",&g3,&s3);
                gs3=suntetagmenes_kartas(g3,s3);//Kai tin gs3
                //Eleghos an oi suntetagmenes einai mesa sta oria
                if ((g1>GRAMMES)||(g2>GRAMMES)||(g3>GRAMMES)||(s1>STILES)||(s2>STILES)||(s3>STILES)){
                   printf("\n Oi suntetagmenes einai ektos ton orion.\n\n");
                ektuposi_karton(kartes);//Klisi sunartisis gia ektuposi ton karton
                }
                else{

                    if (set_kartes(kartes[gs1],kartes[gs2],kartes[gs3])){
                        /*Klisi tis sunartisis pou eleghei an oi 3 kartes apoteloun set*/
                        printf("\n Sosta! Edoses SET. Kerdizeis 2 pontous!\n\n");
                        paiktes[energos].score+=2;//An o energos paiktis petuhe SET tote prosauksanoume to pedio paiktes.score me 2 pontous
                        if(paiktes[energos].score>=10){//An to skor tou paikti ftasei i kseperasei tous 10 pontous
                            ektuposi_skor(paiktes);//Klisi tis sunartisis gia ektuposi listas me ta skor ton paikton
                            printf("\n O nikhths einai o/h %s\n",paiktes[energos].name);//Anakoinosi nikiti tou energou paikti
                            return 1;//Kleisimo paihnidiou
                        }
                        tuhaies_kartes(kartes);//An den ehei vrethei nikitis(eimaste ektos tou teleutaiou if pou afora tin periptosi euresis nikiti),
                    }                           //tote ginetai klisi tis sunartisis pou epilegei tuhaies kartes
                    else {
                        printf("\n Lathos apantisi.");
                        if(paiktes[energos].score>0){/*An o energos paiktis kanei lathos sto SET kai to skor tou einai >0,
                                                      tote afairoume apo to pedio paiktes.score enan ponto*/
                            paiktes[energos].score-=1;
                            printf("Exases enan ponto\n\n");//Ektuposi tou shetikou minumatos
                        }
                        else{
                            printf("Parameneis me mideniko skor.\n\n");//allios den afairoume ponto,apla enimeronoume oti paramenei to skor tou sto miden
                        }
                    /*Simeiosi: Se auto to simeio, diladi tis lanthasmenis apantisis,
                    DEN epilegoume nees tuhaies kartes(den kanoume klisi tis sunartisis tuhaies_kartes),
                    ara sti mnimi einai apothikeumenes oi arhikes kartes(prin to lathos tou paikti)*/
                    }
                    ektuposi_karton(kartes);/*Se kathe periptosi eite sostis eite lathos apantisis apo ton energo paikti,
                                            kanoume klisi tis sunartisis gia tin ektuposi karton.*/
                }
            }
            else{/*Pleon eimaste stin periptosi patimatos enos allou id(OXI to miden-auto to eksetasame stin arhi),
                    to opoio den antistoihei se kapoion paikti kai i metavliti energos paramenei stin arhikopoiimeni tis timi*/
                printf("\n Ektuposi neon karton: \n\n");//Ektuposi shetikou minumatos stin othoni
                tuhaies_kartes(kartes);//Klisi sunartisis gia epilogi neon tuhaion karton
                ektuposi_karton(kartes);//Kai ektuposi ton karton auton
            }
        }
    }
return 0;
}
//Akolouthoun ta somata ton sunartiseon pou hrisimopoiisame sti main
void eisagogi_paikton(paiktis_t *p){//Orisma einai enas deiktis *p enos struct p tupou paiktis_t, oste me anafora na allaksei ta periehomena tis dieuthunsis
    strcpy(p[0].name,"Marina Andreou");//Me strcpy antigrafoume sto pedio p.name ta 3 onomata ton paikton
    p[0].score=0;//Arhikopoioume kai to skor tou kathe paikti, katahorontas to 0 sto pedio p.score
    p[0].id='a';//Sto pedio p.id katahoroume ta antistoiha id
    strcpy(p[1].name,"Kostas Grammenos");
    p[1].score=0;
    p[1].id='g';
    strcpy(p[2].name,"Maria Perdika");
    p[2].score=0;
    p[2].id='p';
}
void getNextCard(karta_t *k){//Opos kai proigoumenos me anafora apothikeuoume sto struct k tupou karta_t me ti voitheia tou deikti *k
    int r;//Dilosi metavlitis
    r=rand()%3;//Katahorisi sti metavliti r tou apotelesmatos tis sunartisis rand me hrisi %3 gia na lamvanei times 0 1 kai 2
    switch(r){//Hrisi pollon switch gia ton epimerismo ton periptoseon gia kathe idiotita
        case 0:
        k->colour='r';//Gia tin idiotita hroma leme: pigaine sti dieuthunsi tou pediou k.colour kai vale to r( diladi (*k).colour)
        break;
        case 1:
        k->colour='g';
        break;
        case 2:
        k->colour='b';
        break;
    }
    r=rand()%3;
    switch(r){//Omoios gia tin idiotita shima
        case 0:
        k->shape='c';
        break;
        case 1:
        k->shape='t';
        break;
        case 2:
        k->shape='r';
        break;
    }
    k->number=rand()%3+1;//Ston arithmo einai pio aplo.Prosthetoume +1 sto %3 tis rand gia na lamvanei tuhaies times 1 2 kai 3
                        //(tis opoies katathoroume kai apothikeuoume sti dieuthinsi tou pediou k.number-diladi tin (*k).number
    r=rand()%3;
    switch(r){
        case 0:
        k->texture='b';//Pali ishuei to idio kai sto gemisma
        break;
        case 1:
        k->texture='h';
        break;
        case 2:
        k->texture='e';
        break;
    }
}
void tuhaies_kartes(karta_t *k){//Pali me anafora sto struct k tupou karta_t apothikeuoume me ti voitheia tou deikti *k
    int i,x;
    for(i=0;i<PLITHOS_KARTON;i++){
        getNextCard(&(k[i]));/*Kathos i for diatrehei to plithos karton kalei ti sunartisi epilogis tuhaias kartas
                                kai sto orisma tis mpainei i dieuthinsi tou struck(me hrisi tou &).Ousiastika leme sti randon_karta
                                pare to apotelesma sou kai katahorise to sti dieuthunsi tis domis tupou karta_t*/
    }
    //Afou egine i tuhaia epilogi ton karton, ksanatrehoume mia for gia na doume an einai oles monadikes
    for(i=0;i<PLITHOS_KARTON;i++){
        for(x=0;x<i;x++){//Emfoleumeni for
            if(idies_kartes(k[i],k[x])){//pou kalei ti sunartisi idies kartes me orismata to i tis protis for kai to x tis emfoleumeris for
                getNextCard(&(k[i]));//An oi 2 kartes einai ontos idies kalei ti getNextCard kai pali
                x=-1;/*Katahoroume se kathe guro tis emfoleumenis for sto x stin arhiki timi -1,
                    oste H for na diatrehei panta oles tis theseis x pou proigountai apo tin thesi i*/
            }
        }
    }
}
void ektuposi_karton(karta_t *k){//Sunartisi ektuposis ton karton - pali me anafora gia na apothikeuontai oi plirofories sto struct k tupou karta_t me ti voitheia tou deikti *k
    int i;
    for(i=0;i<PLITHOS_KARTON;i++){//Me mia for diatrehoume tis kartes kai tuponoume kathe fora sta antistoiha pedia tis times
        printf("[%c,%c,%d,%c] ",k[i].colour,k[i].shape,k[i].number,k[i].texture);
        if(i%4==3){//Me ti hrisi %3 kathe 4 theseis allazoume grammi,oste na ftiaksoume to plegma 3 grammes X 4 stiles
            printf("\n");
        }
    }
}
int idies_kartes(karta_t a,karta_t b){//Sunartisi eleghou isotitas 2 karton a kai b struct tupou karta_t
    if((a.colour==b.colour)&&(a.shape==b.shape)&&(a.number==b.number)&&(a.texture==b.texture)){
        return 1;//An oles tautohrona oi idiotites ton pedion tou struct einai idies gia tis 2 kartes i sunartisi epistrefei tin timi 1
    }
    else{
        return 0;//allios epistrefei mideniki timi
    }
}
int set_kartes(karta_t a,karta_t b,karta_t c){//Sunartisi eleghou gia to an oi 3 kartes a b c struct tupou karta_t apoteloun SET
    /*Eleghoume tis idiotites me emfoleumena if. Se kathe sugkrisi elegoume an i kathe idiotita einai eite isi kai gia tis 3 kartes
    eite anisi kai gia tis 3 kartes*/
    if(((a.colour==b.colour)&&(a.colour==c.colour))||((a.colour!=b.colour)&&(a.colour!=c.colour)&&(b.colour!=c.colour))){
       if(((a.shape==b.shape)&&(a.shape==c.shape))||((a.shape!=b.shape)&&(a.shape!=c.shape)&&(b.shape!=c.shape))){
            if(((a.number==b.number)&&(a.number==c.number))||((a.number!=b.number)&&(a.number!=c.number)&&(b.number!=c.number))){
                if(((a.texture==b.texture)&&(a.texture==c.texture))||((a.texture!=b.texture)&&(a.texture!=c.texture)&&(b.texture!=c.texture))){
                   return 1;//An ishioun ola ta parapano i sunartisi epistrefei tin timi 1
                }
            }
       }
    }
    return 0;//allios epistrefei mideniki timi
}
int suntetagmenes_kartas(int g,int s){//Sunartisi metashimatismou suntetagmenon pou dinei o hristis me eksodo ti metavliti gs
    int gs;
    gs=4*(g-1)+(s-1);//Pollaplasiazoume to plithos ton grammon (pou dinei o paiktis) me to 4 kai athroizoume ti stili
return gs;            //(kai apo ta duo afairoume -1 giati o pinakas arhizei apo 0 grammes kai 0 stiles)
}
void ektuposi_skor(paiktis_t p[]){//Sunartisi ektuposis listas me ta skor ton paikton
    int i=0;
    printf("\n Skor paikton:\n\n");
    printf(" --------------------\n");
    for(i=0;i<PLITHOS_PAIKTON;i++){//Me mia for diatrehoume to plithos ton paikton kai ektuponoume ta pedia tou struct paiktis.name kai paiktis.score
        printf(" %s %d\n",p[i].name,p[i].score);
    }
}
