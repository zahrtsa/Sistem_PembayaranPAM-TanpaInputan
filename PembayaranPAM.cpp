/*TUGAS BESAR: Algoritma dan Pemograman A(Group2)
  Program - SI Pembayaran PAM (TanpaInputan)
                              (SelectionSort-Ascending)
  Zahra - 4523210145
*/
#include <iostream> //library cin/cout
#include <fstream> //library file
#include <iomanip> //library stew
#include <windows.h> //library sistem windows
#include <string.h> //library string
#define JUMLAH_BULAN 12 //nyatakan variable penyimpan array bernilai 12
using namespace std;

void lihatRekapTahunLalu() {
	int R, t, s = 0, h, z;
	int totalTagihanPemakaianAir = 0,
		totalTerlambat = 0;
    int bulan[JUMLAH_BULAN] = {12,3,4,5,6,8,2,11,10,7,1,9},
		pakaiAir[JUMLAH_BULAN] = {4,5,6,7,8,42,4,10,49,34,11,20};
	int tagihanAir[JUMLAH_BULAN], tagihanPakaiAir[JUMLAH_BULAN];
    char bayar[JUMLAH_BULAN][10] = {"CASH","BCA","BRI","CASH", //menyimpan data pada array 2 dimensi
									"BRI","CASH","BCA","CASH",
									"BCA","BCA","BRI","CASH"};
    string tanggal[JUMLAH_BULAN] = {"04-01-2023","29-02-2023","17-03-2023","05-04-2023",
									"18-05-2023","20-06-2023","01-07-2023","03-08-2023",
									"30-09-2023","26-10-2023","27-11-2023","10-12-2023"};
    string status[JUMLAH_BULAN] = {"TEPAT WAKTU","TERLAMBAT(!)","TEPAT WAKTU","TEPAT WAKTU",
									"TEPAT WAKTU","TEPAT WAKTU","TEPAT WAKTU","TEPAT WAKTU",
									"TERLAMBAT(!)","TEPAT WAKTU","TERLAMBAT(!)","TEPAT WAKTU"};
									

    /*Sistem proses SelectionSort-Ascending untuk mengurutkan
	  data berdasarkan variable array*/
    while (s < JUMLAH_BULAN - 1) {
        t = s;
        R = s + 1;
        while (R < JUMLAH_BULAN) {
            if (bulan[R] < bulan[t])
                t = R;
            R++;
        }

        h = bulan[t];
        bulan[t] = bulan[s];
        bulan[s] = h;
        s++;
    }
	
	//Menampilkan rekapan pembayaran tahun lalu
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"                            ------------------------ REKAPAN PEMBAYARAN PAM TAHUN 2023 ----------------------------------                      "<<endl;
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Nama Pelanggan          : ZAHRA TSABITAH"<<endl;
	cout<<"Alamat  Pelanggan       : JL. PAM BARU RAYA NO.7A"<<endl;
	cout<<"ID Pelanggan            : 45-23-2-101-45"<<endl;
	cout<<"Jenis Golongan          : Rumah Tangga"<<endl; 
	//menampilkan header
	cout << setfill('-') << setw(124) << "-" << endl; // garis pembatas otomatis
		cout << setfill(' '); // mengembalikan karakter pengisi ke spasi
		//header judul diratakan dengan setw untuk merapihkan tabel
		 cout << "| " << setw(6) << left << "Bulan"   
			 << "| " << setw(15) << left << "Pemakaian Air" 
			 << "| " << setw(12) << left << "Tagihan Air" 
			 << "| " << setw(22) << left << "Tagihan Pemakaian Air" 
			 << "| " << setw(19) << left << "Tanggal Pembayaran" 
			 << "| " << setw(18) << left << "Status Pembayaran" 
			 << "| " << setw(17) << left << "Metode Pembayaran" << "|" <<endl; 
		cout << setfill('-') << setw(124) << "-" << endl; // garis pembatas otomatis
		cout << setfill(' ');

	/*Sistem proses menampilkan data berdasarkan array looping
	  variable z sebagai patokan*/
    for (z = 0; z < JUMLAH_BULAN; z++) {
		//sistem menghitung biaya
		if(pakaiAir[z] <= 35){
			tagihanAir[z] = 7450;
			tagihanPakaiAir[z] = pakaiAir[z] * tagihanAir[z] + 1195 + 3000;
		} else {
			tagihanAir[z] = 8250;
			tagihanPakaiAir[z] = pakaiAir[z] * tagihanAir[z] + 2400 + 3000;
		}
		
		/* - Menambahkan biaya denda jika terlambat
		   - menghitung berapa kali terlambat*/
		if(status[z] == "TERLAMBAT(!)"){
			tagihanPakaiAir[z] += 5000;
			totalTerlambat++;
		}
		
	 cout << setw(4.5) << "| " << setw(4.5) << bulan[z]
		//menggunakan fungsi string untuk mengubah tipedata menjadi string
         << setw(7.5) << "| " << setw(10) << to_string(pakaiAir[z]) + "m3" 
         << setw(4) << "| " << "Rp" << setw(8) << tagihanAir[z]
         << setw(9) << "| " << "Rp" << setw(13) << tagihanPakaiAir[z]
         << setw(6.5) << "| " << setw(15) << tanggal[z]
         << setw(4.5) << "| " << setw(16) << status[z]
         << setw(7.5) << "| " << setw(12) << bayar[z] << "|" << endl;
		
		/*hitung total tagihan pemakaian air dengan operator penugasan yang bertugas 
		untuk Pengisian dan Penambahan variable dinyatakan dengan symbol += */
        totalTagihanPemakaianAir += tagihanPakaiAir[z];
	}
	cout << setfill('-') << setw(124) << "-" << endl; // garis pembatas otomatis
	//menampilkan footer
	cout << setfill(' ');
	cout << " TOTAL TAGIHAN PEMAKAIAN AIR 1.THN : " << "Rp" << totalTagihanPemakaianAir << endl;
    cout << " TOTAL KETERLAMBATAN PEMBAYARAN    : " << totalTerlambat << " kali" << endl;
	cout << setfill('-') << setw(124) << "-" << endl; // garis pembatas otomatis
	cout << setfill(' ');
}

