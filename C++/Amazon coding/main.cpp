#include <stdlib.h>
#include <stdio.h>

int num_ways(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return num_ways(n-1)+num_ways(n-2);
}


int main() {

}
