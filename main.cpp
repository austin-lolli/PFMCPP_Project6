/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

 Pointers

 Please look at the screenshot in the files to see what happens if you copy this assignment into Xcode
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    T(int v, const char* w)
    {
        this->value = v;
        this->name = w;
    }   //1
    int value;//2
    std::string name;//3
};

struct X                                //4
{
    T* compare(T* a, T* b) //5
    {   
        if( a != nullptr && b != nullptr )
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float first { 0 }, second { 0 };
    float memberUpdate(float* newVal)      //12
    {
        if( newVal != nullptr )
        {
            std::cout << "U's first value: " << this->first << std::endl;
            this->first = *newVal;
            std::cout << "U's first updated value: " << this->first << std::endl;
            while( std::abs (this->second - this->first) > 0.001f )
            {
                if(this->second > this->first)
                {
                    this->second -= 0.001f;
                }
                else
                {
                    this->second += 0.001f;
                }
            }
            std::cout << "U's second updated value: " << this->second << std::endl;
            return this->second * this->first;
        }
        return 0.0f;
        

    }
};

struct Y
{
    static float updateAndShorten(U* that, float* newVal )        //10
    {
        if( that != nullptr && newVal != nullptr)
        {
            std::cout << "U's first value: " << that->first << std::endl;
            that->first = *newVal;
            std::cout << "U's first updated value: " << that->first << std::endl;
            while( std::abs(that->second - that->first) > 0.001f )
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                if(that->second > that->first)
                {
                    that->second -= 0.001f;
                }
                else
                {
                    that->second += 0.001f;
                }
            }
            std::cout << "U's second updated value: " << that->second << std::endl;
            return that->second * that->first;
        }
        return 0.0f;
    }
};
        
int main()
{
    T pity(6,"Mr T");                                             //6
    T theFool(4,"Son of T");                                             //6
    
    X f;                                            //7
    auto* smaller = f.compare(&pity, &theFool);  
    if( smaller != nullptr )
    {
        std::cout << "The smaller value is " << smaller->name << std::endl; //9
    
    }                        //8
    else
    {
        std::cout << "The compared values are equal" << std::endl;
    }

    U jrT;
    float updatedValue = 5.f;
    std::cout << "[static func] jrT's multiplied values: " << Y::updateAndShorten(&jrT, &updatedValue) << std::endl;                  //11
    
    U babyT;
    std::cout << "[member func] babyT's multiplied values: " << babyT.memberUpdate( &updatedValue ) << std::endl;
}
