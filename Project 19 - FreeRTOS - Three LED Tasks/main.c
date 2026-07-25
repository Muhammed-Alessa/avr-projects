/*
 * FreeRTOS - Three LED Tasks
 * Board: Arduino Uno R3
 * MCU: ATmega328P
 * Toolchain: AVR-GCC
 *
 * Bare-metal AVR C. No Arduino framework functions are used.
 * Independently rewritten from the concepts studied in "Simply AVR".
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"

static void task_led1(void *parameters)
{
    (void)parameters;

    for (;;)
    {
        PORTB ^= (1U << PORTB0);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

static void task_led2(void *parameters)
{
    (void)parameters;

    for (;;)
    {
        PORTB ^= (1U << PORTB1);
        vTaskDelay(pdMS_TO_TICKS(300));
    }
}

static void task_led3(void *parameters)
{
    (void)parameters;

    for (;;)
    {
        PORTB ^= (1U << PORTB2);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int main(void)
{
    DDRB |= (1U << DDB0) | (1U << DDB1) | (1U << DDB2);

    xTaskCreate(task_led1, "LED1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(task_led2, "LED2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(task_led3, "LED3", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();

    for (;;)
    {
        // Scheduler should not return.
    }
}
