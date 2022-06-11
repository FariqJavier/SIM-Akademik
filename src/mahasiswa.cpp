#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include "include/mahasiswa.hpp"


mahasiswa::mahasiswa(std::string id, std::string nama, int dd, int mm, int yy, 
				std::string nrp, std::string departemen, int tahunmasuk, unsigned long int semesterke, int skslulus)
		: person(id, nama, dd, mm, yy), nrp(nrp), departemen(departemen), tahunmasuk(tahunmasuk), semesterke(semesterke), skslulus(skslulus)
{
	this->ipk = 0.0;
	//this->semesterke = 1;
	//this->skslulus = 0;

	this->ips = std::vector<double> (14,0.0);
}

void mahasiswa::setSemester(int semesterke)
{
	this->semesterke = semesterke;
}

int mahasiswa::getSemester()
{
	return this->semesterke;
}

void mahasiswa::setSKSLulus(int skslulus)
{
	this->skslulus = skslulus;
}

int mahasiswa::getSKSLulus()
{
	return this->skslulus;
}

std::string mahasiswa::getNRP()
{
	return this->nrp;
}

std::string mahasiswa::getDepartemen()
{
	return this->departemen;
}

double mahasiswa::hitungIPK(int semester)
{
        double sum = std::accumulate(ips.begin(),ips.end(),
                                         0.0);
        return this->ipk = sum/(semester-1);
}

void mahasiswa::setIPS(int semester, double ips)
{
	// semester mulai dari 1
	if (semester < 15) {
		this->ips[semester-1] = ips;
	}
}

double  mahasiswa::getIPS(int semester)
{
	if (semester < 15){
		return this->ips[semester-1];
	}else{
                return 0;
        }
}

std::vector<double> mahasiswa::getAllIPS()
{
	return this->ips;
}



