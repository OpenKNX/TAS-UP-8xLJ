#include "HardwareModule.h"

HardwareModule::HardwareModule()
{}

const char *HardwareModule::name()
{
    return "HardwareModule";
}

void HardwareModule::setup()
{
    // BinaryInput
    pinMode(BINARY_INPUT_A_PIN, INPUT);
    pinMode(BINARY_INPUT_B_PIN, INPUT);

    // Setup BE
    for (uint8_t i = 0; i < BI_ChannelCount; i++)
        _binaryInputChannels[i]->setup();

    // Taster
    _taster[0].pin = TASTER_A_PIN;
    _taster[1].pin = TASTER_B_PIN;
    _taster[2].pin = TASTER_C_PIN;
    _taster[3].pin = TASTER_D_PIN;
    _taster[4].pin = TASTER_E_PIN;
    _taster[5].pin = TASTER_F_PIN;
    _taster[6].pin = TASTER_G_PIN;
    _taster[7].pin = TASTER_H_PIN;

    for (uint8_t i = 0; i < 8; i++)
        pinMode(_taster[i].pin, INPUT);
}

void HardwareModule::loop()
{
    processTasterInputs();
    processBinaryInputs();
    for (uint8_t i = 0; i < BI_ChannelCount; i++)
        _binaryInputChannels[i]->loop();

    _lastHardwareQuery = millis();
}

void HardwareModule::processBinaryInputs()
{
    _binaryInputChannels[0]->setHardwareState(digitalRead(BINARY_INPUT_A_PIN) == LOW);
    _binaryInputChannels[1]->setHardwareState(digitalRead(BINARY_INPUT_B_PIN) == LOW);
}

void HardwareModule::processTasterInputs()
{
    bool status = 0;
    for (uint8_t i = 0; i < 8; i++)
    {
        status = (digitalRead(_taster[i].pin) == HIGH);

        if (status != _taster[i].status)
        {
            log("%i: %i", i, status);
            knx.getGroupObject(21 + i).value(status, DPT_Switch);
            _taster[i].status = status;
        }
    }
}
