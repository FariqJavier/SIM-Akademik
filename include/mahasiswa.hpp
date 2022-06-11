#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__


#include <iostream>
#include <string>
#include <vector>
#include "include/person.hpp"

class mahasiswa : public person {
private:
	std::string nrp;
	std::string departemen;
	int tahunmasuk;
	unsigned long int semesterke;
	int skslulus;
	double ipk;
	std::vector<double> ips;

public:
	mahasiswa(std::string id, std::string nama, int dd, int mm, int yy,
					std::string nrp, std::string departemen, int tahunmasuk, unsigned long int semesterke, int skslulus);

	void setSemester(int semesterke);
	int getSemester();

	void setSKSLulus(int skslulus);
	int getSKSLulus();

	std::string getNRP();
	std::string getDepartemen();

	double hitungIPK(int semester);

	void setIPS(int semester, double ips);
	double  getIPS(int semester);
	std::vector<double> getAllIPS();
};

#endif
