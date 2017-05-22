#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARXEIO "bus.txt"

//Dilosi domis me hrisi tis typedef
typedef struct bus_struct{
    char name[40];
    unsigned short num[10];
    unsigned int th;
    } bus_t;

//Akolouthoun oi prosthies diloseis ton sunartiseon pou tha hrisimopoiisoume sti main

void anoigma_arheiou(bus_t *b,char *pinakida,int *ptheseis);
void arhikopoiisi_struct(bus_t *b,int theseis);
void emfanisi_kenon_theseon(bus_t *b,int theseis);
void kratisi_thesis(bus_t *b);
void anazitisi_kratimenis_thesis(bus_t *b,int theseis,int choice);
void akurosi_thesis(bus_t *b);
void ektuposi_listas_kratimenon_theseon(bus_t *b,int theseis);
void apothikeusi_se_arheio(bus_t b[],char pinakida[],int theseis);

int main(){
    bus_t bus[53];//Dilosi pinaka 53 theseon tupou domis
    char pinakida[8];
    int theseis,x;
    int choice=1;//Aparaititi i arhikopoiisi (oxi 0) gia na leitourgisei to sxetiko while

    //anoigma ARXEIO opos dilothike me define-diavasma pinakidas kai arithmou theseon-kai ektuposi stin othoni
    anoigma_arheiou(bus,pinakida,&theseis);

    // H lista epilogon epanalamvanetai mehrio na patithei to 0 pou mas odigei stin eksodo
    while(choice!=0){
        printf("\n\n SYSTHMA KATAGRAFIS KRATHMENON 8ESEON LEOFOREIOU\n");
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - ");
        printf("\n 1 Emfanisi sunolikou plithous kenon theseon \n   kai taxinomimenis listas ton arithmon tous\n");
        printf("\n 2 Kratisi thesis me sugkekrimeno arithmo me stoixeia epivati\n");
        printf("\n 3 Anazitisi kratimenis thesis me onomateponumo 'H ar. tilefonou\n");
        printf("\n 4 Akurosi kratisis me sugkekrimeno arithmo\n");
        printf("\n 5 Ektuposi listas: Onomateponumo,Tilefono,Arithmos Thesis \n   me taksinomisi kata Arithmo Thesis\n");
        printf("\n 0 Termatismos tou systimatos kratiseon\n");
        printf("\n Parakalo eisagete tin epilogi sas: ");
        scanf("%d",&choice);
        //Hrisi tis sunartisis switch gia tis epimerous epiloges
        //Se kathe epilogi ginetai klisi ton antistoihon sunartiseon
        switch (choice){
            case 1:
                emfanisi_kenon_theseon(bus,theseis);//klisi shetikis sunartisis
                break;
            case 2:
                printf(" Dose arithmo gia kratisi thesis: ");
                scanf("%d",&x);
                if(x<1||x>theseis){ //Elegoume oti o arithmos pou dothike apo to hristi einai entos orion
                    printf("\n\n Lathos arithmos thesis\n\n");
                }
                else{
                    kratisi_thesis(&(bus[x-1]));//klisi shetikis sunartisis me apothikeusi
                }//Vazoume x-1 gia na sumfonei o arithmos thesis x pou edose o hristis me ton antistoiho tou pediou bus.name
                break;
            case 3:
                printf("\n Gia anazitisi me onomateponumo patiste 1\n Gia anazitisi me ar.tilefonou patiste 2\n Epilogi: ");
                scanf("%d",&choice);
                anazitisi_kratimenis_thesis(bus,theseis,choice);//klisi shetikis sunartisis
                break;
            case 4:
                printf("\n Dose arithmo gia akurosi thesis: ");
                scanf("%d",&x);
                if(x<1||x>theseis){//Eleghos an o dothen arithmos gia akurosi einai entos orion
                    printf("\n Lathos arithmos thesis\n");
                }
                else{
                    akurosi_thesis(&(bus[x-1]));//Omoios me tin case 2 tis kratisis
                }
                break;
            case 5:
              ektuposi_listas_kratimenon_theseon(bus,theseis);//klisi shetikis sunartisis
                break;
            default:{
                break;
            }
        }
    }
    /*Telos kata tin exodo apo to systima kratiseon anoigoume to arheio bus.txt me tin epilogi tis eggrafis.
    Apothikeuoume ek neou tin pinakida kai ton arithmo theseon tou leoforeiou,
    kathos kai tis kratimenes theseis me taxinomisi ana arithmo thesis tou leoforeiou.
    Telika kleinoume to enimeromeno arheio  */
    apothikeusi_se_arheio(bus,pinakida,theseis);//klisi shetikis sunartisis
return 0;
}

void anoigma_arheiou(bus_t *b,char *pinakida,int *ptheseis){/*San orisma-ektos apo ti domi b typou bus_t kai tin pinakida-
    orisame epipleon enan deikti ptheseis pou mas voithaei stin fscanf kai ola me anafora, kathos
    to arheio allazei kata to diavasma tis times tous*/

    FILE *fin;//Dilosi deikti se arheio
    char onoma[40],epitheto[40];
    char tilefono[11];
    int i,thesi;
    fin=fopen(ARXEIO,"r");//Anoigma tou arheiou-Edo ehoume kanei define to onoma tou arheiou gia eukolia se tuhon allagi tou
    fscanf(fin,"%s %d",pinakida,ptheseis);
    printf("  OXHMA  - 8ESEIS\n");//Boithitikos titlos gia ta stoiheia pou diavastikan
    printf(" %s -   %d\n",pinakida,*ptheseis);

    arhikopoiisi_struct(b,*ptheseis);/*Klisi sunartisis arhikopoiisis struct.
    Kata tin klisi i sunartisi auti diavazei me anafora to deikti ptheseis,
    eno sto soma tis sunartisis ehei san eisodo to int theseis*/

// diavasma kratimenon theseon apo to arxeio
    while(!feof(fin)){//gia oso o deiktis sto arxeio mas den exei ftasei sto telos tou arxeio
        fscanf(fin," %s %s %d %s",epitheto,onoma,&thesi,tilefono);//diavazoume tin kathe tetrada ton stoiheion tou arheiou

        //antigrafi ton diavasmenon stoiheion apo to arheio
        strcpy(b[thesi-1].name,epitheto);//prota to (diavasmeno apo to arheio) epitheto mpainei kateutheian sto pedio b.name
        strcat(b[thesi-1].name," ");//meta sughoneuoume to pedio b.name me ena keno
        strcat(b[thesi-1].name,onoma);//telos sughoneoume to pedio b.name me to (diavasmeno apo to arheio) onoma
    //Me ti for gemizoume to pedio b.num me tous diavasmenous haraktires tilefonou
        for(i=0;i<10;i++){
            b[thesi-1].num[i]=tilefono[i]-'0';//Edo bazoume thesi-1 gia na katahorithei ortha ston pinaka pou ksekinaei apo to 0
            /*Gia ti metatropi ton haraktiron pou diavasame se morfi unsigned short hrisimopoioume tin eksis methodo:
            Afairoume ton arithmo ASCII pou antistoihei sto haraktira '0' apo ton kathe arithmo ASCII pou antistoihei
            stous haraktires '0 eos 9'. Auti i methodos leitourgei egguimena,kathos ston pinaka ASCII
            oi haraktires pou antistoihoun stous arithmous einai diadohikoi.Paradeigma o haraktiras '4' ehei ASCII to 52 kai
            afairontas ton ASCII pou antistoihei sto '0',diladi to 48, mas dinei 4 pou einai o insigned short pou zitame! */
        }
    }
    //kleinoume to arheio pleon
    fclose(fin);
}
void arhikopoiisi_struct(bus_t *b, int theseis){
    int i,x;
    for(i=0;i<theseis;i++){
        for(x=0;x<10;x++){/*Diatrehoume to pedio b.num kai bazoume se kathe stoiheio x tou to miden.
                            Auto to petuhainoume me emfoleumeni for i opoia diatrehei kathe thesi i tou leoforeio*/
            b[i].num[x]=0;
        }
        for(x=0;x<40;x++){
            b[i].name[x]='\0';
        /*Enallaktika anti anti gia for mporousame na arhikopoiisoume
        mono ton proto haraktira tou pediou name os eksis: b[i].name[0]='\0';*/
        }
        //+1 prokeimenou na sumfonei to pedio b.th tis domis me tis pragmatikes theseis tou leoforeiou
            b[i].th=i+1;
    }
}

void emfanisi_kenon_theseon(bus_t *b,int theseis){
    int i,x=0;//Arhikopoiisi metriti
    for(i=0;i<theseis;i++){
        if(b[i].name[0]=='\0'){
    /*Me ti hrisi tis for diatrehoume to pedio b.name gia oles tis theseis
    kai koitame an ston proto haraktira uparhei i keni sumvoloseira.
    Otan ishiei kati tetoio simainei pos i thesi auti einai keni.
    Den uparhei logos na psaksoume tous upoloipous haraktires tou b.name,
    kathos einai arketos o protos haraktiras-me tin uparksi i mi tis kenis sumvoloseiras*/
            x++;
    //Auksisi tou metriti kathe fora pou sunantame keni thesi
        }
    }
    printf("\n \tPlithos kenon theseon: %d",x);//diavasma tou metriti kai ektuposi stin othoni
    printf("\n \tLISTA KENON THESEON:\n");
    for(i=0;i<theseis;i++){
        if(b[i].name[0]=='\0'){
    /*Me tin idia logiki me proigoumenos, ektuponoume ti lista kenon theseon
    diavazontas kata tin ektuposi to pedio b.th gia tis theseis
    stis opoies sto pedio tou b.name ksekina me tin keni sumvoloseira*/
            printf("[%2d]  ",b[i].th);//Stoihisi ton ar.theseon gia na emfanizontai omorfa kai oi monopsifies theseis
            if(b[i].th%9==0){//Gia optikous logous allazoume grammi kathe 9h thesi
                printf("\n");
            }
        }

    }
}

