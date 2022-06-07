#include "FreqMeter.h"

#include "CRT.h"
#include "Object.h"
#include "Platform.h"
#include "XUtils.h"

static const int FreqMeter_attributes[] = {
    FREQ};

static void FreqMeter_updateValues(Meter *this)
{
   float freq = Platform_getFreq();

   xSnprintf(this->txtBuffer, sizeof(this->txtBuffer), "%.1lf GHz", freq);
}

const MeterClass FreqMeter_class = {
    .super = {
        .extends = Class(Meter),
        .delete = Meter_delete},
    .updateValues = FreqMeter_updateValues,
    .defaultMode = TEXT_METERMODE,
    .maxItems = 1,
    .total = 100.0,
    .attributes = FreqMeter_attributes,
    .name = "Freq",
    .uiName = "Freq",
    .caption = "CPU/Frequency: "};
