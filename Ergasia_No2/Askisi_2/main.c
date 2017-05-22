#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARXEIO "bus.txt"

/* SHMEIOSH: PARELEIPSA TA SXOLIA POU YPHRXAN APO THN PROTH ASKHSH.
EPIKENTROTHIKA MONO STO SXOLIASMO TON OPOION ALLAGON THS SUGKEKRIMENIS EKDOSIS TOU PROGRAMMATOS*/


//Dilosi domis me hrisi tis typedef
typedef struct bus_struct bus_t;/*Dilosi typou struct bus_t se duo vimata logo tou deikti *next
                                pou deihnei ston idio typo*/
struct bus_struct{
    char name[40];
    unsigned short num[10];
    unsigned int th;
    bus_t *next;// Deiktis se struct typou bus_t
    };//Vgike to onoma tou struct,kathos dilothike sto proto vima

FILE *fin;//Hrisi global metavlitis gia na ti vlepoun oles shetikes oi sunartiseis

//Akolouthoun oi prosthies diloseis ton sunartiseon pou tha hrisimopoiisoume sti main

void anoigma_arheiou(char *pinakida,int *ptheseis);
void kratima_theseon_apo_arxeio(bus_t *b);
void arhikopoiisi_struct(bus_t *b,int theseis);
void emfanisi_kenon_theseon(bus_t *b,int theseis);
void kratisi_thesis(bus_t *b);
void anazitisi_kratimenis_thesis(bus_t *b,int theseis,int choice);
void akurosi_thesis(bus_t *b);
void apothikeusi_se_arheio(bus_t *head,char pinakida[],int theseis);
void ektuposi_listas(bus_t bus[],int theseis);
void bubblesort_eponumo(bus_t *b,int length);
void bubblesort_thesi(bus_t *b,int length);
void dimiourgia_listas(bus_t b[],bus_t **head, int theseis);
void eisagogi_se_lista(bus_t **head,bus_t *n);
//void print_lista(bus_t *head); Edo eho mia voithitiki sunartisi gia elegho tis apla sundedemenis listas

int main(){
    bus_t *bus;//pointer se struct type
    char pinakida[8];
    int theseis,x,t;
    int choice=1;
    bus_t *head=NULL;
    //anoigma ARXEIO opos dilothike me define-diavasma pinakidas kai arithmou theseon-kai ektuposi stin othoni
    anoigma_arheiou(pinakida,&theseis);/*Edo "spasame" tj sunartisi pou eihame stin proti askisi se 2 sunartisis,
    kathos endiamesa kanoume hrisi tis malloc. Etsi prota anoigoume to arheio kai diavazoume pinakida kai theseis.
    Meta kanoume dunamiki desmeusi mnimis-me vasi tis theseis pou diavasame apo to ARXEIO- me hrisi malloc,
    mata arhikopoioume ta pedia tou struct
    kai meta diavazoume kai kanoume kratisi ton theseon apo osa anagrafontai sto ARXEIO.

    Me alla logia, osa kaname stin proti askisi se mia sunartisi-pleon ginontai se 2 sunartiseis me
    2 endiameses energeies(malloc kai arhikopoiisi struct)*/
    bus = (bus_t *)malloc((theseis)*sizeof(bus_t));//Hrisi malloc
    arhikopoiisi_struct(bus,theseis);//Klisi sunartisis arhikopoiisis struct
    kratima_theseon_apo_arxeio(bus);//Diavasma kai kratisi theseon apo to ARXEIO

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

        switch (choice){
            case 1:
                emfanisi_kenon_theseon(bus,theseis);
                break;
            case 2:
                printf(" Dose arithmo gia kratisi thesis: ");
                scanf("%d",&x);
                if(x<1||x>theseis){
                    printf("\n\n Lathos arithmos thesis\n\n");
                }
                else{
                    kratisi_thesis(&(bus[x-1]));
                }
                break;
            case 3:
                printf("\n Gia anazitisi me onomateponumo patiste 1\n Gia anazitisi me ar.tilefonou patiste 2\n Epilogi: ");
                scanf("%d",&choice);
                anazitisi_kratimenis_thesis(bus,theseis,choice);
                break;
            case 4:
                printf("\n Dose arithmo gia akurosi thesis: ");
                scanf("%d",&x);
                if(x<1||x>theseis){
                    printf("\n Lathos arithmos thesis\n");
                }
                else{
                    akurosi_thesis(&(bus[x-1]));
                }
                break;
            case 5:
                printf("\n Epilexte 1 gia taxinomisi kata auksonta arithmo thesis\n\t  2 gia tax/si ABtika me Onom/mo (prota Epitheto): ");
                scanf(" %d",&t);
                switch(t){
                    case 1:
                        ektuposi_listas(bus,theseis);
                        break;
                    case 2:
                        bubblesort_eponumo(bus,theseis);
                        ektuposi_listas(bus,theseis);
                        bubblesort_thesi(bus,theseis);
                        break;
                    default:
                        printf("\n Lathos epilogi.\n");
                        break;
                }
                break;
            default:{
                break;
            }
        }
    }
    bubblesort_eponumo(bus,theseis);//Ksanakanoume taxinomisi me onomateponumo
    dimiourgia_listas(bus,&head,theseis);
   // print_lista(head); Edo ginetai klisi tis voithitikis sunartisis eleghou an i lista douleuei sosta
    apothikeusi_se_arheio(head,pinakida,theseis);//I sunartisi auti kaleitai me orisma to deikti head tis listas
