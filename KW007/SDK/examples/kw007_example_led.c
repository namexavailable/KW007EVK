/**
 * ============================================================
 *  kw007_example_led.c - Minimal KW007 example
 *  Keywave KW007 5.8GHz Doppler Radar Sensor
 *  KW007_SDK_v1.2
 *  Released: 2026-08-24
 *
 *  Copyright 2026 Keywave Technology
 *  SPDX-License-Identifier: Apache-2.0
 *  Licensed under the Apache License, Version 2.0; see LICENSE.
 *
 *  Lights an LED while the sensor reports motion.
 *
 *  What this example needs from you:
 *    1. A HAL for your platform - copy User_platform/kw007_hal_user.c and
 *       fill in its four functions. One of the ready-made HALs may fit as-is.
 *    2. The two LED stubs at the bottom of this file.
 *
 *  HARDWARE REQUIREMENT
 *    The Range1 pin must be tied to GND through a protection resistor
 *    before power-up. Without it the
 *    sensor runs in hardware mode and ignores every register write.
 * ============================================================
 */

#include "KW007_api.h"

/* Provided at the bottom of this file - replace with your own GPIO calls */
static void led_init(void);
static void led_set(bool on);

int main(void)
{
    led_init();

    /* Start-up sequence: reads the factory VCO bank and writes the whole
     * register map. Nothing else will work until this succeeds. */
    if (KW007_Init() != KW007_OK)
    {
        /* Common causes: no I2C reply (wiring, supply, address), or the
         * adapter/driver is missing on a PC-hosted HAL. */
        for (;;) { }
    }

    /* Detection distance. 1 is the shortest, 8 the longest; each range sets
     * the amplifier gains and the threshold together. Pick the smallest one
     * that covers the area - a longer range is also more prone to false
     * triggers. */
    if (KW007_SetDetectionRange(4) != KW007_OK)
    {
        for (;;) { }
    }

    for (;;)
    {
        KW007_Data data = KW007_Read();

        if (!data.ok)
        {
            /* One failed read is not worth acting on; the flags simply keep
             * their previous state until the next poll succeeds. */
            KW007_HAL_DelayMs(128);
            continue;
        }

        /* Either direction counts as motion for this example. data.rssi is
         * also available if the application wants the signal strength. */
        led_set(data.approaching || data.leaving);

        /* The sensor updates its flags at its own rate; polling faster than
         * this returns the same values. */
        KW007_HAL_DelayMs(128);
    }
}

/* ─── LED stubs - replace these two ────────────────────────── */

static void led_init(void)
{
    /* e.g. STM32:  __HAL_RCC_GPIOA_CLK_ENABLE(); HAL_GPIO_Init(...);
     *      Arduino: pinMode(LED_BUILTIN, OUTPUT); */
}

static void led_set(bool on)
{
    (void)on;
    /* e.g. STM32:  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,
     *                  on ? GPIO_PIN_SET : GPIO_PIN_RESET);
     *      Arduino: digitalWrite(LED_BUILTIN, on ? HIGH : LOW); */
}
