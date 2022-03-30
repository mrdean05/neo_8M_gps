#include <stdio.h>
#include <string.h>
#include "driver/uart.h"
#include "esp_log.h"

#define TX_PIN 4
#define RX_PIN 5

#define INPUT_BUFF_SIZE 1024


void app_main(void)
{

uart_config_t uart_config= {
    .baud_rate= 9600,
    .data_bits= UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl= UART_HW_FLOWCTRL_DISABLE
};
const int uart_num =  UART_NUM_1;
uart_param_config(uart_num, &uart_config);
uart_set_pin(uart_num, TX_PIN, RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
uart_driver_install (uart_num, INPUT_BUFF_SIZE*2, 0 , 0, NULL, 0);

uint8_t *data = (uint8_t *)malloc (INPUT_BUFF_SIZE);
memset(data, 0, sizeof(INPUT_BUFF_SIZE)); 

while (1){
       //read data from the UART
       int len= uart_read_bytes (uart_num, data, INPUT_BUFF_SIZE, 2000/ portTICK_RATE_MS);
        printf("len = %d, data = %.*s\n",len, len, data);
  
}


}
