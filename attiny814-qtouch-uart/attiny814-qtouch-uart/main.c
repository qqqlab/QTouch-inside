#include <atmel_start.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	/* Enable interrupts */
	SREG |= 0x80;

	/* If any of the two self-capacitance buttons is touched, the LED is turned ON
	 * When touch is released, the LED is turned OFF
	 */
	 int j=0;
	while (1) {
		/* Does acquisition and post-processing */
		touch_process();

		j++;
		if(j>50){
		    j=0;
			calibrate_node(0);
			printf("CALIBRATE\n");
		}
		uint8_t v1 = get_sensor_state(0);
		uint16_t v2 = get_sensor_node_signal(0);
		uint16_t v3 = get_sensor_node_reference(0);
		uint16_t v4 = get_sensor_cc_val(0);
		printf("i=%d state=%d sig=%ld ref=%ld cc=%ld\n",j,(int)v1, (long)v2, (long)v3, (long)v4);
		for(volatile long i=0;i<50000;i++);

	}
}
