#include "include/TDA7439.h"

#define TDA7439_INPUT_SELECT_COMMAND 0x00
#define TDA7439_INPUT_GAIN_COMMAND   0x01
#define TDA7439_VOLUME_COMMAND       0x02
#define TDA7439_BASS_COMMAND         0x03
#define TDA7439_MIDDLE_COMMAND       0x04
#define TDA7439_TREBLE_COMMAND       0x05

#define TDA7439_RIGHT_SPEAKER_ATTENUATION_COMMAND 0x06
#define TDA7439_LEFT_SPEAKER_ATTENUATION_COMMAND  0x07

static I2C_Polling i2c;

static void writeTDA7439(uint8_t command, uint8_t value);

I2CStatus initTDA7439(I2C_TypeDef *I2Cx) {
    i2c = initI2C(I2Cx, I2C_ADDRESSING_MODE_7BIT, TDA7439_TIMEOUT);
    return isDeviceReady(&i2c, TDA7439_I2C_ADDRESS);
}

void setStereoInputTDA7439(TDA7439StereoInput input) {
    writeTDA7439(TDA7439_INPUT_SELECT_COMMAND, input);
}

void setInputGainTDA7439(TDA7439GainValue gain) {
    writeTDA7439(TDA7439_INPUT_GAIN_COMMAND, gain);
}

void setVolumeTDA7439(TDA7439VolumeValue volume) {
    writeTDA7439(TDA7439_VOLUME_COMMAND, volume);
}

void muteTDA7439() {
    writeTDA7439(TDA7439_VOLUME_COMMAND, TDA7439_VOLUME_MUTE);
}

void setBassGainTDA7439(TDA7439BassValue bass) {
    writeTDA7439(TDA7439_BASS_COMMAND, bass);
}

void setMiddleGainTDA7439(TDA7439MidRangeValue midRange) {
    writeTDA7439(TDA7439_MIDDLE_COMMAND, midRange);
}

void setTrebleGainTDA7439(TDA7439TrebleValue treble) {
    writeTDA7439(TDA7439_TREBLE_COMMAND, treble);
}

void setRightSpeakerAttenuationTDA7439(TDA7439SpeakerAttenuationValue attenuation) {
    writeTDA7439(TDA7439_RIGHT_SPEAKER_ATTENUATION_COMMAND, attenuation);
}

void setLeftSpeakerAttenuationTDA7439(TDA7439SpeakerAttenuationValue attenuation) {
    writeTDA7439(TDA7439_LEFT_SPEAKER_ATTENUATION_COMMAND, attenuation);
}

static void writeTDA7439(uint8_t command, uint8_t value) {
    I2CStatus status = startAsMasterI2C(&i2c, TDA7439_I2C_ADDRESS, I2C_WRITE_TO_SLAVE);
    if (status == I2C_OK) {
        transmitByteAsMasterI2C(&i2c, command);
        transmitByteAsMasterI2C(&i2c, value);
    }
    stopAsMasterI2C(&i2c);
}