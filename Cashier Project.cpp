#include <iostream>
#include <conio.h>
#include <ctime>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//ALGORITMA PROGRAM KASIR S-MART
/*
1.Pemilihan Kasir
2.Melakukan Log In ke dalam sistem
3.Memasukan barang yang ingin dibeli
4.Menentukan apakah pelanggan seorang member/non-member
    jika member mendapatkan diskon 5%
5.Checkout.
*/

//Number Randomizer Function
int numberRandomizer()
{
    int i, number;
    time_t nTime;
    number = 5;

    srand((unsigned) time(&nTime));
    for( i = 0 ; i < number ; i++ )
    {printf("%d", rand() % 1000);}

    return(0);
}

//Number Separator Function
string thousandSeparator(int n)
{
    string ans = "";
    string num = to_string(n);
    int count = 0;

    for (int i = num.size() - 1; i >= 0; i--)
    {count++;ans.push_back(num[i]);
        if (count == 3)
            {ans.push_back('.');count = 0;}
    }

    reverse(ans.begin(), ans.end());

        if (ans.size() % 4 == 0)
            {ans.erase(ans.begin());}

    return ans;
}

//Checkout Function
int checkout(int sum,string nama,string NIM)
{
    int uang,x;
    double discount;
    string desc,mem;
    time_t now = time(0);
    char* dt = ctime(&now);

    cout<<"========================================="<<endl;
    cout<<"\n1.member \n2.non member \n"<<endl;
    cout<<"========================================="<<endl;

    disk:
    cin>>mem;
    if (mem=="1")
    {discount=0.95;desc="     Discount -5%";}
        else if(mem=="2")
        {discount=1;desc="      No Discount";}
    else
    {cout<<"Angka yang anda input salah, silahkan pilih ulang\n";goto disk;}

    system ("cls");
    cout<<"                CHECK-OUT                 \n\n"<<endl;
    cout<<"                 S'-MART                    \n"<<endl;
    cout<<"     Sekaran Gunung Pati, Semarang     \n";
    cout<<"         2256, Semarang, 50229         \n";
    cout<<"\n \t\t "<< dt ;
    cout<<"========================================="    <<endl;
    cout<<nama                                           <<endl;
    cout<<NIM                                            <<endl;
    cout<<"========================================= \n";
    cout<<"\nRECEIPT \n";
    cout<<"----------------------------------------- \n";
    cout<<"\t\t\tTOTAL = Rp "<<thousandSeparator(sum)<<"\n";
    cout<<"\t\t\t"<<desc<<"\n";
    cout<<"\t\t\t      = Rp "<<thousandSeparator(sum*discount)<<"\n";
    cout<<"-----------------------------------------   \n";
    cout<<"Order ID: "<<numberRandomizer()<<"\n\n";
    cout<<"TUNAI\t\t\t\tRp ";cin>>uang;
    cout<<"\n\nKembalian = Rp "<<thousandSeparator(uang-(sum*discount))<<"\n";
    cout<<"----------------------------------------- \n";
    cout<<" Terima-kasih Telah Berbelanja di S-MART \n\n";
    cout<<"=========Layanan Konsumen S-MART=========\n";
    cout<<"     Customer Sevice: 0812-8743-8888 \n";
    cout<<"SMS: 0812-1137-2321  CALL: 0812-8722-8836"     <<endl;
    cout<<"       E-MAIL: KONTAK@S-MART.CO.ID       "     <<endl;

    getch();
    exit(0);
    return 0;
}

