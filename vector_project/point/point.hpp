#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <iostream>
#include <type_traits>

#include "../header.hpp"
#include "../braced_exception/braced_exception.hpp"

namespace my_math
{
    USING_STD_
    USING_BR_EXCEPT_

    extern const string NOT_ENOUGH_AXES;
    
    template <class T>
    class point
    {
        
        vector<T> coordinates_;

    public:
        
        point(const vector<T>& data)
            :coordinates_(data)
        {
            static_assert(is_arithmetic_v<T> == true);
        }
        point(const size_t & size, const T & to_fill)
            :point(vector<T>(size, to_fill))
        {}
        point(const size_t & size)
            :point(size, T())
        {}

        point()
            :point(0)
        {}
        bool has_axes(const size_t & s) const;
        
        bool axes_count_equal(const point& other) const;

        const vector<T>& coordinates() const;

        void coordinates(const vector<T>& coordinates);

        const T& get_axis(const int & index) const;

        size_t axes() const;

        const T& x() const;

        const T& y() const;

        const T& z() const;

        const T& w() const;

        point<T> operator+ (const point<T>& other) const;
        point<T> operator- (const point<T>& other) const;

        point<T> operator+(const T& some_value) const;
        point<T> operator-(const T& some_value) const;

        

        point<T>& operator+= (const point<T>& other);
        point<T>& operator-= (const point<T>& other);
        
        point<T>& operator+=(const T& some_value);
        point<T>& operator-=(const T& some_value);

        

        template<class U>
        friend ostream& operator<< (ostream & out, const point<U>& point);
        
    private:

        static void make_axes_count_equal(vector<T>& coords, const point<T>& some_point);
        
        static bool axes_count_equal(const vector<T>& coords, const point<T>& some_point);
        
    };
};

#define USING_MY_MATH_ using namespace my_math;

#include "point.inl"
