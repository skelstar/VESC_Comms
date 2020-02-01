/*
    Copyright 2018 Jan Pomikalek <jan.pomikalek@gmail.com>

    This file is part of the DAVEga firmware.

    DAVEga firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DAVEga firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with DAVEga firmware.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef vesc_comms_h
#define vesc_comms_h

#include <Arduino.h>

#define PACKET_MAX_LENGTH 70

typedef enum {
	COMM_FW_VERSION = 0,
	COMM_JUMP_TO_BOOTLOADER,
	COMM_ERASE_NEW_APP,
	COMM_WRITE_NEW_APP_DATA,
	COMM_GET_VALUES,
	COMM_SET_DUTY,
	COMM_SET_CURRENT,
	COMM_SET_CURRENT_BRAKE,
	COMM_SET_RPM,
	COMM_SET_POS,
	COMM_SET_HANDBRAKE,
	COMM_SET_DETECT,
	COMM_SET_SERVO_POS,
	COMM_SET_MCCONF,
	COMM_GET_MCCONF,
	COMM_GET_MCCONF_DEFAULT,
	COMM_SET_APPCONF,
	COMM_GET_APPCONF,
	COMM_GET_APPCONF_DEFAULT,
	COMM_SAMPLE_PRINT,
	COMM_TERMINAL_CMD,
	COMM_PRINT,
	COMM_ROTOR_POSITION,
	COMM_EXPERIMENT_SAMPLE,
	COMM_DETECT_MOTOR_PARAM,
	COMM_DETECT_MOTOR_R_L,
	COMM_DETECT_MOTOR_FLUX_LINKAGE,
	COMM_DETECT_ENCODER,
	COMM_DETECT_HALL_FOC,
	COMM_REBOOT,
	COMM_ALIVE,
	COMM_GET_DECODED_PPM,
	COMM_GET_DECODED_ADC,
	COMM_GET_DECODED_CHUK,
	COMM_FORWARD_CAN,
	COMM_SET_CHUCK_DATA,
	COMM_CUSTOM_APP_DATA,
	COMM_NRF_START_PAIRING
} COMM_PACKET_ID;


class vesc_comms
{
    public:
        typedef enum {
            FAULT_CODE_NONE = 0,
            FAULT_CODE_OVER_VOLTAGE,
            FAULT_CODE_UNDER_VOLTAGE,
            FAULT_CODE_DRV,
            FAULT_CODE_ABS_OVER_CURRENT,
            FAULT_CODE_OVER_TEMP_FET,
            FAULT_CODE_OVER_TEMP_MOTOR
        } fault_code;

        void init(uint32_t baud);
        uint8_t fetch_packet(uint8_t *vesc_packet, uint16_t timeout = 100);
        void setNunchuckValues(int x, int y, bool lowerButton, bool upperButton);
        float get_temp_mosfet(uint8_t *vesc_packet);
        float get_temp_motor(uint8_t *vesc_packet);
        float get_motor_current(uint8_t *vesc_packet);
        float get_battery_current(uint8_t *vesc_packet);
        float get_duty_cycle(uint8_t *vesc_packet);
        int32_t get_rpm(uint8_t *vesc_packet);
        float get_voltage(uint8_t *vesc_packet);
        float get_amphours_discharged(uint8_t *vesc_packet);
        float get_amphours_charged(uint8_t *vesc_packet);
        int32_t get_tachometer(uint8_t *vesc_packet);
        int32_t get_tachometer_abs(uint8_t *vesc_packet);

        void setCurrent(float current);
        void setBrakeCurrent(float brakeCurrent);
        void setRPM(float rpm);

#endif //vesc_comms_h
