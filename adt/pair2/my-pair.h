#ifndef MyPair_Included
#define MyPair_Included
template <typename FirstType, typename SecondType> class MyPair
{
public:
    FirstType getFirst();
    void setFirst(FirstType newValue);
SecondType getSecond();
void setSecond(SecondType newValue);
private:
    FirstType first;
    SecondType second;
};

#define UseMyPairCpp
#include "my-pair.cpp"
#undef  UseMyPairCpp 

#endif
// Import the implementation into the header
