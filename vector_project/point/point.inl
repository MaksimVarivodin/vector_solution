#pragma once
#include "point.hpp"

namespace my_math
{
    template <class T>
    const vector<T>& point<T>::coordinates() const
    {
        return this->coordinates_;
    }

    template <class T>
    void point<T>::coordinates(const vector<T>& coordinates)
    {
        this->coordinates_ = coordinates;
    }

    template <class T>
    bool point<T>::has_axes(const size_t& s) const
    {
        return this->coordinates_.size() >= s;
    }

    template <class T>
    bool point<T>::axes_count_equal(const point& other) const
    {
        return coordinates_.size() == other.coordinates_.size();
    }

    template <class T>
    const T& point<T>::get_axis(const int& index) const
    {
        if (has_axes(index + 1))
            return coordinates_[index];
        throw braced_exception(NOT_ENOUGH_AXES, index + 1, coordinates_.size());
    }

    template <class T>
    size_t point<T>::axes() const
    {
        return coordinates_.size();
    }


    template <class T>
    const T& point<T>::x() const
    {
        return get_axis(0);
    }

    template <class T>
    const T& point<T>::y() const
    {
        return get_axis(1);
    }

    template <class T>
    const T& point<T>::z() const
    {
        return get_axis(2);
    }

    template <class T>
    const T& point<T>::w() const
    {
        return get_axis(3);
    }

    template <class T>
    void point<T>::make_axes_count_equal(vector<T>& coords, const point<T>& some_point)
    {
        if (!axes_count_equal(coords, some_point))
        {
            if (coords.size() < some_point.axes())
                coords.resize(some_point.axes());
        }
    }

    template <class T>
    bool point<T>::axes_count_equal(const vector<T>& coords, const point<T>& some_point)
    {
        return coords.size() == some_point.axes();
    }


    template <class T>
    point<T> point<T>::operator+(const point<T>& other) const
    {
        vector<T> temp(coordinates());

        make_axes_count_equal(temp, other);

        for (size_t i = 0; i < other.axes(); ++i)
            temp[i] += other.get_axis(i);

        return point(temp);
    }

    template <class T>
    point<T> point<T>::operator+(const T& some_value) const
    {
        return operator+(point(axes(), some_value));
    }

    template <class T>
    point<T> point<T>::operator-(const T& some_value) const
    {
        return operator-(point(axes(), some_value));
    }


    template <class T>
    point<T> point<T>::operator-(const point<T>& other) const
    {
        vector<T> temp(coordinates());

        make_axes_count_equal(temp, other);

        for (size_t i = 0; i < other.axes(); ++i)
            temp[i] -= other.get_axis(i);
        
        return point(temp);
    }

    template <class T>
    point<T>& point<T>::operator+=(const point<T>& other)
    {
        make_axes_count_equal(this->coordinates_, other);

        for (size_t i = 0; i < other.axes(); ++i)
            this->coordinates_[i] += other.get_axis(i);

        return *this;
    }

    template <class T>
    point<T>& point<T>::operator-=(const point<T>& other)
    {
        make_axes_count_equal(this->coordinates_, other);

        for (size_t i = 0; i < other.axes(); ++i)
            this->coordinates_[i] -= other.get_axis(i);
        
        return *this;
    }

    template <class T>
    point<T>& point<T>::operator+=(const T& some_value)
    {
        return operator+=(point(axes(), some_value));
    }

    template <class T>
    point<T>& point<T>::operator-=(const T& some_value)
    {
        return operator-=(point(axes(), some_value));
    }
    
    template <class U>
    ostream& operator<< (ostream & out, const point<U>& point)
    {
        out << "(";
        for(size_t i =0; i < point.axes()-1; ++i)
            out << point.coordinates()[i] << ";";
        
        out<< point.coordinates()[point.axes()-1]<< ")";
        return out;
    }
    

};
