#include "OfficeEmployee.h"
#include "Worker.h"

int main(){
	Employee nv1("2b3", "Nguyen Van A", "123 ntmk Q3");
	
	OfficeEmployee nvvp1;
	OfficeEmployee nvvp2("21127","Nguyen Thi","123 NVC Q5");
	OfficeEmployee nvvp3("211356", "Nguyen Pop", "345 NVC Q6", 11);
	OfficeEmployee nvvp4(nv1);
	OfficeEmployee nvvp5(nvvp3);

	nvvp1.input();

	cout << "======Nhan vien van phong 1======" << endl;
	nvvp1.output();
	cout << "======Nhan vien van phong 2======" << endl;
	nvvp2.output();
	cout << "======Nhan vien van phong 3======" << endl;
	nvvp3.output();
	cout << "======Nhan vien van phong 4======" << endl;
	nvvp4.output();
	cout << "======Nhan vien van phong 5======" << endl;
	nvvp5.output();

	cout << "================================" << endl;
	Worker nvsx1;
	Worker nvsx2("234", "Nguyet Thi", "234 nvc Q5");
	Worker nvsx3("2321", "Nguyen23 Thi", "943 nvc Q5", 40);
	Worker nvsx4(nv1);
	Worker nvsx5(nvsx2);
	
	nvsx1.input();

	cout << "======Cong nhan san suat 1=======" << endl;
	nvsx1.output();
	cout << "======Cong nhan san suat 2=======" << endl;
	nvsx2.output();
	cout << "======Cong nhan san suat 3=======" << endl;
	nvsx3.output();
	cout << "======Cong nhan san suat 4=======" << endl;
	nvsx4.output();
	cout << "======Cong nhan san suat 5=======" << endl;
	nvsx5.output();


	return 0;
}