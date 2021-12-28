#ifndef INPUT_HPP
#define INPUT_HPP

extern bool INPUT_SETUP_FLAG;

const int INPUT_ARROW_LEFT = 68;
const int INPUT_ARROW_RIGHT = 67;
const int INPUT_ARROW_UP = 65;
const int INPUT_ARROW_DOWN = 66;
const int INPUT_ENTER = 10;

void input_setup();
void input_restore();
int get_key();

#endif // INPUT_HPP