void kratisi_thesis(bus_t *b){
    char onoma[40];
    char tilefono[11];
    int i;

    if(b->name[0]!='\0'){
    //Kai pali eleghoume gia tin keni sumvoloseira sto pedio b.name
        printf("\n\n H thesi %d einai idi kratimeni\n\n",b->th);//Ektuposi minumatos gia idi kratimeni thesi
    }
    else {
        printf("\n Dose Epitheto kai Onoma: ");
        scanf(" %s %s",b->name,onoma);//Apothikeuoume to dothen epitheto kateutheian sto pedio b.name
        strcat(b->name," ");//Sughoneuoume sto pedio b.name me ena keno haraktira
        strcat(b->name,onoma);//Sughoneoume sto pedio b.name to dothen onoma apo to hristi
        printf("\n Dose arithmo tilefonou: ");
        scanf(" %s",tilefono);
        for(i=0;i<10;i++){//Gemizoume to pedio b.num apo ton pinaka char tilefono meion ton ASCII arithmo tou miden.
            b->num[i]=tilefono[i]-'0';
        }
        printf("\n H thesi %d kratithike me stoixeia epibati %s %s\n",b->th,b->name,tilefono);
        /*Kata tin ektuposi to tilefono to diavazoume apo auto pou edose o hristis,kati pou de mas peirazei
        epeidi apla kai mono enimeronoume stin othoni,diladi den ehei kapoia epiptosi sto programma mas*/
    }
}


void anazitisi_kratimenis_thesis(bus_t *b,int theseis,int choice){
    int i,x;
    char onoma[40],epitheto[40];
    unsigned short noumero[10];
    int z,counter;
    char tilefono[11];

    switch(choice){//"Spame tin periptosi 3 se 2 upoperiptoseis"
        case 1:
            printf("\n Dose onomateponumo: ");
            scanf(" %s %s",epitheto,onoma);//Aothikeuontai ta duo stoiheia stous voithitikous pinakes
            strcat(epitheto," ");//Sughoneuo to epitheto me ena keno haraktira
            strcat(epitheto,onoma);//Sughoneuo to epitheto me to onoma afou eparkei o horos tou pinaka epitheto kai gia ta 2 stoiheia
            x=0;//Arhikopoiisi metriti
            for(i=0;i<theseis;i++){
                if(strcmp(epitheto,b[i].name)==0){
            /*Den einai aparaitito na ginei elegxos gia to an einai kratimeni i thesi,
            giati an i thesi einai keni tote o protos haraktiras tis tha ehei tin keni sumboloseira
            kai sunepos den mporei na prokipsei isotita sto strcmp pou kanoume me to dothen onoma apo to hristi*/
                    printf("\n Brethike kratisi sto onoma %s sti thesi %d\n",b[i].name,b[i].th);//Ektuposi shetikou minumatos diavazontas ta antistoiha pedia b.name kai b.th.
                    x++;//Stin periptosi pou brethei kratimeni thesi prosthetoume sto metriti
                }
            }
            if(x==0){//An o metritis paramenei miden
                printf("\n De brethike kratisi sto onoma %s\n",epitheto);//Simainei pos den brethike kratisi sto dothen onoma
            }
            break;
        case 2:
            printf("\n Dose arithmo tilefonou: ");
            scanf(" %s",tilefono);
            for(i=0;i<10;i++){
              noumero[i]=tilefono[i]-'0';/*Katahoroume to dothen tilefono (meion ton ASCII tou miden) se boithitiko pinaka unsigned short */
            }
            counter=0;//Arhikopoiisi metriti euresis kratiseon
            for(i=0;i<theseis;i++){
                if(b[i].name[0]!='\0'){//Edo einai aparaitito o elegxos gia to an einai kratimeni i thesi, me elegho an o protos haraktiras tou b.name einai \0
                    z=0;//Arhikopoiisi metriti euresis psifion tilefonou
                    for(x=0;x<10;x++){
                    /*Diatrehoume to pedio bus.num kai ton pinaka noumero kai eleghoume gia isotita se kathe thesi */
                        if(noumero[x]==b[i].num[x]){
                            z++;//Kathe fora pou ishuei i isotita prothetoume +1 sto metriti psifion
                        }
                    }
                    if(z==10){/*An o metritis deiksei 10(diladi ola ta psifia tou dothentos
                                noumerou tairiazoun ena pros ena me to pedio b.num)
                                simainei oti brethike kratisi se auto to noumero*/
                        printf("\n Brethike kratisi sto tilefono %s sti thesi %d\n",tilefono,b[i].th);
                        counter++;//Se autin tin periptosi prosthetoume +1 ston metriti kratiseon
                    }
                }
           }
            if(counter==0){//An o metritis kratiseon paramenei miden-de brethike kratisi me to arithmo tilefonou pou edose o hristis
                printf("\n De brethike kratisi sto tilefono %s\n",tilefono);
            }
            break;
        default:{//Se periptosi pou o hristis patisei lathos psifio anti gia 1 'H 2
            printf("\n Lathos epilogi");
            }
            break;
    }
}

