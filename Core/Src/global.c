#include "global.h"

int mode = INIT;
int status = 0;
int state = RED_GREEN_INIT;

int yellowTime;
int greenTime;
int redTime;

int ledModeData;
int ledValueData;

void initValues() {
	yellowTime = YELLOW_TIME;
	greenTime = GREEN_TIME;
	redTime = RED_TIME;
	ledModeData = redTime;
	ledValueData = greenTime;
}