void PembayaranBulanIni(){
	const char *bayar[] = {"BRI", "BCA", "CASH"}; //deklarasi array dari pointer ke kontanta string 
	char nama[50] = "Zahra Tsabitah", //Menyimpan data pada array 1 dimensi
		alamat[50] = "Jl. Pam Baru Raya No.7a",
		ID[50] = "45-23-2-101-45",
		jenis[50] = "Rumah Tangga",
		tanggal[50] = "2 Januari 2024",
	    code[25];
	int pakaiAir = 34,
	    tagihanAir,
		tagihanPakaiAir,
		metode,
		panjang_array;

    srand(time(0));
	panjang_array = sizeof(bayar) / sizeof(bayar[0]); //menghitung panjang character array
    metode = rand() % panjang_array; //menghasilkan kata random pada data yang ada di dalam variable bayar

	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"                              ------------------------ PEMBAYARAN PAM BULAN INI ----------------------------------                               "<<endl;
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Nama Pelanggan          : ..."<<endl;
	    Sleep(2000);cout << "\x1b[1A\x1b[2K";
	    cout<<"Nama Pelanggan          : "<<strupr(nama)<<endl; //string untuk huruf besar semua
	cout<<"Alamat  Pelanggan       : ..."<<endl;
	    Sleep(2000);cout << "\x1b[1A\x1b[2K";
	    cout<<"Alamat  Pelanggan       : "<<strupr(alamat)<<endl; // str-> string upr-> upper
	cout<<"ID Pelanggan            : ..."<<endl;
	    Sleep(2000);cout << "\x1b[1A\x1b[2K";
	    cout<<"ID Pelanggan            : "<<ID<<endl;
	cout<<"Jenis Golongan          : ..."<<endl;
	    Sleep(2000);cout << "\x1b[1A\x1b[2K";
	    cout<<"Jenis Golongan          : "<<jenis<<endl; 
	cout<<"Tanggal                 : ..."<<endl;
	    Sleep(2000);cout << "\x1b[1A\x1b[2K";
		cout<<"Tanggal                 : "<<tanggal<<endl;
	cout<<"Pemakaian Air (m3)      : ..."<<endl;
	    Sleep(2000);cout << "\x1b[1A\x1b[2K";
		cout<<"Pemakaian Air (m3)      : "<<pakaiAir<<"m3"<<endl;
	cout<<"Sistem Pembayaran(CASH/BRI/BCA)  : ..."<<endl;
		Sleep(2000);cout << "\x1b[1A\x1b[2K";
		cout<<"Sistem Pembayaran       : "<< bayar[metode]<<endl;
		
	//sistem penghitung tagihanAir dan tagihanPakaiAir
	if(pakaiAir <= 35){
		tagihanAir = 7450;
		tagihanPakaiAir = pakaiAir * tagihanAir + 1195 + 3000;
	} else {
		tagihanAir = 9550;
		tagihanPakaiAir = pakaiAir * tagihanAir + 2400 + 3000;
	}
	
	if(bayar[metode] == "BRI"){
		tagihanPakaiAir += 2500;
		strcpy(code, "0097 8823 2791 1111 0273"); //copy nilai string ke variable code
	}else if (bayar[metode] == "BCA"){
		tagihanPakaiAir += 2500;
		strcpy(code, "4444 6793 8712 0853 4365");
	}else{
		strcpy(code, "-");
	}
	
	//cetak tagihan pembayaran
	cout<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"---------------TAGIHAN PEMBAYARAN AIR------------------"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"Pemakaian Air (m3)      : "<<pakaiAir<<"m3"<<endl;
	cout<<"Tagihan Air             : "<<tagihanAir<<endl;
	cout<<"Biaya Admin             : "<<"Rp3000"<<endl;
	cout<<"Biaya Pajak             : "<<"Rp1195"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"TOTAL TAGIHAN PEMAKAIAN AIR  : Rp"<<tagihanPakaiAir<<endl;
	cout<<"SISTEM PEMBAYARAN            : "<<bayar[metode]<<endl;
	cout<<"CODE PEMBAYARAN              : "<<code<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	
    ofstream file("TAGIHAN_PEMBAYARAN.txt"); // membuka/membuat file "TAGIHAN_PEMBAYARAN"
    if (file.is_open()) { //nyatakan kondisi apakah file terbuka
		//Masukan seluruh data kedalam file
        file << "-------------------------------------------------------" << endl;
        file << "---------------TAGIHAN PEMBAYARAN AIR------------------" << endl;
        file << "-------------------------------------------------------" << endl;
        file << setw(25) << left << "Nama Pelanggan"              << ": " << strupr(nama) << endl;
        file << setw(25) << left << "Alamat Pelanggan"            << ": " << strupr(alamat) << endl;
        file << setw(25) << left << "ID Pelanggan"                << ": " << ID << endl;
        file << setw(25) << left << "Jenis Golongan"              << ": " << jenis << endl;
        file << setw(25) << left << "Tanggal"                     << ": " << tanggal << endl;
        file << setw(25) << left << "Pemakaian Air (m3)"          << ": " << pakaiAir << "m3" << endl;
        file << setw(25) << left << "Tagihan Air"                 << ": " << tagihanAir << endl;
        file << setw(25) << left << "Biaya Admin"                 << ": " << "Rp3000"<< endl;
        file << setw(25) << left << "Biaya Pajak"                 << ": " << "Rp1195"<< endl;
        file << "-------------------------------------------------------" << endl;
        file << setw(25) << left << "TOTAL TAGIHAN PEMAKAIAN AIR" << ": Rp" << tagihanPakaiAir << endl;
        file << setw(25) << left << "SISTEM PEMBAYARAN"           << ": " <<bayar[metode]<< endl;
        file << setw(25) << left << "CODE PEMBAYARAN"             << ": " <<code<< endl;
        file << "-------------------------------------------------------" << endl;

        file.close(); //menutup file
        cout << "SEDANG MENCETAK TAGIHAN MOHON TUNGGU SEBENTAR...........\n";
        Sleep(5000);
        cout << "\x1b[1A\x1b[2K";
        cout << "\nBERHASIL MENCETAK TAGIHAN KE DALAM FILE  | TAGIHAN_PEMBAYARAN.txt |"; 
    } else {
        cout << "GAGAL MENCETAK TAGIHAN" << endl; //kondisi jika file gagal dibuka
    }
}

