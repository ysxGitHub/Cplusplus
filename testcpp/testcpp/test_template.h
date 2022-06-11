#pragma once

template <typename T> class TestTemplate {
public:
	TestTemplate(const T& t) : ele_(t) {}
	T get_ele();

private:
	T ele_;
};

