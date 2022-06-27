#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

template<typename T = int>
struct xy_comp {
    T x;
    T y;

    bool operator==(xy_comp<T>& l, xy_comp<T>& r)const {
        return l.x == r.x && l.y == r.y;
    }

    bool operator!=(xy_comp<T>& l, xy_comp<T>& r)const {
        return !(l == r);
    }

    bool operator>(xy_comp<T>& l, xy_comp<T>& r)const {
        return (l.x == r.x) ? (l.y > r.y) : (l.x > l.y);
    }

    bool operator<(xy_comp<T>& l, xy_comp<T>& r)const {
        return !(l > r || l == r);
    }

    bool operator>=(xy_comp<T>& l, xy_comp<T>& r)const {
        return !(l < r);
    }

    bool operator<=(xy_comp<T>& l, xy_comp<T>& r)const {
        return !(l > r);
    }

    xy_comp<T> operator+(xy_comp<T>& l, xy_comp<T>& r)const {
        return {
            l.x + r.x,
            l.y + r.y
        };
    }

    xy_comp<T> operator-(xy_comp<T>& l, xy_comp<T>& r)const {
        return {
            l.x - r.x,
            l.y - r.y
        };
    }

    xy_comp<T> abs() {
        return {
            abs(l.x), abs(l.y)
        };
    }

    double len2(xy_comp<T>& c) {
        auto diff_abs = (this - c).abs();
        return pow(diff_abs.x, 2) + pow(diff_abs.y, 2);
    }

    double len(xy_comp<T> c) {
        return sqrt(len2(c));
    }
}