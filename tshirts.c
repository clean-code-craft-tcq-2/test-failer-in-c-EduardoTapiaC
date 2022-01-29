#include <stdio.h>
#include <assert.h>

enum shirtSize {
    tooSmall = 33,
    small = 34,
    medium = 38,
    large = 42,
    xlarge = 46,
    tooLarge = 50,
}shoulderStartSize;

char size(int cms) {
    char sizeName = '\0';
    if(cms <= tooSmall || cms >= tooLarge ) {
        sizeName = 'N';
    } else if(cms >= small && cms < medium) {
        sizeName = 'S';
    } else if(cms >= medium && cms < large) {
        sizeName = 'M';
    } else if(cms >= large && cms < xlarge) {
        sizeName = 'L';
    } else if(cms >= xlarge) {
        sizeName = 'U';
    }
    return sizeName;
}

void testOversizeToFit() {
    assert(size(medium) == 'M');
    assert(size(large) == 'L');
}
void testInvalidSize() {
    assert(size(small) == 'S');
    assert(size(medium) == 'M');
    assert(size(large) == 'L');
    assert(size(xlarge) == 'U');
    assert(size(tooSmall) == 'N');
    assert(size(tooLarge) == 'N');
} 

int main() {
    testOversizeToFit();
    testInvalidSize();
    printf("All is well (maybe!)\n");
    return 0;
}
