#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct makan{
    int soto;
    int nasiputih;
    int pecel;
    int ikanbakar;
    int ayamgoreng;
}menu_makanan;

struct minum{
    int teh;
    int jus;
    int kopi;
    int airputih;
    int tehbotol;
}menu_minuman;

struct subtotal{
    int jmlbeli1,jmlbeli2,jmlbeli3,jmlbeli4,jmlbeli5,jmlbeli6,jmlbeli7,jmlbeli8,jmlbeli9,jmlbeli10;
    int totalharga, bayar, kembalian;
}sub;

struct tnode{
    char nama[100];
    struct makan menu_makanan;
    struct minum menu_minuman;
    struct subtotal sub;
    struct tnode *next;
    struct tnode *prev;
};

int login();
void hasing();
void daftarkan();
int cariid();
void logmenu();


struct user{
char id[10],pas[10];
};

int login(int *start){
struct user my[66];
int pil;
while(1){
logmenu(&pil);fflush(stdin);
if(pil==1){
    system("cls");
    printf("================ Daftar ================\n");
    printf(" Username: "); gets(my[50].id);fflush(stdin);
    printf(" Password: "); gets(my[50].pas);fflush(stdin);

    hasing(my);

    daftarkan(my);
    *start=1;
    printf("===  Daftar Akun Baru Succes !!!  ===");getchar();
}
if(pil==2){
    system("cls");
    printf("================ LOGIN ================\n");
    printf(" Username: "); gets(my[50].id);fflush(stdin);
    printf(" Password: "); gets(my[50].pas);fflush(stdin);

    hasing(my);
    cariid(my);
    for(int i=0;i<50;i++){

            if(strcmp(my[50].id,my[i].id)==0&&strcmp(my[50].pas,my[i].pas)==0){
                *start=1;
                printf("====  Login Succes !!!  ====\n");
                break;
            }
    }
    if(*start==0)printf("Akun Belum Terdaftar !!!\n");
    getchar();

}
if(*start==1)break;
}
}
void daftarkan(struct user *baru){
FILE *akun;
akun= fopen("akun.txt","a");

fprintf(akun,"%s#%s\n",baru[50].id,baru[50].pas);
fclose(akun);
}
int cariid(struct user *cari){
int i=0;
FILE *akun;
akun=fopen("akun.txt","r");
while(!feof(akun)){
fscanf(akun,"%[^#]#%[^\n]\n",&cari[i].id,&cari[i].pas);
fflush(stdin);
i++;
}
fclose(akun);
}

void hasing(struct user *x){
char abjat[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i=0;i<strlen(x[50].pas);i++){

        for(int j=0;j<26;j++){
            if(x[50].pas[i]==abjat[j]){
                x[50].pas[i]=abjat[j+3];
                break;
            }
        }
    }
}


void logmenu(int *x){
system("cls");
printf("======================== Restauran UMN ==========================\n");
printf("|                                                                |\n");
printf("| 1.)Daftar                                                      |\n");
printf("| 2.)Login                                                       |\n");
printf("=================================================================\n");
printf("Pilihan: ");scanf("%d",&(*x));
}


