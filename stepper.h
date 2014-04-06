
void initGlobals(); 

int pulsePin(int thePin, int delayMicroSec);

void turnMotorDriverOn();
void turnMotorDriverOff();


void setMountDirection(int theDirection);
void moveMount(float inchesToMove);
void moveMountUp(float inchesToMove);
void moveMountDown(float inchesToMove);


void goHome();

#define DIRECTION_UP 1
#define DIRECTION_DOWN 0

#define STEP_PIN 15
#define DIRECTION_PIN 7
#define MOTOR_DRIVER_ACTIVE_PIN  1
#define LIMIT_SWITCH_MIN_PIN 9

#define MOTOR_DRIVER_ON  1
#define MOTOR_DRIVER_OFF  0



