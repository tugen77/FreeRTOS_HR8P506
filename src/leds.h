#define LED_RED					1
#define LED_GREEN				2
#define LED_YELLOW			3

#define ACT_OFF					0
#define ACT_ON					1
#define ACT_TOGGLE			2

void ledsInit(void);
void ledsAct(unsigned char led, unsigned char act);