void tampilan_menu(){
    printf("\n\tSelamat datang di Warung Sederhana Universitas Multimedia Nusantara\n");
    printf("\t\t\tSilakan pilih menu yang Anda sukai:\n\n");
    printf("=====================================================================================\n");
    printf("|No.| Makanan \t\t|    Harga   |\t\t|No.| Minuman\t\t|   Harga   |\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("| 1 | Soto\t\t|  Rp. 15000 |\t\t| 6.| Teh\t\t| Rp.  3000 | \n");
    printf("| 2 | Nasi Putih\t|  Rp.  5000 |\t\t| 7.| Jus\t\t| Rp. 12000 |\n");
    printf("| 3 | Pecel\t\t|  Rp. 10000 |\t\t| 8.| Kopi\t\t| Rp.  5000 |\n");
    printf("| 4 | Ikan Bakar\t|  Rp. 18000 |\t\t| 9.| Air Mineral\t| Rp.  3000 |\n");
    printf("| 5 | Ayam Goreng\t|  Rp. 15000 |\t\t| 10| Teh Botol\t\t| Rp.  6000 |\n");
    printf("=====================================================================================\n");
}

void node_inisialisasi(struct tnode *node){
    node->menu_makanan.soto = 0;
    node->menu_makanan.nasiputih = 0;
    node->menu_makanan.pecel = 0;
    node->menu_makanan.ikanbakar = 0;
    node->menu_makanan.ayamgoreng = 0;
    node->menu_minuman.teh = 0;
    node->menu_minuman.jus = 0;
    node->menu_minuman.kopi = 0;
    node->menu_minuman.airputih = 0;
    node->menu_minuman.tehbotol = 0;
    node->sub.jmlbeli1 = 0;
    node->sub.jmlbeli2 = 0;
    node->sub.jmlbeli3 = 0;
    node->sub.jmlbeli4 = 0;
    node->sub.jmlbeli5 = 0;
    node->sub.jmlbeli6 = 0;
    node->sub.jmlbeli7 = 0;
    node->sub.jmlbeli8 = 0;
    node->sub.jmlbeli9 = 0;
    node->sub.jmlbeli10 = 0;
    node->sub.bayar = 0;
    node->sub.kembalian = 0;
    node->sub.totalharga = 0;
    node->sub.jmlbeli1 = 0;
}

void struk(struct tnode *node);
void program_linkedlist();
void display_linkedlist(struct tnode **head,struct tnode **tail);
int cari_pesanan(struct tnode **head);
void deletion_node(struct tnode **head, struct tnode **tail,struct tnode *node);
void menu_linkedlist(struct tnode **head,struct tnode **tail,struct tnode *node);

int main(){
    program_linkedlist();
    return 0;
}

void struk(struct tnode *node){
        time_t ambil_waktu;
        time(&ambil_waktu); //mengambil waktu saat ini
        system("cls");
        printf("=================================================================\n");
        printf("| \t\t\tWarung Sederhana UMN                   \t|\n");
        printf("| Jl. Scientia Boulevard, Gading, Kec. Serpong, Tangerang.\t|\n| \t\t\tBanten\t\t\t\t\t|\n");
        printf("| \t     Telp : (0274)14954 / 0812010101010                 |\n");
        printf("|_______________________________________________________________|\n");
        printf("| Nama Pesanan  | Harga Satuan  | Jumlah  | \t    Total  \t|\n");
        printf("|===============|===============|=========|=====================|\n");
        if(node->sub.jmlbeli1>0){
        	printf("|    Soto\t|     15000\t|    %d\t  |  Rp.%d\t\t|",node->menu_makanan.soto,node->sub.jmlbeli1);
        }
        if(node->sub.jmlbeli2>0){
        	printf("\n|    Nasi Putih\t|     5000\t|    %d\t  |  Rp.%d\t\t|",node->menu_makanan.nasiputih,node->sub.jmlbeli2);
        }
        if(node->sub.jmlbeli3>0){
       	 	printf("\n|    Pecel\t|     10000\t|    %d\t  |  Rp.%d\t\t|", node->menu_makanan.pecel,node->sub.jmlbeli3);
        }
        if(node->sub.jmlbeli4>0){
        	printf("\n|    Ikan Bakar\t|     18000\t|    %d\t  |  Rp.%d\t\t|",node->menu_makanan.ikanbakar,node->sub.jmlbeli4);
        }
        if(node->sub.jmlbeli5>0){
        	printf("\n|    Ayam Goreng\t|     15000\t|    %d\t  |  Rp.%d\t\t|",node->menu_makanan.ayamgoreng,node->sub.jmlbeli5);
        }
        if(node->sub.jmlbeli6>0){
        	printf("\n|    Teh\t|     3000\t|    %d\t  |  Rp.%d\t\t|",node->menu_minuman.teh,node->sub.jmlbeli6);
        }
		if(node->sub.jmlbeli7>0){
        	printf("\n|    Jus\t|     12000\t|    %d\t  |  Rp.%d\t\t|",node->menu_minuman.jus,node->sub.jmlbeli7);
        }
        if(node->sub.jmlbeli8>0){
        	printf("\n|    Kopi\t|     5000\t|    %d\t  |  Rp.%d\t\t|",node->menu_minuman.kopi,node->sub.jmlbeli8);
        }
        if(node->sub.jmlbeli9>0){
        	printf("\n|    Air Mineral\t|     3000\t|    %d\t  |  Rp.%d\t\t|",node->menu_minuman.airputih,node->sub.jmlbeli9);
        }
        if(node->sub.jmlbeli10>0){
        	printf("\n|    Teh Botol\t|     6000\t|    %d\t  |  Rp.%d\t\t|",node->menu_minuman.tehbotol,node->sub.jmlbeli10);
        }
        printf("\n|_______________________________________________________________|");
        printf("\n| Total Harga       = %d\t\t\t\t\t|", node->sub.totalharga);
        printf("\n| Uang bayar        = %d\t\t\t\t\t|", node->sub.bayar);
        printf("\n| Kembalian         = %d\t\t\t\t\t|", node->sub.kembalian);
    	printf("\n|---------------------------------------------------------------|\n");
		printf("    Waktu/Hari 	: %s", ctime (&ambil_waktu));
        printf("\n|---------------------------------------------------------------|\n");
}

void display_linkedlist(struct tnode **head,struct tnode **tail){
    struct tnode *node;
    node = (*head);
    int i;
    if(node == NULL){
        printf("\t\tTIDAK ADA PESANAN\n");
        getchar();
    }
    while(node != NULL){
        system("cls");
        printf("\t\tPesanan Atas Nama %s\n", node->nama);
        printf("-----------------------------------------------------\n");
        printf("Pesanan Makanan\n");
        printf("\tJumlah  | Nama Makanan      | Total Harga\n");
        printf("\t===========================================\n");
        printf("\t   %d   : Soto              : Rp. %d \n",node->menu_makanan.soto, node->sub.jmlbeli1);
        printf("\t   %d   : Nasi Putih        : Rp. %d \n",node->menu_makanan.nasiputih, node->sub.jmlbeli2);
        printf("\t   %d   : Pecel             : Rp. %d \n",node->menu_makanan.pecel, node->sub.jmlbeli3);
        printf("\t   %d   : Ikan Bakar        : Rp. %d \n",node->menu_makanan.ikanbakar, node->sub.jmlbeli4);
        printf("\t   %d   : Ayam Goreng       : Rp. %d \n",node->menu_makanan.ayamgoreng, node->sub.jmlbeli5);
        printf("\t--------------------------------------------\n\n");
        printf("Pesanan Minuman \n");
        printf("\t===========================================\n");
        printf("\tJumlah  | Nama Minuman      | Total Harga\n");
        printf("\t   %d   : Teh               : Rp. %d \n",node->menu_minuman.teh, node->sub.jmlbeli6);
        printf("\t   %d   : Jus               : Rp. %d \n",node->menu_minuman.jus, node->sub.jmlbeli7);
        printf("\t   %d   : Kopi              : Rp. %d \n",node->menu_minuman.kopi, node->sub.jmlbeli8);
        printf("\t   %d   : Air Mineral       : Rp. %d \n",node->menu_minuman.airputih, node->sub.jmlbeli9);
        printf("\t   %d   : Teh Botol         : Rp. %d \n",node->menu_minuman.tehbotol, node->sub.jmlbeli10);
        printf("\t-------------------------------------------\n");
        printf("\n===============================\nTotal Harga adalah = Rp.%d,-\n===============================\n",node->sub.totalharga);
        printf("=====================================================\n");
        pesanan:
        printf("1. Pesanan Selanjutnya\n");
        printf("2. Pesanan Sebelumnya\n");
        printf("3. Exit\n");
        printf("Lihat Pesanan : ");scanf("%d", &i);
        if(i == 1){
            if(node->next == NULL){
                node = (*head);
                i = 1;
            }else{
                i++;
                node = node->next;
            }
        }else if(i == 2){
            if(node->prev == NULL){
                node = (*tail);
                i = 0;
            }else{
                i--;
                node = node->prev;
            }
        }else if(i == 3){
            return;
        }else{
            goto pesanan;
        }
    }
}

void deletion_node(struct tnode **head, struct tnode **tail,struct tnode *node){//free up node
    if((*head) == (*tail)){
        free(node);
        (*head) = NULL;
        (*tail) = NULL;
    }else if((*head) == node){
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        free(node);
    }else if((*tail) == node){
        (*tail) = (*tail)->prev;
        (*tail)->next = NULL;
        free(node);
    }
    else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        free(node);
    }
    return;
}

