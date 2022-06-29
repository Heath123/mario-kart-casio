typedef unsigned char bool;

typedef struct {
  bool up;
  bool left;
  bool right;
  bool down;
} ControlState;

typedef struct {
  double x;
  double y;
  double xVelocity;
  double yVelocity;
  double power;
  double reverse;
  double angle;
  double angularVelocity;
  bool isThrottling;
  bool isReversing;
  bool isShooting;
  bool isTurningLeft;
  bool isTurningRight;
} Car;

extern double drag;

void updateWithControls(Car *car, ControlState controls);
