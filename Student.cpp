#include <vector>
#include <string>
#include <iostream>

class Student {
public:
	Student(const std::string& name) : _name(name) {
	}

	void Relax() {
		_state += " Relax";
	}

	void Read() {
		_state += " Read";
	}
	
	void Write() {
		_state += " Write";
	}

	std::string GetName() const {
		return _name;
	}

	std::string GetState() const {
		return _state;
	}

	virtual void Study() = 0;

protected:
	const std::string _name;
	std::string _state;
};

class BadStudent : public Student {
public:
	BadStudent(const std::string& name) : Student(name) {
		_state = "bad";
	}
	void Study() override {
		Relax();
		Relax();
		Relax();
		Relax();
		Read();
	}
};

class GoodStudent : public Student {
public:
	GoodStudent(const std::string& name) : Student(name) {
		_state = "good";
	}
	void Study() override {
		Read();
		Write();
		Read();
		Write();
		Read();
	}
};

class Group {
public:
	Group(const std::string& name) : _name(name) {
	}

	void AddStudent(const GoodStudent& student) {
		_goodStudents.push_back(student);
	}
	void AddStudent(const BadStudent& student) {
		_badStudents.push_back(student);
	}
	
	void GetInfo() const {
		std::cout << _name << ": ";
		for (const auto& student : _goodStudents) {
			std::cout << student.GetName() << ' ';
		}
		for (const auto& student : _badStudents) {
			std::cout << student.GetName() << ' ';
		}
		std::cout << std::endl;
	}

	void GetFullInfo() const {
		std::cout << _name << std::endl;
		for (const auto& student : _goodStudents) {
			std::cout << student.GetName() << ": ";
			std::cout << student.GetState() << std::endl;
		}
		for (const auto& student : _badStudents) {
			std::cout << student.GetName() << ": ";
			std::cout << student.GetState() << std::endl;
		}
		std::cout << std::endl;
	}
protected:
	const std::string _name;
	std::vector<GoodStudent> _goodStudents;
	std::vector<BadStudent> _badStudents;
};

int main() {
	Group group("K27");
	BadStudent vasya = BadStudent("Vasya");
	GoodStudent vovochka = GoodStudent("Vovochka");
	GoodStudent yurochka = GoodStudent("Yurochka");
	vasya.Study();
	vovochka.Study();
	yurochka.Study();

	group.AddStudent(vasya);
	group.AddStudent(vovochka);
	group.AddStudent(yurochka);
	group.GetFullInfo();
	group.GetInfo();

	return 0;
}
