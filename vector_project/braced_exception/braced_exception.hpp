#pragma once
#include <format>
#include <stdexcept>
#include <string>
#include <utility>

#include "../header.hpp"


namespace br_except
{
    USING_STD_
    
    class braced_exception: public runtime_error
    {
        
    public:
        braced_exception(const string & error_message = "Something went wrong. ('_,' )")
            : runtime_error(error_message)
        {  }
        template<typename ... P>
        braced_exception(const format_string<P...> &to_format, P&& ... exception_args)
        : braced_exception(format(to_format, std::forward<P>(exception_args)...))               
        {     }
        template<typename ... P>
        braced_exception(const string& to_format,  P&& ... exception_args)
        : braced_exception(vformat(to_format, make_format_args(exception_args...)))               
        {     }
        
    };
    
};

#define USING_BR_EXCEPT_ using namespace br_except;
