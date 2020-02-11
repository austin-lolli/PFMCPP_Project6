/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or const reference types ** WHERE POSSIBLE **
    hint: There is no reference equivalent to nullptr.  
    So don't try to convert nullptr, if nullptr is being returned anywhere
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
