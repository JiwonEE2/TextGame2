#pragma once
template<typename T>
class Singleton {
protected:
	Singleton() {}
	~Singleton() {}
public:
	static T& GetInstance() {
		static T inst;
		return inst;
	}
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;
};