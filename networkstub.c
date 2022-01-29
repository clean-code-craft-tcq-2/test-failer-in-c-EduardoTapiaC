#define HEAT_THRESHOLD_CELSIUS 200

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