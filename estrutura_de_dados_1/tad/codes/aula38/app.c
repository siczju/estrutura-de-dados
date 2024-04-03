#include "float_vector.h"

void main(){

    FloatVector *vec = FloatVector_create(10);
    FloatVector_print(vec);

    FloatVector_append(vec, 0.0);
    FloatVector_append(vec, 1.0);
    FloatVector_print(vec);

    FloatVector_destroy(&vec);
    

}