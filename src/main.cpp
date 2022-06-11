#include <iostream>
#include <vector>
#include <string>
#include <ios>
#include <limits>
#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

int main()
{
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;

	int menu_terpilih;

	while(1) {
		cout << "Selamat datang di Universitas X" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " orang" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " orang" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " orang" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		cout <<  "----------------------------------------------------------------" << endl << endl;

		switch (menu_terpilih) {
			case 1:
				{
					string id, nama, nrp, departemen;
					int dd, mm, yy, tahunmasuk, skslulus;
					double ips;
					unsigned long int semesterke;
					cout << "Masukkan id: ";
					cin >> id;
					cout << "Masukkan nama: ";
					cin.ignore();
					getline(cin,nama);
					cout << "Masukkan tgl lahir: ";
					cin >> dd;
					cout << "Masukkan bln lahir: ";
					cin >> mm;
					cout << "Masukkan thn lahir: ";
					cin >> yy;
					cout << "Masukkan nrp: ";
					cin >> nrp;
					cout << "Masukkan departemen: ";
					cin.ignore();
					getline(cin,departemen);
					cout << "Masukkan tahun masuk: ";
					cin >> tahunmasuk;
					cout << "Mahasiswa semester: ";
					cin >> semesterke;
					cout << "Jumlah sks lulus: ";
					cin >> skslulus;

					mahasiswa* object1 = new mahasiswa(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk, semesterke, skslulus);
					for(unsigned long int i = 1; i < semesterke; i++){
						cout << "IPS semester " << i << ": ";
						cin >> ips;
						object1 -> setIPS(i, ips);
					}
					recMhs.push_back((*object1));
					cout << endl << endl;
				}
				break;
			case 2:
				{
					string id, nama, npp, departemen;
					int dd, mm, yy, pendidikan;
					cout << "Masukkan id: ";
					cin >> id;
					cout << "Masukkan nama: ";
					cin.ignore();
					getline(cin,nama);
					cout << "Masukkan tgl lahir: ";
					cin >> dd;
					cout << "Masukkan bln lahir: ";
					cin >> mm;
					cout << "Masukkan thn lahir: ";
					cin >> yy;
					cout << "Masukkan npp: ";
					cin >> npp;
					cout << "Masukkan departemen: ";
					cin.ignore();
					getline(cin,departemen);
					cout << "Masukkan pendidikan terakhir: ";
					cin >> pendidikan;

					dosen* object2 = new dosen(id, nama, dd, mm, yy, npp, departemen, pendidikan);
					recDosen.push_back((*object2));
					cout << endl << endl;
				}
				break;
			case 3:
				{
					string id, nama, npp, unit;
					int dd, mm, yy;
					cout << "Masukkan id: ";
					cin >> id;
					cout << "Masukkan nama: ";
					cin.ignore();
					getline(cin,nama);
					cout << "Masukkan tgl lahir: ";
					cin >> dd;
					cout << "Masukkan bln lahir: ";
					cin >> mm;
					cout << "Masukkan thn lahir: ";
					cin >> yy;
					cout << "Masukkan npp: ";
					cin >> npp;
					cout << "Masukkan unit: ";
					cin.ignore();
					getline(cin,unit);

					tendik* object3 = new tendik(id, nama, dd, mm, yy, npp, unit);
					recTendik.push_back((*object3));
					cout << endl << endl;
				}
				break;
			case 4:
				{
					for (unsigned long int i = 0; i < recMhs.size(); i++)
					{
						cout << "Nama: " << recMhs[i].getNama() << endl;
						cout << "Tgl lahir: " << recMhs[i].getTglLahir();
						cout << "/" << recMhs[i].getBulanLahir();
						cout << "/" << recMhs[i].getTahunLahir() << endl;
						cout << "NRP: " << recMhs[i].getNRP() << endl;
						cout << "Departemen: " << recMhs[i].getDepartemen() << endl;
						cout << "Mahasiswa Semester: " << recMhs[i].getSemester() << endl;
						cout << "Jumlah sks lulus: " << recMhs[i].getSKSLulus() << endl;
						for(int j = 1; j < recMhs[i].getSemester(); j++){
							cout << "IPS semester " << j << ':' << ' ' << recMhs[i].getIPS(j) << endl;
						}
						cout << "IPK: " << recMhs[i].hitungIPK(recMhs[i].getSemester()) << endl;
						cout << endl << endl;
					}
				}
				break;
			case 5:
				{
					for (unsigned long int i = 0; i < recDosen.size(); i++)
					{
						cout << "Nama: " << recDosen[i].getNama() << endl;
						cout << "Tgl lahir: " << recDosen[i].getTglLahir();
						cout << "/" << recDosen[i].getBulanLahir();
						cout << "/" << recDosen[i].getTahunLahir() << endl;
						cout << "NRP: " << recDosen[i].getNPP() << endl;
						cout << "Pendidikan Terakhir: S" << recDosen[i].getPendidikan() << endl;
						cout << "Departemen: " << recDosen[i].getDepartemen() << endl << endl;
					}
				}
				break;
			case 6:
				{
					for (unsigned long int i = 0; i < recTendik.size(); i++)
					{
						cout << "Nama: " << recTendik[i].getNama() << endl;
						cout << "Tgl lahir: " << recTendik[i].getTglLahir();
						cout << "/" << recTendik[i].getBulanLahir();
						cout << "/" << recTendik[i].getTahunLahir() << endl;
						cout << "NRP: " << recTendik[i].getNPP() << endl;
						cout << "Unit: " << recTendik[i].getUnit() << endl;
					}
				}
				break;
		}
	}

	return 0;
}

