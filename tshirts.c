#include <stdio.h>
#include <assert.h>

enum shirtSize {
    small = 34,
    medium = 38,
    large = 42,
    xlarge = 46,
}shoulderSize;

#define SIZE_S 34
#define SIZE_M 38
#define SIZE_L 42
#define SIZE_XL 46

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testOversizeToFit() {
    assert(size(small) == "M");
    assert(size(large) == "L");
}
void testUnavailableSize() {
    assert(size(small) != "S");
    assert(size(medium) != "M");
    assert(size(large) != "L");
    assert(size(xlarge) != "XL");
}

int main() {
    assert(size(36) == "S");
    assert(size(40) == "M");
    assert(size(44) == "L");
    assert(size(47) == "XL");
    testOversizeToFit();
    testUnavailableSize();
    printf("All is well (maybe!)\n");
    return 0;
}