return 0;
}

void anoigma_arheiou(char *pinakida,int *ptheseis){
    fin=fopen(ARXEIO,"r");
    fscanf(fin,"%s %d",pinakida,ptheseis);
    printf("  OXHMA  - 8ESEIS\n");
    printf(" %s -   %d\n",pinakida,*ptheseis);
    /*Ara i sunartisi auti diavazei pinakida kai ar. theseon apo to ARXEIO
    kai teleionei XORIS na kleisei to ARXEIO */
}



void kratima_theseon_apo_arxeio(bus_t *b){
    char onoma[40],epitheto[40];
    char tilefono[11];
    int i,thesi;



    while(!feof(fin)){
        fscanf(fin," %s %s %d %s",epitheto,onoma,&thesi,tilefono);


        strcpy(b[thesi-1].name,epitheto);
        strcat(b[thesi-1].name," ");
        strcat(b[thesi-1].name,onoma);

        for(i=0;i<10;i++){
            b[thesi-1].num[i]=tilefono[i]-'0';
        }
    }
    fclose(fin);
}
void arhikopoiisi_struct(bus_t *b, int theseis){
    int i,x;

    for(i=0;i<theseis;i++){
        for(x=0;x<10;x++){
            b[i].num[x]=0;
        }
        for(x=0;x<40;x++){
            b[i].name[x]='\0';
        }
        b[i].th=i+1;
        b[i].next=NULL;//Arhikopoiisi deikti next gia kathe struct tou pinaka b
    }
}

