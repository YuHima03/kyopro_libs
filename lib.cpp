#pragma once
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

#define rep(n, a, b) for (int (n) = (a); (n) < (b); (n)++)
#define rrep(n, a, b) for (int (n) = (a); (a) >= (b); (n)--)
#define all(x) (x).begin(), (x).end()
#define inputvec(v) for (auto& x : v) {std::cin >> x;}

using namespace std;
using ll = long long;

template<typename T = int>
struct xy_comp {
	T x;
	T y;

	bool operator==(const xy_comp<T>& c)const {
		return x == c.x && y == c.y;
	}

	bool operator!=(const xy_comp<T>& c)const {
		return !(this == c);
	}

	bool operator>(const xy_comp<T>& c)const {
		return (x == c.x) ? y > c.y : x > c.x;
	}

	bool operator<(const xy_comp<T>& c)const {
		return !(this > c || this == c);
	}

	bool operator>=(const xy_comp<T>& c)const {
		return !(this < c);
	}

	bool operator<=(const xy_comp<T>& c)const {
		return !(this > c);
	}

	xy_comp<T> operator+(const xy_comp<T>& c)const {
		return {
			x + c.x,
			y + c.y
		};
	}

	xy_comp<T>& operator+=(const xy_comp<T>& c) {
		this = this + c;
		return *this;
	}

	xy_comp<T>& operator++(int) {
		this += 1;
		return *this;
	}

	xy_comp<T> operator-(const xy_comp<T>& c)const {
		return {
			x - c.x,
			y - c.y
		};
	}

	xy_comp<T>& operator-=(const xy_comp<T>& c) {
		this = this - c;
		return *this;
	}

	xy_comp<T>& operator--(int) {
		this -= 1;
		return *this;
	}

	xy_comp<T> operator*(const T v)const {
		return {
			x * v,
			y * v
		};
	}

	xy_comp<T>& operator*=(const T v) {
		this = this * v;
		return *this;
	}

	xy_comp<T> operator/(const T v)const {
		return {
			x / v,
			y / v
		};
	}

	xy_comp<T> operator/=(const T v) {
		this = this / v;
		return *this;
	}

	xy_comp<T> operator%(const T v) const {
		return {
			x % v,
			y % v
		};
	}
 
	xy_comp<T>& operator%=(const T v) {
		this = this % v;
		return *this;
	}

	xy_comp<T> abs()const {
		return {
			abs(x),
			abs(y)
		};
	}

	xy_comp<double> unit_vec()const {
		return this / len();
	}

	xy_comp<T> reduce()const {
		return this / gcd(x, y);
	}

	T inner_product(const xy_comp<T>& c)const {
		return (x * c.x) + (y * c.y);
	}

	double cos_sq(const xy_comp<T>& c)const {
		return pow(inner_product(), 2) / (len_sq() * c.len_sq());
	}

	double cos(const xy_comp<T>& c)const {
		return inner_product() / (len() * c.len());
	}

	double sin_sq(const xy_comp<T>& c)const {
		return 1 - cos_sq();
	}

	double sin(const xy_comp<T>& c)const {
		return pow(sin_sq());
	}

	T area_2(const xy_comp<T>& c)const {
		return abs((x * c.y) - (y - c.x));
	}

	double area(const xy_comp<T>& c)const {
		return area_2() / 2;
	}

	double len_sq(const xy_comp<T>& c)const {
		auto diff_abs = (this - c).abs();
		return pow(diff_abs.x, 2) + pow(diff_abs.y, 2);
	}

	double len(const xy_comp<T> c)const {
		return sqrt(len_sq(c));
	}
};

template<typename T = int, T mod = 1000000007>
struct mod_num {
	T value;

	mod_num(T v) {
		this = v;
	}

	operator T()const {
		return value;
	}

	mod_num<T, mod>& operator=(const T v) {
		value = v % mod;
		return *this;
	}

	bool operator==(const mod_num<T, mod>& v)const {
		return value == v.value;
	}

	bool operator!=(const mod_num<T, mod>& v)const {
		return !(this == v);
	}

	mod_num<T, mod> operator+(const mod_num<T, mod>& v)const {
		return mod_num<T, mod>(value + v.value);
	}

	mod_num<T, mod>& operator+=(const mod_num<T, mod>& v) {
		this = this + v;
		return *this;
	}

	mod_num<T, mod>& operator++(int) {
		value++;
		if (value >= mod) value = 0;
		return *this;
	}

	mod_num<T, mod> operator-(const mod_num<T, mod>& v)const {
		return mod_num<T, mod>(value - v.value);
	}

	mod_num<T, mod>& operator-=(const mod_num<T, mod>& v) {
		this = this - v;
		return *this;
	}

	mod_num<T, mod>& operator--(int) {
		value--;
		if (value < 0) value = mod;
		return *this;
	}

	mod_num<T, mod> operator*(const mod_num<T, mod>& v)const {
		return mod_num<T, mod>(value * v.value);
	}

	mod_num<T, mod>& operator*=(const mod_num<T, mod>& v) {
		this = this * v;
		return *this;
	}

	friend ostream &operator<<(ostream &os, const mod_num<T, mod> &v)const {
		return os << v.value;
	}

	friend istream &operator>>(istream &is, mod_num<T, mod> &x) {
		T t;
		is >> t;
		x = t;
		return (is);
	}

	void pow(T x) {
		value = std::pow(value, x) % mod;
	}
};

template<int mod = 1000000007>
using mod_int = mod_num<int, mod>;

template<ll mod = 1000000007>
using mod_ll = mod_num<ll, mod>;

class union_find {

};