#include <stdio.h>
#include <assert.h>

#define HEAT_THRESHOLD_CELSIUS 200

#define USE_STUBS 1

    
#if (USE_STUBS == 1)
    //we could create networkstub.c/h and redirect call to stub
    #define networkAlert(celsius) networkAlertStub(celsius)
#endif
// this would also go into networkstub.c
int networkAlertStub(float celsius) {
    printf("ALERT: Temperature is %.1f celsius.\n", celsius);
    // Return 500 for not-ok
    if(celsius > HEAT_THRESHOLD_CELSIUS) 
    {
        return 500;
    }
    // stub succeeds and returns 200
    return 200;
}

int alertFailureCount = 0;

void alertInCelsius(float farenheit) {
    float celsius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celsius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

void testAlertInCelsius() {
    alertFailureCount = 0;
    alertInCelsius(400.5);
    alertInCelsius(303.6);
    assert(alertFailureCount == 1);
    alertFailureCount = 0;
}

int main() {
    testAlertInCelsius();
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