//Menu Function
int menuKeranjang(string nama,string NIM)
{
    int harga,jumlah,total;
    double sum = 0.0;
    string barang,benda;

    int N=50;

    string daftarMenu[N]={"Amplop dus isi 50"
                        ,"Beras 10kg","Beras 5kg","Boardmarker Snowman","Buku A5 Sidu 34hal"
                        ,"Buku A5 Sidu 74hal","Buku B5 Sidu 46hal","Glue Stick Kenko"
                        ,"Indomie Ayam Bawang","Indomie Goreng","Indomie Goreng Hype Abiss"
                        ,"Indomie Soto Ayam","Kental Manis Kaleng","Kental Manis Sachet"
                        ,"Masker Duckbill isi 5","Masker Jilbab isi 5","Masker KN94 isi 2"
                        ,"Masker Standar","Notebook Besar Sidu","Notebook Kecil Sidu"
                        ,"Nugget Bintang isi 30","Nugget Bintang isi 50","Penghapus karet kenko"
                        ,"Pensil Tulis isi 3","Pepsodent Besar","Pepsodent Kecil","Pulpen biru isi 3"
                        ,"Pulpen hitam isi 3","Pulpen merah isi 3","Rokok Gudang Garam Surya"
                        ,"Rokok Marlboro","Roti Panggang Sosis","Roti Sandwich Coklat","Roti Sandwich Keju"
                        ,"Roti Tawar isi 20","Silverqueen 120gr","Silverqueen 65gr","Sosis Bintang isi 15"
                        ,"Sosis So Nice isi 20 rasa Ayam","Sosis So Nice isi 20 rasa Sapi","Sticky Note"
                        ,"Susu Bear Brand","Teh Kotak 150ml","Teh Kotak isi 250ml","Ultramilk Fullcream 1000ml"
                        ,"Ultramilk Fullcream 250ml","Ultramilk rasa Coklat 1000ml","Ultramilk rasa Coklat 250ml"
                        ,"Ultramilk rasa Vanilla 1000ml","Ultramilk rasa Vanilla 250ml"};

    string harga_barang[N]={"17.000","70.000","40.000","8.000","3.500","5.000","5.000","4.000","2.200"
                            ,"2.500","2.800","2.300","12.000","10.000","8.000","8.000","12.000","8.000"
                            ,"14.000","8.500","28.000","43.000","5.000","8.000","11.000","8.000","7.000"
                            ,"7.000","7.000","26.000","33.000","8.000","5.000","5.000","10.000","24.000"
                            ,"18.000","12.000","15.000","16.000","5.000","9.000","4.000","5.500","19.000"
                            ,"6.000","19.000","6.000","19.000","6.000"};


    daftar_menu:
    cout<<"                        MENU:                   \n"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    for(int i=0; i<=N-1; i++)
    {cout<<"Rp "<<harga_barang[i]<<"\t";cout<<i+1<<". "<<daftarMenu[i]<<"\n";
    }
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Untuk Checkout, pilih 0";
    cout<<"\nTotal Belanja Saat ini: Rp "<<thousandSeparator(sum)<<endl;

    menu:
        do{

        cout<<"\nPilih barang: ";cin>>barang;


        if      (barang=="1"){benda="Amplop dus isi 50";harga = 17000;}
        else if (barang=="2"){benda="Beras 10kg";harga = 70000;}
        else if (barang=="3"){benda="Beras 5kg";harga = 40000;}
        else if (barang=="4"){benda="Boardmarker Snowman";harga = 8000;}
        else if (barang=="5"){benda="Buku A5 Sidu 34hal";harga = 3500;}
        else if (barang=="6"){benda="Buku A5 Sidu 74hal";harga = 5000;}
        else if (barang=="7"){benda="Buku B5 Sidu 46hal";harga = 5000;}
        else if (barang=="8"){benda="Glue Stick Kenko";harga = 4000;}
        else if (barang=="9"){benda="Indomie Ayam Bawang"; harga = 2200;}
        else if (barang=="10"){benda="Indomie Goreng"; harga = 2500;}
        else if (barang=="11"){benda="Indomie Goreng Hype Abis"; harga = 2800;}
        else if (barang=="12"){benda="Indomie Soto Ayam";harga = 2300;}
        else if (barang=="13"){benda="Kental Manis Kaleng";harga = 12000;}
        else if (barang=="14"){benda="Kental Manis Sachet"; harga = 10000;}
        else if (barang=="15"){benda="Masker Duckbill isi 5"; harga = 15000;}
        else if (barang=="16"){benda="Masker Jilbab isi 5"; harga = 8000;}
        else if (barang=="17"){benda="Masker KN94 isi 2"; harga = 12000;}
        else if (barang=="18"){benda="Masker Standar"; harga = 8000;}
        else if (barang=="19"){benda="Notebook Besar Sidu";harga = 14000;}
        else if (barang=="20"){benda="Notebook Kecil Sidu";harga = 8500;}
        else if (barang=="21"){benda="Nugget bintang isi 30"; harga = 28000;}
        else if (barang=="22"){benda="Nugget bintang isi 50"; harga = 43000;}
        else if (barang=="23"){benda="Penghapus karet kenko";harga = 5000;}
        else if (barang=="24"){benda="Pensil Tulis isi 3";harga = 8000;}
        else if (barang=="25"){benda="Pepsodent besar"; harga = 11000;}
        else if (barang=="26"){benda="Pepsodent kecil"; harga = 8000;}
        else if (barang=="27"){benda="Pulpen biru isi 3";harga = 7000;}
        else if (barang=="28"){benda="Pulpen hitam isi 3";harga = 7000;}
        else if (barang=="29"){benda="Pulpen merah isi 3";harga = 7000;}
        else if (barang=="30"){benda="Rokok Gudang Garam Surya";harga = 26000;}
        else if (barang=="31"){benda="Rokok Marlboro";harga = 33000;}
        else if (barang=="32"){benda="Roti Panggang Sosis"; harga = 8000;}
        else if (barang=="33"){benda="Roti Sandwich coklat"; harga = 5000;}
        else if (barang=="34"){benda="Roti Sandwich Keju"; harga = 5000;}
        else if (barang=="35"){benda="Roti Tawar isi 20"; harga = 15000;}
        else if (barang=="36"){benda="Silverqueen 65gram"; harga = 18000;}
        else if (barang=="37"){benda="Silverqueen 120gram"; harga = 24000;}
        else if (barang=="38"){benda="Sosis bintang isi 15"; harga = 12000;}
        else if (barang=="39"){benda="Sosis So Nice isi 20 rasa Ayam"; harga = 15000;}
        else if (barang=="40"){benda="Sosis So Nice isi 20 rasa Sapi"; harga = 16000;}
        else if (barang=="41"){benda="Sticky Note";harga = 5000;}
        else if (barang=="42"){benda="Susu Bear Brand"; harga = 9000;}
        else if (barang=="43"){benda="Teh Kotak 150ml"; harga = 4000;}
        else if (barang=="44"){benda="Teh Kotak 250ml"; harga = 5500 ;}
        else if (barang=="45"){benda="Ultramilk Fullcream 1000ml"; harga = 19000;}
        else if (barang=="46"){benda="Ultramilk Fullcream 250ml"; harga = 6000;}
        else if (barang=="47"){benda="Ultramilk rasa Coklat 1000ml"; harga = 19000;}
        else if (barang=="48"){benda="Ultramilk rasa Coklat 250ml"; harga = 6000;}
        else if (barang=="49"){benda="Ultramilk rasa Vanilla 1000ml"; harga = 19000;}
        else if (barang=="50"){benda="Ultramilk rasa Vanilla 250ml"; harga = 6000;}
        else if (barang=="0"){checkout(sum,nama,NIM);}
        else    {cout<<"barang tidak ada, silahkan memilih ulang \n"<<endl;goto menu;}

        cout<<benda<<" Rp "<<thousandSeparator(harga)<<endl;
        cout<<"Jumlah barang yang di inginkan: ";cin>>jumlah;

        total = harga * jumlah;

        cout<<".....x"<<jumlah<<" = Rp "<<thousandSeparator(total)<<endl;
        sum += (total);

        getch();
        system ("cls");
        goto daftar_menu;

        }while(barang != "0");
        cout<<"\n================================================="<<endl;

        return 0;
}

