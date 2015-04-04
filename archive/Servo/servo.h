#define DETECTOR_bm (1 << 10)

void Servo_GoTo(unsigned int uiPosition);

enum DetectorStan {ACTIVE, INACTIVE};

void DetectorInit(void);
enum DetectorStan eReadDetector(void);
void Servo_Init(unsigned int uiServoFrequency);
void Automat(void);
