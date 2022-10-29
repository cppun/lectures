#include <iostream>

#include "strings/common_string.hpp"

using namespace strings;

int main() {

    char arr[6] = "Array";

    common_string str(arr);

    arr[3] = 'l';

    common_string copy(str);

    common_string assign = copy;

    common_string big_str("Hello world!");

    assign = big_str;


    return 0;
}