//Password Procedure
void Password(string nama)
{
    string Password,PIN;
    cout<<"===========================================\n"<<endl;
    cout<<"      Masukan Username dan PIN anda\n";
    cout<<"\n==========================================="<<endl;
    pass:
    cout<<"Password: ";cin>>Password;
    cout<<"PIN     : ";cin>>PIN;
    cout<<"==========================================="<<endl;

    if(nama=="Muhammad Dylan Hikma Sanjaya" && Password=="jaynotdylan" && PIN=="123456")
        {cout<<"\nPassword is Correct\n"<<endl;
        getch();
        system ("cls");}
        else if(nama=="Yassar Ghinata" && Password=="yassar123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
        else if(nama=="Stefan Enrico Joel Manurung" && Password=="stefan123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
        else if(nama=="Alya Nur Afifa" && Password=="alya123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
        else if(nama=="Satria Imawan" && Password=="satria123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
        else if(nama=="Awangga Surya Atmaja" && Password=="surya123" && PIN=="123456")
            {cout<<"\nPassword is Correct\n"<<endl;
            getch();
            system ("cls");}
    else
    {cout<<"Password atau PIN salah, coba lagi\n==========================================="<<endl;goto pass;}
}

//Main Program
int main()
{

    string cashier,nama,NIM;
    string kasir[6]={"Dylan","Yassar","Stefan","Alya","Satria","Surya"};
    system("color F0");

    cout<<"==================S-MART==================="<<endl;
    cout<<"\nPilih Kasir:\n"<<endl;

    for(int i=0; i<=6-1; i++)
    {cout<<i+1<<". "<<kasir[i]<<"\n";}

    cout<<"\n==========================================="<<endl;

    x:
    cin>>cashier;
    if(cashier=="1")
    {nama="Muhammad Dylan Hikma Sanjaya";       NIM="4612421028";}
        else if(cashier=="2")
        {nama="Yassar Ghinata";                 NIM="4612421010";}
        else if(cashier=="3")
        {nama="Stefan Enrico Joel Manurung";    NIM="4612421045";}
        else if(cashier=="4")
        {nama="Alya Nur Afifa";                 NIM="4612421002";}
        else if(cashier=="5")
        {nama="Satria Imawan";                  NIM="4612421050";}
        else if(cashier=="6")
        {nama="Awangga Surya Atmaja";           NIM="4612421042";}
    else
    {cout<<"Tidak ada kasir "<<cashier<<"silahkan pilih ulang"<<endl; goto x;}

        Password(nama);
        menuKeranjang(nama,NIM);
        return 0;
}