void emfanisi_kenon_theseon(bus_t *b,int theseis){
    int i,x=0;
    for(i=0;i<theseis;i++){
        if(b[i].name[0]=='\0'){
            x++;
        }
    }
    printf("\n \tPlithos kenon theseon: %d",x);
    printf("\n \tLISTA KENON THESEON:\n");
    for(i=0;i<theseis;i++){
        if(b[i].name[0]=='\0'){
            printf("[%d]  ",b[i].th);
            if(b[i].th%9==0){
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
        printf("\n\n H thesi %d einai idi kratimeni\n\n",b->th);
    }
    else {
        printf("\n Dose Epitheto kai Onoma: ");
        scanf(" %s %s",b->name,onoma);
        strcat(b->name," ");
        strcat(b->name,onoma);
        printf("\n Dose arithmo tilefonou: ");
        scanf(" %s",tilefono);
        for(i=0;i<10;i++){
            b->num[i]=tilefono[i]-'0';
        }
        printf("\n H thesi %d kratithike me stoixeia epibati %s %s\n",b->th,b->name,tilefono);
    }
}


void anazitisi_kratimenis_thesis(bus_t *b,int theseis,int choice){
    int i,x;
    char onoma[40],epitheto[40];
    unsigned short noumero[10];
    int z,counter;
    char tilefono[11];

    switch(choice){
        case 1:
            printf("\n Dose onomateponumo: ");
            scanf(" %s %s",epitheto,onoma);
            strcat(epitheto," ");
            strcat(epitheto,onoma);
            x=0;
            for(i=0;i<theseis;i++){
                if(strcmp(epitheto,b[i].name)==0){
                    printf("\n Brethike kratisi sto onoma %s sti thesi %d\n",b[i].name,b[i].th);
                    x++;
                }
            }
            if(x==0){
                printf("\n De brethike kratisi sto onoma %s\n",epitheto);
            }
            break;
        case 2:
            printf("\n Dose arithmo tilefonou: ");
            scanf(" %s",tilefono);
            for(i=0;i<10;i++){
              noumero[i]=tilefono[i]-'0';
            }
            counter=0;
            for(i=0;i<theseis;i++){
                if(b[i].name[0]!='\0'){
                    z=0;
                    for(x=0;x<10;x++){
                        if(noumero[x]==b[i].num[x]){
                            z++;
                        }
                    }
                    if(z==10){
                        printf("\n Brethike kratisi sto tilefono %s sti thesi %d\n",tilefono,b[i].th);
                        counter++;
                    }
                }
           }
            if(counter==0){
                printf("\n De brethike kratisi sto tilefono %s\n",tilefono);
            }
            break;
        default:{
            printf("\n Lathos epilogi");
            }
            break;
    }
}

void akurosi_thesis(bus_t *b){
    char yesno;
    if(b->name[0]=='\0'){
        printf("\n H thesi pou epileksate einai idi keni.\n\n");
    }
    else{
        printf("\n Eiste sigouroi gia tin akurosi\n tis thesis %d sto onoma %s(y/n)?",b->th,b->name);
        scanf(" %c",&yesno);
        if((yesno=='y')||(yesno=='Y')){
            b->name[0]='\0';
            printf("\n Egine epitixos i akurosi tis thesis %d\n",b->th);
        }
        else {
            printf("\n Den egine i akurosi.\n");
        }
    }
}
void ektuposi_listas(bus_t b[],int theseis){
    int i,x;
    printf("\n\n\t\t               Lista kratimenon theseon\n");
    printf("    ------------------------------------------------------------\n");
    printf(" \t\t\t   Onomateponumo  -  Tilefono  -  Thesi \n");
    printf("    ------------------------------------------------------------\n");
    for(i=0;i<theseis;i++){
        if(b[i].name[0]!='\0'){
            printf(" %40.40s   ",b[i].name);
            for(x=0;x<10;x++){
                printf("%d",b[i].num[x]);
            }
            printf(" %6d\n",b[i].th);

        }
    }
}
/*Pleon stin apothikeusi se arheio hrisimopoioume to deikti head(ti lista mas diladi-kai oxi ton pinaka me ta struct*/
void apothikeusi_se_arheio(bus_t *head,char pinakida[],int theseis){
    int x;
    FILE *fin;

    fin=fopen(ARXEIO,"w");
    fprintf(fin,"%s %d",pinakida,theseis);
    while(head != NULL)
        {
            fprintf(fin,"\n%s %d ",head->name,head->th);//Gi'auto hrisimopoioume tous komvous tis listas
            for(x=0;x<10;x++){
                fprintf(fin,"%d",head->num[x]);
            }
            head = head->next;
        }
    fclose(fin);
}
void bubblesort_eponumo(bus_t *b,int length){/*Sunartisi fussalidas.San orisma pairnei to struct typou bus_t kai to int length mikos tou struct*/
        int i,k,s,f,j;
        char temp[40];
        unsigned short h;
/*Me 2 for emfoleumenes petuhainoume to sort. I esoteriki for diatrehei kata mikos tou struct ksekinontas apo kato kai pigainei pros ta epano me --.
Kanei elegho isotitas duo diadohikon string ton pedion b.name kai an to kato (i) string einai mikrotero apo eto epano string(i-1),
tote ta kanei toumpa (swap) me ti voitheia mias endiamesis metavlitis.
I eksoteriki for diatrehei to length apo epano pros ta kato kai etsi epitughanetai se kathe guro na paramenei to mikrotero i epano epano sti lista*/
    for(k=0;k<length-1;k++){
        for(i=length-1;i>k;i--){
            s=strcmp(b[i].name,b[i-1].name);
            if(s<0){
                // swap onomaton
                strcpy(temp,b[i].name);//1o vima katahorisi tou string sti voithitiki metavliti
                strcpy(b[i].name,b[i-1].name);//2o vima katahorisi tou string tis i-1 sti i
                strcpy(b[i-1].name,temp);//3o vima katahorisi tis voithitikis metavlitis sto i-1
                // swap theseon
                f=b[i].th;//Omoios me ti thesi me hrisi voithitikis metavlitis f
                b[i].th=b[i-1].th;
                b[i-1].th=f;
                // swap tilefonon
                for(j=0;j<10;j++){//Omoios me to tilefono me hrisi voithitikis metavlitis h, me parallili hrisi mias for gia gemisma tou pinaka
                    h=b[i].num[j];
                    b[i].num[j]=b[i-1].num[j];
                    b[i-1].num[j]=h;
                }
            }
        }
    }
}
void bubblesort_thesi(bus_t *b,int length){//Omoio skeptiko me tin bubblosort eponumo
        int i,k,f,j;
        char temp[40];
        unsigned short h;

    for(k=0;k<length-1;k++){
        for(i=length-1;i>k;i--){
            if(b[i].th<b[i-1].th){//Moni diafora, o eleghos isotitas afora ton arithmo thesis
               // swap onomaton
                strcpy(temp,b[i].name);
                strcpy(b[i].name,b[i-1].name);
                strcpy(b[i-1].name,temp);
                // swap theseon
                f=b[i].th;
                b[i].th=b[i-1].th;
                b[i-1].th=f;
                // swap tilefonon
                for(j=0;j<10;j++){
                    h=b[i].num[j];
                    b[i].num[j]=b[i-1].num[j];
                    b[i-1].num[j]=h;
                }
            }
        }
    }
}
/*Auti i sunartisi eisagei ena struct sto telos tis listas me anadromiko tropo
head:o deiktis stin arhi tis listas,
n: deiktis sto struct pou theloume na eisagoume*/
void eisagogi_se_lista(bus_t **head,bus_t *n){/*Edo hreiazomaste enan deikti sto deikti head,
    kathos o idios o head deihnei sto NULL kai prokeimenou na parameinei i metakinisi tou sto next
    meta to telos tis sunartisis, ton pername me anafora-Etsi vazoume kai deutero asteri*/
    if((*head)==NULL){//Periptosi adeias listas
       (*head)=n;//Tote katahoroume to neo (=proto) struct
    }
    else{
        if((*head)->next==NULL){//Periptosi na ftasame anadromika sto telos tis listas
            (*head)->next=n;//Prosthetoume to neo struct
            n->next=NULL;//Gia na eimaste vevaioi oti o deiktis tou neou struct den deihnei kapou
        }
        else{//Anadromiki klisi gia to epomeno stoiheio tis listas
            eisagogi_se_lista(&((*head)->next),n);/*Ginetai pali klisi tis idias sunartisis
            kai sto orisma tis apothikeuei sti dieuthunsi tou deikti*/
        }
    }
}
/*I sunartisi auti psahnei ton pinaka b gia kratimenes theseis
kai tis eisagei sti lista*/
void dimiourgia_listas(bus_t b[],bus_t **head, int theseis){
    //Pali sto orisma vazoume me anafora to deikti-etsi pali vazoume diplo asteri(deiktis se deikti)
    int i;
    for(i=0;i<theseis;i++){
        if(b[i].name[0]!='\0'){
            eisagogi_se_lista(head,&(b[i]));
    //Stin klisi tis sunartisis sto orisma vazoume to deikti kai ti dieuthinsi tou struct pou antistoihei stis kratimenes theseis
        }
    }
}

//Akolouthei to soma tis voithitikis sunartisis eleghou an lista mas leitourgei sosta
//void print_lista(bus_t *head)
//{
//
//    if (head == NULL)
//    {
//        printf("adeia\n");
//    }
//    else
//    {
//        while(head != NULL)
//        {
//            printf("%s %d\n",head->name, head->th);
//            head = head->next;
//        }
//        //printf("%s %d",head->name, head->th);
//    }
//}
