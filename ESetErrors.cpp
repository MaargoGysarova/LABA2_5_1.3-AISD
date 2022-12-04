#include "ESetErrors.h"

void InvalidIndex::print_error() const {
    cout <<"Index out of range"<<endl;
}

void InvalidPoints::print_error() const {
    cout <<"Broken line hasn't this point"<<endl;
}

