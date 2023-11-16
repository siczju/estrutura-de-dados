#include "float_vector.h"

void main(){

    FloatVector *vec = create(10);

    print(vec);
    append(vec, 0.0);
    append(vec, 1.0);
    append(vec, 2.0);
    print(vec);

    destroy(&vec);
    

}