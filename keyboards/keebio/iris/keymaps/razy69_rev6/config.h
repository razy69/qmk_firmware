#pragma once

#define SPLIT_LAYER_STATE_ENABLE // data sync

#define TAPPING_TERM 150

#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#define RGB_MATRIX_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_TRIGGER_ON_KEYDOWN // Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards
