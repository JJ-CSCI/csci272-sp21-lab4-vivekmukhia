//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include "catch.hpp"
using Catch::Matchers::Equals;
//------------------------------

// Fix the following class
class Complex {

private:
    int a;
    int b;
public:
    Complex(int a=0, int b=0)
    {
        this->a = a;
        this->b = b;
    }

    int re()
    {
        return a;
    }

    int im()
    {
        return b;
    }

    void operator>>(std::string& s) const
    {
        
        s += std::to_string(a);
        
        if (b >= 0)
            s += '+';
        s += std::to_string(b);
        s += 'i';
    }

    void operator<<(const std::string& s)
    {
        int seprator;

        for (int i = s.size() - 1; i >= 0; i--)
        {
           
            if (s[i] == '+' || s[i] == '-')
            {
                seprator = i;
                break;
            }
        }

        this->a = stoi(s.substr(0, seprator));
        this->b = stoi(s.substr(seprator, s.size() - seprator - 1));
    }
};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------