int main() {
	srand(time(0)); //refresh random setiap kali program dijalankan
	int pilihan = 2; //rand() % 2 + 1; //menyatakan nilai pilihan secara random

	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"                              ------------------------ SISTEM PEMBAYARAN PAM ----------------------------------                               "<<endl;
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\nSilahkan Login untuk melanjutkan "<<endl;
	cout<<"Username : ..."<<endl;
		Sleep(2000); //Mmenggunakan sistem windows program menunggu selama beberapa detik
		cout << "\x1b[1A\x1b[2K"; //Hapus baris:\x1b[1A -> Naik 1 Baris || \x1b[2K -> Hapus Seluruh Baris
		cout<<"Username :  Zahra Tsabitah"<<endl; //menampilkan baris code setelah baris sebelumnya dihapus menggunakan sistem ANSI
	cout<<"Password : ..."<<endl;
		Sleep(2000);cout << "\x1b[1A\x1b[2K"; 
		cout<<"Password :  4523210145"<<endl;
	cout<<"\nTELAH BERHASIL LOGIN!!!"<<endl;
	//cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	
	cout<<"\nSilahkan Pilih Aktivitas yang dinginkan sesuai dengan menu dibawah ini"<<endl;
	cout<<"1. Lihat Rekap Tahun Lalu"<<endl;
	cout<<"2. Melakukan Pembayaran Bulan Ini "<<endl;
	cout<<"\nMasukan Pilihan : ....."<<endl;
		Sleep(2000);cout << "\x1b[1A\x1b[2K"; 
		cout<<"\nAnda memilih pilihan ke-"<<pilihan<<endl;
		cout<<endl;
	cout<<"MOHON TUNGGU SEBENTAR SEDANG BERALIH......."<<endl;
		Sleep(2000);cout << "\x1b[1A\x1b[2K"; 
	cout<<endl;
	cout<<endl;
    
	//sistem pemilihan aktivitas dengan menampilkan fungsi yang sesuai
    switch (pilihan) { //sesuai dengan inisialisasi nilai random diatas
        case 1:
            lihatRekapTahunLalu(); //memanggil function
            break;
        case 2:
            PembayaranBulanIni();
            break;
        default:
        cout << "Pilihan tidak valid" << endl;
    }
	cin.get();
}