int cari_pesanan(struct tnode **head){
    struct tnode *node;
    node = (*head);
    char bayar;
    char namapelanggan[100];
    printf("Cari Pesanan Atas Nama : ");scanf("%s", &namapelanggan);
    if(namapelanggan[0] >= 'a' && namapelanggan[0] <= 'z'){
        namapelanggan[0] = namapelanggan[0]-32;
    }
    for(int i=1;i<100;i++){
        if(namapelanggan[i]>='A' && namapelanggan[i]<='Z'){
            namapelanggan[i] = namapelanggan[i]+32;
        }
    }
    while(node != NULL){
        if(strcmp(node->nama,namapelanggan) == 0){
            printf("Pesanan Atas Nama %s berhasil ditemukan!!\n", node->nama);
            printf("Total Biaya Pemesanan Rp. %d\n", node->sub.totalharga);
            getch();
            //system("PAUSE");
            return 1;
        }else{
            node = node->next;
            return 0;
        }
    }
    printf("Pesanan Tidak Ditemukan\n");
}

void program_linkedlist(){
    struct tnode *head,*tail,*node;
    int input,start=0;
    char bayar;
    head = tail = NULL;

    login(&start);
    if(start==1){
    //node = (struct tnode*) malloc(sizeof(struct tnode));
    //node_inisialisasi(node);

    do{
        system("cls");
        printf("Linked List Program : Pemesanan dan Pembayaran Restoran\n");
        printf("==============================================================\n");
        printf("1. Pesan Makanan dan Minuman\n");
        printf("2. Tampilkan Pesanan\n");
        printf("3. Cari Pesanan\n");
        printf("4. Bayar Pesanan\n");
        printf("5. Urutkan Pesanan\n");
        printf("0. Exit\n");
        printf("Input Pilihan : ");scanf("%d", &input);
        switch(input){
            case 1 :
                system("cls");
                menu_linkedlist(&head,&tail,node);
                break;
            case 2 :
                display_linkedlist(&head,&tail);
                break;
            case 3 :
                cari_pesanan(&head);
                break;
            case 4 :
                //cari_pesanan(&head);
                if(cari_pesanan(&head)){
                    printf("Bayar Pesanan? (y/n) ");fflush(stdin);scanf("%c", &bayar);
                    if(bayar == 'y' || bayar == 'Y'){
                        node = head;
                        pembayaran:
                        printf("Masukkan Jumlah Uang Untuk Melakukan Pembayaran : ");scanf("%d", &node->sub.bayar);
                        if(node->sub.bayar >= node->sub.totalharga){
                            node->sub.kembalian = node->sub.bayar - node->sub.totalharga;
                            printf("Kembalian : Rp. %d", node->sub.kembalian);
                            getch();
                            struk(node);
                            deletion_node(&head,&tail,node);
                            system("PAUSE");
                        }else{
                            printf("Uang Tidak Mencukupi!!!\n");
                            goto pembayaran;
                        }
                    }
                }else{
                    printf("Nama Pemesan Tidak Ada\n");getch();
                }
                break;
        }
    }while(1);
    }
}