void akurosi_thesis(bus_t *b){
    char yesno;
    if(b->name[0]=='\0'){    /*Me tin euresi kenis sumvoloseiras sto pedio b.name
                            enimeronoume pos i thesi pou epilehthike einai idi keni*/
        printf("\n H thesi pou epileksate einai idi keni.\n\n");
    }
    else{//Zitame epivevaiosi tis akirosis
        printf("\n Eiste sigouroi gia tin akurosi\n tis thesis %d sto onoma %s(y/n)?",b->th,b->name);
        scanf(" %c",&yesno);
        if((yesno=='y')||(yesno=='Y')){
            b->name[0]='\0';/*Bazoume ston proto haraktira tin keni sumvoloseira,
                                    kati pou mas arkei gia tin apeleutherosi tis thesis.
                                    Simeiosi-stis upoloipes theseis tou pediou b.name paramenoun "skoupidia",
                                    pou omos den epireazoun ta apotelesmata tou programmatos*/
            printf("\n Egine epitixos i akurosi tis thesis %d\n",b->th);
        }
        else {//Gia akurosi tis akurosis!!!
            printf("\n Den egine i akurosi.\n");
        }
    }
}
void ektuposi_listas_kratimenon_theseon(bus_t *b,int theseis){
    int i,x;
    printf("\n\n\t\t               Lista kratimenon theseon\n");
    printf("    ------------------------------------------------------------\n");
    printf(" \t\t\t   Onomateponumo  -  Tilefono  -  Thesi \n");
    printf("    ------------------------------------------------------------\n");
    for(i=0;i<theseis;i++){
        if(b[i].name[0]!='\0'){/*Me ti hrisi tis for diatrehoume to pedio b.name
                                    mono ston proto haraktira tou pediou.
                                    Otan i for sunantisei MH keni sumvoloseira, tote tuponei to pedio*/
            printf(" %40.40s   ",b[i].name);
            for(x=0;x<10;x++){/*Me tin emfoleumeni for diatrehoume to pedio b.num
                                kai tupoume kathe stoiheio tou pinaka pou pliri to proigoumeno kritirio
                                (diladi tis MH kenis sumvoloseiras sto pedio b.name)*/
                printf("%d",b[i].num[x]);
            }
            printf(" %6d\n",b[i].th);//Antistoiha tuponoume kai tis theseis(me MH keni sumvoloseira)

        }
    }
}
void apothikeusi_se_arheio(bus_t b[],char pinakida[],int theseis){
    int i,x;
    FILE *fin;

    fin=fopen(ARXEIO,"w");
    fprintf(fin,"%s %d\n",pinakida,theseis);//Apothikeuoume me fprintf pinakida kai theseis tou leoforeiou sto ARXEIO pou orisame me define me ti voitheia tou deikti fin
    for(i=0;i<theseis;i++){//Me hrisi tis for diatrehoume tis theseis tou leoforeiou gia na entopisoume tis kratimenes
        if(b[i].name[0]!='\0'){//Me mia if exetazoume an o protos haraktiras tou pediou b.num ehei MH keni sumvoloseira,ara kratimeni thesi
            fprintf(fin,"%s %d ",b[i].name,b[i].th);//Kai tin "tuponoume"(=apothikeuoume me fprintf sto ARXEIO)
            for(x=0;x<10;x++){//Akomi me hrisi mis emfoleumenis for diatrehoume ton pinaka tou pediou b.num
                fprintf(fin,"%d",b[i].num[x]);//Kai apothikeuoume me fprintf kathe psifio tou tilefonou sto ARXEIO
            }
            fprintf(fin,"\n");
            /*Se kathe gyro tou exoterikou for allazoume grammi,
            opos mas dothike arhika to ARXEIO me tis kratiseis ti mia kato apo tin alli*/
        }
    }
    fclose(fin);//Kleisimo tou ARXEIO me fclose sto deikti fin.
}
