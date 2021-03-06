// Make a simple GBA state machine
// Name: YOUR NAME HERE

#include <stdbool.h>

#include "lib.h"
// These pictures are available as the variables puppy1, puppy2, etc.
// Peep the img/ directory if you're nosy.
#include "img/puppy1.h"
#include "img/puppy2.h"
#include "img/puppy3.h"
#include "img/puppy4.h"
#include "img/puppy5.h"


volatile unsigned short *videoBuffer = (unsigned short *)0x6000000;

// State enum definition
enum GBAState {
    STATE_START,
    STATE_PUPPY1,
    STATE_PUPPY2,
    STATE_PUPPY3,
    STATE_PUPPY4,
    STATE_PUPPY5,
};

// TODO: Draw an image onto the screen using DMA.
//       It's guaranteed that this image will be 240 * 160
//       which is the size of the GBA screen.
//       You MUST use DMA in this!

void drawFullScreenImage(const u16 *img) {
   DMA[3].src = img;
   DMA[3].dst = videoBuffer;
   DMA[3].cnt = DMA_ON | 240 * 160 | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT;

}



int main(void) {
    REG_DISPCNT = MODE3 | BG2_ENABLE;

    enum GBAState state = STATE_START;

    // TODO: Use this somehow in the states below. When you press and
    //       hold A (the z key in the emulator we recommend), it
    //       should NOT cycle through all of the states!
    bool a_down = false;

    while(1) {
        waitForVblank();
        // Get the current state of the buttons for this iteration
        u32 buttons = BUTTONS;
        switch(state) {
        case STATE_START:
            // TODO: Draw puppy1 and go to STATE_PUPPY1
        		drawFullScreenImage(puppy1);
            state = STATE_PUPPY1;
            break;

        case STATE_PUPPY1:
            // TODO: If A is pressed, go to STATE_PUPPY2.
            //
            //       (Hint: If A is down and we've marked it as down, we
            //              should do nothing.
            //              If A is down and it wasn't before, we should
            //              mark it as down, draw the next puppy,
            //              and go to the next state.
            //              If A is not down but we'd marked it as down,
            //              we whould mark it as not down.)
            //
            //       (Hint #2: You can check if A is currently down with
            //                 KEY_DOWN(BUTTON_A, buttons)
        		if (KEY_DOWN(BUTTON_A, buttons) && !a_down) {
        			drawFullScreenImage(puppy2);
        			a_down = true;
        			state = STATE_PUPPY2;
        		}
        		if (a_down && !KEY_DOWN(BUTTON_A, buttons)) {
        			a_down = false;
        		}

            break;

        case STATE_PUPPY2:
            // TODO: If A is pressed, go to STATE_PUPPY3
            //
            //       (Hint: This is a copypaste of STATE_PUPPY1 tbh)
        		if (KEY_DOWN(BUTTON_A, buttons) && !a_down) {
        			drawFullScreenImage(puppy3);
        			a_down = true;
        			state = STATE_PUPPY3;
        		}
        		if (a_down && !KEY_DOWN(BUTTON_A, buttons)) {
        			a_down = false;
        		}
            break;


        case STATE_PUPPY3:
            // TODO: If A is pressed, go to STATE_PUPPY4
        		if (KEY_DOWN(BUTTON_A, buttons) && !a_down) {
        			drawFullScreenImage(puppy4);
        			a_down = true;
        			state = STATE_PUPPY4;
        		}
        		if (a_down && !KEY_DOWN(BUTTON_A, buttons)) {
        			a_down = false;
        		}
            break;

        case STATE_PUPPY4:
            // TODO: If A is pressed, go to STATE_PUPPY5
        		if (KEY_DOWN(BUTTON_A, buttons) && !a_down) {
        			drawFullScreenImage(puppy5);
        			a_down = true;
        			state = STATE_PUPPY5;
        		}
        		if (a_down && !KEY_DOWN(BUTTON_A, buttons)) {
        			a_down = false;
        		}
            break;

        case STATE_PUPPY5:
            // TODO: If A is pressed, go to STATE_PUPPY1
        		if (KEY_DOWN(BUTTON_A, buttons) && !a_down) {
        			drawFullScreenImage(puppy1);
        			a_down = true;
        			state = STATE_PUPPY1;
        		}
        		if (a_down && !KEY_DOWN(BUTTON_A, buttons)) {
        			a_down = false;
        		}
            break;

        }
    }

    return 0;
}


void waitForVblank(void) {
    while(*SCANLINECOUNTER > 160);
    while(*SCANLINECOUNTER < 160);
}