void menu_linkedlist(struct tnode **head,struct tnode **tail,struct tnode *node){
    int pilih,pelanggan;
    char yakin,ingin;
    char namapelanggan[100];
    pemesan_selanjutnya:
    do{
        system("cls");
        tampilan_menu();
        printf("Ingin Memesan Makanan (y/n)? ");fflush(stdin);scanf("%c", &ingin);
        if(ingin == 'y' || ingin == 'Y'){
            printf("Pesanan Atas Nama : ");scanf("%s",&namapelanggan);
            if(namapelanggan[0] >= 'a' && namapelanggan[0] <= 'z'){
                 namapelanggan[0] = namapelanggan[0]-32;
            }
            for(int i=1;i<100;i++){
                if(namapelanggan[i]>='A' && namapelanggan[i]<='Z'){
                    namapelanggan[i] = namapelanggan[i]+32;
                }
            }
            node = (struct tnode*) malloc(sizeof(struct tnode));
            node_inisialisasi(node);
            strcpy(node->nama,namapelanggan);
            pelanggan = 1;
        }else if(ingin == 'n' || ingin == 'N'){
            pelanggan = 0;
        }else{
            printf("Permintaan tidak dikenal\n");
            break;
        }
        if(pelanggan == 0){
            break;
        }else{
            while(pelanggan == 1){
                if(pelanggan == 1){
                    system("cls");
                    tampilan_menu();Pilih_Menu:
                    printf("Nama Pemesan : %s\n", namapelanggan);
                    do{
                        printf("Pilih Menu : ");scanf("%d",&pilih);
                        if(pilih == 1){
                            printf("[1] Pemesanan Soto\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_makanan.soto);
                            printf("=============================================\n");
                            node->sub.jmlbeli1 = node->menu_makanan.soto*15000;
                        }else if(pilih == 2){
                            printf("[2] Pemesanan Nasi Putih\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_makanan.nasiputih);
                            printf("=============================================\n");
                            node->sub.jmlbeli2 = node->menu_makanan.nasiputih*5000;
                        }else if(pilih == 3){
                            printf("[3] Pemesanan Pecel\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_makanan.pecel);
                            printf("=============================================\n");
                            node->sub.jmlbeli3 =  node->menu_makanan.pecel*10000;
                        }else if(pilih == 4){
                            printf("[4] Pemesanan Ikan Bakar\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_makanan.ikanbakar);
                            printf("=============================================\n");
                            node->sub.jmlbeli4 = node->menu_makanan.ikanbakar*18000;
                        }else if(pilih == 5){
                            printf("[5] Pemesanan Ayam Goreng\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_makanan.ayamgoreng);
                            printf("=============================================\n");
                            node->sub.jmlbeli5 = node->menu_makanan.ayamgoreng*15000;
                        }else if(pilih == 6){
                            printf("[6] Pemesanan Teh\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_minuman.teh);
                            printf("=============================================\n");
                            node->sub.jmlbeli6 = node->menu_minuman.teh*3000;
                        }else if(pilih == 7){
                            printf("[7] Pemesanan Jus\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_minuman.jus);
                            printf("=============================================\n");
                            node->sub.jmlbeli7 = node->menu_minuman.jus*12000;
                        }else if(pilih == 8){
                            printf("[8] Pemesanan Kopi\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_minuman.kopi);
                            printf("=============================================\n");
                            node->sub.jmlbeli8 = node->menu_minuman.kopi*5000;
                        }else if(pilih == 9){
                            printf("[9] Pemesanan Air Mineral\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_minuman.airputih);
                            printf("=============================================\n");
                            node->sub.jmlbeli9 = node->menu_minuman.airputih*3000;
                        }else if(pilih == 10){
                            printf("[10] Pemesanan Teh Botol\n");
                            printf("Jumlah Pesanan : ");scanf("%d", &node->menu_minuman.tehbotol);
                            printf("=============================================\n");
                            node->sub.jmlbeli10 = node->menu_minuman.tehbotol*6000;
                        }else{
                            printf("Pesanan tidak ada dalam menu\n");
                            printf("Akhiri Pemesanan (y/n)? ");fflush(stdin);scanf("%c", &yakin);
                            if(yakin == 'y' || yakin == 'Y'){
                                printf("~~Pesanan Akan Segera Di Hidangkan~~\n");
                                node->sub.totalharga = node->sub.jmlbeli1 + node->sub.jmlbeli2 + node->sub.jmlbeli3 + node->sub.jmlbeli4 + node->sub.jmlbeli5 + node->sub.jmlbeli6 + node->sub.jmlbeli7 + node->sub.jmlbeli8 + node->sub.jmlbeli9 + node->sub.jmlbeli10;
                                getchar();
                                node->next = NULL;
                                node->prev = NULL;
                                if((*head) == NULL){
                                    (*tail) = node;
                                    (*head) = node;
                                }else{
                                    (*head)->prev = node;
                                    node->next = (*head);
                                    (*head) = node;
                                    (*head)->prev = NULL;
                                }
                                pelanggan = 0;
                                goto pemesan_selanjutnya;
                            }else if(yakin == 'n' || yakin == 'N'){
                                pelanggan = 1;
                                goto Pilih_Menu;
                            }
                        }
                    }while(pilih < 11);
                }
            }
        }
    }while(pelanggan == 1);
}
