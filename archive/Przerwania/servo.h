#define DETECTOR_bm (1 << 10)

enum DetectorStan {ACTIVE, INACTIVE};

void DetectorInit(void);
enum DetectorStan eReadDetector(void);
