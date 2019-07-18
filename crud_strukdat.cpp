#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct data_mhs{
	string data_mahasiswa, data_jurusan, data_nim;
	bool curr;
	data_mhs *next;
};


data_mhs* awal = NULL;
data_mhs* akhir = NULL;
data_mhs *hapus;
	
void readData();
void createData(string, string, string);
void updateData(string, string, string, string);
void deleteData(string);
int mainMenu(int);

int main(){
	int pilih;
	string ulang = "y";
	string username = "admin";
	int password = 111111;
	int ulangi_pin=1;
	
	do{
		system("cls");
		cout << "Username : " << endl;
		cin >> username;
		cout << endl;
		cout << "password : " << endl;
		cin >> password;
		
		if(username == "admin" && password == 111111){
			while(ulang == "Y" || ulang == "y") {
				system("cls");
				cout << "1. Create Data Mahasiswa" 	<< endl;
				cout << "2. Update Data Mahasiswa" 	<< endl;
				cout << "3. Delete Data Mahasiswa" 	<< endl;
				cout << "4. Read Data Mahasiswa" 		<< endl;
				cout << "5. Exit Bambang" 	<< endl;
				cout << "Pilih Menu : ";
				cin >> pilih;
				system("cls");
				mainMenu(pilih);
				cout << "Ingin ulangi program : ";
				cin >> ulang;
				system("cls");
			}
		}
	}while(ulangi_pin < 3);
	
	return 0;
}

int mainMenu(int pilihan){	
	string dataBaru_mahasiswa, dataBaru_nim, dataBaru_jurusan;
	string dataLama, dataLama_mahasiswa, dataLama_nim, dataLama_jurusan;
	string hapusData;
	
		switch(pilihan){
			case 1 :
				cout<<"Masukan Data Nama Mahasiswa : ";
				cin>>dataBaru_mahasiswa;
				cout<<"Masukan Data Nim : ";
				cin>>dataBaru_nim;
				cout<<"Masukan Data Jurusan : ";
				cin>>dataBaru_jurusan;
				createData(dataBaru_mahasiswa, dataBaru_nim, dataBaru_jurusan);
			break;
			case 2 :
				readData();
			    cout << "Masukan data yang akan di update : ";
			    cin >> dataLama;
			    cout << "Update Data Nama Mahasiswa : ";
				cin >> dataLama_mahasiswa;
				cout << "Update Data Nim : ";
				cin >> dataLama_nim;
				cout << "Update Data Jurusan : ";
				cin >> dataLama_jurusan;
			    updateData(dataLama, dataLama_mahasiswa, dataLama_nim, dataLama_jurusan);
			break;
			case 3 :
				readData();
				cout << "Masukkan data yang akan dihapus : ";
				cin >> hapusData;
				deleteData(hapusData);
			break;
			case 4 :
				readData();
			break;
			case 5 :
				exit(0);
			break;
			default :
				cout << "Pilihan Tidak Ditemukan";
			break;
		}
}

void readData(){
	int no=1;
	data_mhs *tampil = awal;
	cout << " |======================================================|" << endl;
	cout << " | " << "No" << "\t" << " | " << "\t" << "Nama" << "\t" <<" | " << "\t" << "NIM" << "\t" << "|" << "\t" << "Jurusan" << "\t" << "|" << endl;
	cout << " |======================================================|" << endl;
		while(tampil != NULL) {
			if(tampil->curr) {
				cout << " | " << no++ << "\t";
				cout << " | " << tampil->data_mahasiswa << "\t";
				cout << " | " << tampil->data_nim << "\t";
				cout << "| " << tampil->data_jurusan << "\t\t";
				cout << "| ";
				cout << endl;
			}
			tampil = tampil->next;
		}
	cout << " |======================================================|" << endl;
	system("pause");
	}

void createData(string dataBaru_mahasiswa, string dataBaru_nim, string dataBaru_jurusan){
	data_mhs *tmp = new data_mhs();
	tmp->data_mahasiswa = dataBaru_mahasiswa;
	tmp->data_nim = dataBaru_nim;
	tmp->data_jurusan = dataBaru_jurusan;
	tmp->curr = true;
	tmp->next = NULL;
	if(awal == NULL) {
		awal = tmp;
		akhir = tmp;
	} else {
		akhir->next = tmp;
		akhir = tmp;
	}
	readData();
}

void updateData(string dataLama, string dataLama_mahasiswa, string dataLama_nim, string dataLama_jurusan){
	data_mhs *tmp = awal;
	bool success;
		while(tmp != NULL) {
			if(tmp->curr) {
				if(tmp->data_mahasiswa == dataLama) {
					tmp->data_mahasiswa = dataLama_mahasiswa;
					tmp->data_nim = dataLama_nim;
					tmp->data_jurusan = dataLama_jurusan;
					success = true;
				}
			}
		tmp = tmp->next;
		}
	cout << (success ? "Data berhasil di ubah" : "Data tidak ditemukan") << endl;
}

void deleteData(string deleteData){
	data_mhs *tmp = awal;
	bool success = false;
	while(tmp != NULL) {
    	if(tmp->curr) {
      		if(tmp->data_mahasiswa == deleteData) {
		        tmp->curr = false;
		        success = true;
      		}
    	}
    	tmp = tmp->next;
  	}
	cout << (success ? "Data berhasil di Delete" : "Data tidak ditemukan") << endl;
	readData();
}
