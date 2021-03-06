#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

ColorPair getColorsFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMajorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int getPairNumberFromIndex(int MajorColorIndex, int MinorColorIndex) {
    return MajorColorIndex * 5 + MinorColorIndex + 1;
}

void formatedPrint(int pairNumber, ColorPair colorPair) {
    printf("%-3d | %-8s | %-8s\n",pairNumber, majorColor[colorPair.majorColor], minorColor[colorPair.minorColor]);
}

int printColorMap() {
    ColorPair colorPair;
    int pairNumber;
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            pairNumber = getPairNumberFromIndex(i,j);
            colorPair = getColorsFromPairNumber(pairNumber);
            formatedPrint(pairNumber, colorPair);
        }
    }
    return i * j;
}

void testPairNumberAlignment() {
    assert(getPairNumberFromIndex(WHITE, BLUE) == 1);
    assert(getPairNumberFromIndex(VIOLET, SLATE) == 25);
}

void testColorsFromPairNumber() {
    ColorPair colorPair = {WHITE, BLUE};
    ColorPair colorPairTest = getColorsFromPairNumber(1);
    assert(colorPairTest.majorColor == colorPair.majorColor);
    assert(colorPairTest.minorColor == colorPair.minorColor);

    colorPair = {RED, ORANGE};
    colorPairTest = getColorsFromPairNumber(7);
    assert(colorPairTest.majorColor == colorPair.majorColor);
    assert(colorPairTest.minorColor == colorPair.minorColor);

    colorPair = {BLACK, BROWN};
    colorPairTest = getColorsFromPairNumber(14);
    assert(colorPairTest.majorColor == colorPair.majorColor);
    assert(colorPairTest.minorColor == colorPair.minorColor);

    colorPair = {VIOLET, GREEN};
    colorPairTest = getColorsFromPairNumber(23);
    assert(colorPairTest.majorColor == colorPair.majorColor);
    assert(colorPairTest.minorColor == colorPair.minorColor);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testPairNumberAlignment();
    testColorsFromPairNumber();
    printf("All is well (maybe!)\n");
    return 0;
}