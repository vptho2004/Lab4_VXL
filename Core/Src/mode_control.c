#include "mode_control.h"

int counter;
int temp;

void modeRun(){
	switch(mode){
	case INIT:
		counter = 2;
		mode = MODE1;
		break;
	case MODE1:
		//MODE 1 -> control 2 traffic system
		switch (state) {
			case RED_GREEN_INIT:
						if(counter == 2){
							segRun2();
							setRed1();
							setGreen2();
							ledModeData--;
							ledValueData--;
							counter = 0;
						} else{
							segRun1();
							setRed1();
							setGreen2();
						}

						counter++;
					if(ledValueData <= 0){
						state = RED_YELLOW;
						ledValueData = yellowTime;
						counter = 2;
					}
					break;
				case RED_YELLOW:
						if(counter == 2){
							segRun2();
							setYellow2();
							ledModeData--;
							ledValueData--;
							counter = 0;
						} else{
							segRun1();
							setYellow2();
						}
						counter++;
					if(ledValueData <= 0) {
						state = GREEN_RED;
						ledModeData = greenTime;
						ledValueData = redTime;
						counter = 2;
					}
					break;
				case GREEN_RED:
						if(counter == 2){
							segRun2();
							setGreen1();
							setRed2();
							ledModeData--;
							ledValueData--;
							counter = 0;
						} else{
							segRun1();
							setGreen1();
							setRed2();
						}
						counter++;
					if(ledModeData <= 0){
						state = YELLOW_RED;
						ledModeData = yellowTime;
						counter = 2;
					}
					break;
				case YELLOW_RED:
						if(counter == 2){
							segRun2();
							setYellow1();
							ledModeData--;
							ledValueData--;
							counter = 0;
						} else{
							segRun1();
							setYellow1();
						}
						counter++;
					if(ledModeData <= 0){
						state = RED_GREEN;
						ledModeData = redTime;
						ledValueData = greenTime;
						counter = 2;
					}
					break;
				case RED_GREEN:
						if(counter == 2){
							segRun2();
							setRed1();
							setGreen2();
							ledModeData--;
							ledValueData--;
							counter = 0;
						} else{
							segRun1();
							setRed1();
							setGreen2();
						}
						counter++;
					if(ledValueData <= 0){
						state = RED_YELLOW;
						ledValueData = yellowTime;
						counter = 2;
					}
					break;
			default:
				break;
			}
		//MODE 2 -> Modify LED RED
		if (isButtonPressed(BUTTON_1_PRESS) == 1) {
			temp = redTime;
			ledModeData = MODE2;
			ledValueData = redTime;
			mode = MODE2;
			offAllLeds();
		}
		break;
	case MODE2:
				blinkingRED();
				if (counter == 2) {
					segRun2();
					counter = 0;
				} else {
					segRun1();
				}
				counter++;
//			}
			//press button 1 -> MODE 3 -> modify YELLOW LED
			if (isButtonPressed(BUTTON_1_PRESS) == 1) {
				temp = yellowTime;
				ledModeData = MODE3;
				ledValueData = yellowTime;
				mode = MODE3;
				offAllLeds();
			}
			//press button 2
			if (isButtonPressed(BUTTON_2_PRESS) == 1) {
				if (temp > 99) {
					temp = 1;
				}
				temp++;
				ledValueData = temp;
			}
			//press button 3
			if (isButtonPressed(BUTTON_3_PRESS) == 1) {
				redTime = temp;
				ledValueData = redTime;
			}
			break;

	case MODE3:
				blinkingYELLOW();
				if (counter == 2) {
					segRun2();
					counter = 0;
				} else {
					segRun1();
				}
				counter++;
			//press button 1 -> MODE 4 -> modify GREEN LED
			if (isButtonPressed(BUTTON_1_PRESS) == 1) {
				temp = greenTime;
				ledModeData = MODE4;
				ledValueData = greenTime;
				mode = MODE4;
				offAllLeds();
			}
			if (isButtonPressed(BUTTON_2_PRESS) == 1) {
				if (temp > 99) {
					temp = 1;
				}
				temp++;
				ledValueData = temp;
			}
			if (isButtonPressed(BUTTON_3_PRESS) == 1) {
				yellowTime = temp;
				ledValueData = yellowTime;
			}
			break;

	case MODE4:
				blinkingGREEN();
				if (counter == 2) {
					segRun2();
					counter = 0;
				} else {
					segRun1();
				}
				counter++;
//			}
			if (isButtonPressed(BUTTON_1_PRESS) == 1) {
				state = RED_GREEN_INIT;
				counter = 2;
				segRun1();
				ledModeData = redTime;
				ledValueData = greenTime;
				mode = MODE1;
				segRun1();
			}
			if (isButtonPressed(BUTTON_2_PRESS) == 1) {
				if (temp > 99) {
					temp = 1;
				}
				temp++;
				ledValueData = temp;
			}
			if (isButtonPressed(BUTTON_3_PRESS) == 1) {
				greenTime = temp;
				ledValueData = greenTime;
			}
			break;
	default:
		break;
	}
}
